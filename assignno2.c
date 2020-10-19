
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int fd,nbytes;
fd=open("Results.csv",O_RDONLY);
if(fd<0)
{
perror("open");
exit(1);
}
int length=135;
char buff[length];
nbytes=read(fd,buff,length);
if(nbytes<0)
{
perror("read");
exit(2);
}
buff[length]='\0';
printf("%s\n",buff);
close(fd);
}
