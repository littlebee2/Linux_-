#include "can.h"

#define     CAN_ZERO    "can0"
#define     debug_print     printf

volatile can_buf_struct  can0_rx_buf;
volatile can_buf_struct  can0_tx_buf;

static  pthread_mutex_t can0_lock;
static pthread_t thread_read_id = 0;
static pthread_t thread_write_id =0;
static int sockfd=-1;

static void *can0_send(void *v);
static void *can0_recive(void *v);
static void pthread_quit_slot(int sig);

int can0_tx(struct can_frame *frame)
{
    int ret=0;
    memcpy(&can0_tx_buf.frame_buf[can0_tx_buf.in],frame,sizeof(struct can_frame));
    can0_tx_buf.in++;
    if(can0_tx_buf.in >=CAN_FRAME_BUFFER_SIZE)
    {
        can0_tx_buf.in = 0;
    }
    if(can0_tx_buf.in == can0_tx_buf.out)
    {
        debug_print("can0_tx_buf fill\r\n");
    }
    return 0;
}

int can0_rx(struct can_frame *frame)
{
    if(can0_rx_buf.in == can0_rx_buf.out)
    {
        return -1;
    }
    else
    {
        memcpy(frame,&can0_rx_buf.frame_buf[can0_rx_buf.out],sizeof(struct can_frame));
        can0_rx_buf.out++;
        if(can0_rx_buf.out >= CAN_FRAME_BUFFER_SIZE)
        {
            can0_rx_buf.out = 0;
        }
    }
}

//退出时，摧毁线程
static void can_rx_tx_release(int sig)
{
    (void)sig;
    if(thread_read_id > 0)
        pthread_kill(thread_read_id,SIGQUIT);
    if(thread_write_id > 0)
        pthread_kill(thread_write_id,SIGQUIT);
    if(thread_read_id)
        pthread_join(thread_read_id,NULL);
    if(thread_write_id)
        pthread_join(thread_write_id,NULL);
}
//初始化can
int can_rx_tx_init(void)
{
    struct ifreq ifr = {0};//用来配置ip地址，激活接口
    struct sockaddr_can can_addr = {0};

    int ret;

    can0_rx_buf.in = 0;
    can0_rx_buf.out =0;
    can0_tx_buf.in=0;
    can0_tx_buf.out=0;
    debug_print("创建CAN互斥锁\r\n");
    pthread_mutex_init(&can0_lock,NULL);//创建互斥锁
    debug_print("创建套接字\r\n");
    /*打开套接字*/
    sockfd = socket(PF_CAN,SOCK_RAW,CAN_RAW);
    if(0 > sockfd)
    {
        perror("socket error");
        debug_print("socket error");
        exit(-1);
    }
    debug_print("创建套接字成功\r\n");
    /*制定can0设定*/
    strcpy(ifr.ifr_name,CAN_ZERO);
    ioctl(sockfd,SIOCGIFINDEX,&ifr);
    can_addr.can_family = AF_CAN;
    can_addr.can_ifindex= 0;
    debug_print("绑定套接字\r\n");
    /*将can0与套接字绑定*/
    ret = bind(sockfd,(struct sockaddr *)&can_addr,sizeof(can_addr));
    if(0 > ret)
    {
        perror("bind error");
        debug_print("bind error");
        close(sockfd);
        exit(-1);
    }
    debug_print("绑定套接字成功\r\n");
    debug_print("创建can接受线程\r\n");
    ret = pthread_create(&thread_read_id,NULL,can0_recive,&sockfd);
    if(0 > ret)
    {
        debug_print("read pthread_cread fail\r\n");
    }
    debug_print("创建can接受线程成功\r\n");
    debug_print("创建cang发送线程\r\n");
    ret = pthread_create(&thread_write_id,NULL,can0_send,&sockfd);
    if(ret > 0)
    {
        debug_print("write pthread_create fail\r\n");
    }
    debug_print("创建can发送线程成功\r\n");
    signal(SIGQUIT,can_rx_tx_release);
    return 0;
}

/*发送线程*/
static void *can0_send(void *v)
{
    int *p = v;
    int sockfd = *p;
    int ret = 0;

    struct can_frame *frame;
    signal(SIGQUIT,pthread_quit_slot);
    while(1)
    {
        //debug_print("%s,%d\r\n"__FUNCTION__,__LINE__);
        if(can0_tx_buf.in == can0_tx_buf.out)
        {

        }
        else
        {
            debug_print("%s,%d\r\n",__FUNCTION__,__LINE__);
            frame = &can0_tx_buf.frame_buf[can0_tx_buf.out];
            can0_tx_buf.out++;
            if(can0_tx_buf.out >= CAN_FRAME_BUFFER_SIZE)
            {
                can0_tx_buf.out = 0;
            }
            pthread_mutex_lock(&can0_lock);
            ret = write(sockfd,frame,sizeof(struct can_frame));
            pthread_mutex_unlock(&can0_lock);
            if(ret != sizeof(struct can_frame))
            {
                debug_print("send can frame error\r\n");
            }
        }
        usleep(0);
    }
    return NULL;
}

/*接受线程*/
static void * can0_recive(void *v)
{
    int *p = v;
    int sockfd = *p;
    int ret = 0;
    struct can_frame frame;
    signal(SIGQUIT,pthread_quit_slot);
    while(1)
    {
        pthread_mutex_lock(&can0_lock);
        ret = read(sockfd,&frame,sizeof(struct can_frame));
        pthread_mutex_unlock(&can0_lock);

        if(0 > ret)
        {
            debug_print("read can frame error %s,%d",__FUNCTION__,__LINE__);
        }
        else
        {
            debug_print("%s,%d\r\n",__FUNCTION__,__LINE__);
            memcpy(&can0_rx_buf.frame_buf[can0_rx_buf.in],&frame,sizeof(struct can_frame));
            can0_rx_buf.in++;
            if(can0_rx_buf.in >= CAN_FRAME_BUFFER_SIZE)
            {
                can0_rx_buf.in = 0;
            }
            if(can0_rx_buf.in ==  can0_rx_buf.out)
            {
                debug_print("can0_rx_buf fill\r\n");
            }
        }
        usleep(0);
    }
}

static void pthread_quit_slot(int sig)
{
    (void)sig;
    pthread_exit(0);
}

/*打印can_frame 帧数据内容*/
void print_can_frame(struct can_frame *frame)
{
    int i=0;
    /*校验码模式*/
    if(frame->can_id & CAN_EFF_FLAG)//扩展帧
    {
        printf("扩展帧 <0x%08x>",frame->can_id&CAN_EFF_MASK);
    }
    else
    {
        printf("扩展帧 <0x%03x>",frame->can_id&CAN_SFF_MASK);
    }
    /*校验帧类型：数据帧还是远程帧*/
    if(frame->can_id & CAN_RTR_FLAG)
    {
        debug_print("remot request\n");
    }

    /*打印长度*/
    printf("[%d] ",frame->can_dlc);
    /*打印数据*/
    for(i=0; i<frame->can_dlc; i++)
    {
        printf("%02x ",frame->data[i]);
    }
    printf("\n");
}