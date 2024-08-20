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
        bzero(buff,MAX);
        read(connfd,buff,sizeof(buff));
        printf("from client:%s\t to client:",buff);
        bzero(buff,MAX);
        n=0;
        while(buff[n++]=getchar()!='\n');
        write(connfd,buff,sizeof(buff));
        if(strcmp("exit",buff,4)==0)
        {
            printf("exit server....\n");
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

    if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
    {
        printf("bind failed...\n");
        exit(1);
    }
    else
    {
        printf("bind success...!");
    }

    if(listen(sockfd,5)==0)
    {
        printf("listen failed...\n");
        exit(1);
    }
    else
    {
        printf("server listening...");
    }

    len=sizeof(cli);
    connfd=accept(sockfd,(SA*)&cli,sizeof(cli));
    if(connfd<0)
    {
        printf("Accept failure...\n");
        exit(1);
    }
    else
    {
        printf("Connection accepted....\n");
    }
    func(connfd);
    close(sockfd);
}