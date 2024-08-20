#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int connfd)
{
    char buff[MAX];
    int n;
    for(;;)
    {
        printf("enter the string:");
        n=0;
        while(buff[n++]=getchar()!='\n');
        write(sockfd,buff,sizeof(buff));
        bzero(buff,sizeof(buff));
        if(strcmp("exit",buff,4)==0)
        {
            printf("exit client....\n");
            break;
        }
    }
}
void main()
{
    int sockfd,connfd,len;
    struct sockaddr_in servaddr,cli;

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1)
    {
        printf("socket creation failed...\n");
        exit(1);
    }
    else
    {
        printf("socket created..");
    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(PORT);

    if((connect(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
    {
        printf("connection with server failed...\n");
        exit(1);
    }
    else
    {
        printf("connection success...!\n");
    }

    func(connfd);
    close(sockfd);
}