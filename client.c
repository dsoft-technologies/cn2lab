// VTUCS

/* Using TCP/IP sockets, write a client  server program to make the client
send the file name and to make the server send back the contents of the
requested file if present. */

#include<stdio.h>

#include<sys/stat.h>

#include<sys/types.h>

#include<netinet/in.h>

#include<unistd.h>

#include<fcntl.h>

#include<string.h>

#include<stdlib.h>

char fname[512];

int main(int argc,char *argv[])

{

int cs,n,a;

char buf[1024];

struct sockaddr_in add;

if((cs=socket(AF_INET,SOCK_STREAM,0))>0)

printf("socket created at client\n");

add.sin_family=AF_INET;

add.sin_port=htons(5000);

inet_pton(AF_INET,argv[1],&add.sin_addr);

if((a=connect(cs,(struct sockaddr*)&add,sizeof(add)))==0)

printf("connected to server %s",argv[1]);
printf("\n%d\n",a);

printf("enter the filename you want to send\n");

scanf("%s",fname);

send(cs,fname,512,0);

printf("waiting for the contents\n");


while(n=recv(cs,buf,1023,0))
write(1,buf,n);

printf("aa");

return close(cs);

}


