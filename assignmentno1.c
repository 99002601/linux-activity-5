
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int fd1,size_buffer;
fd1 =open("Results.csv",O_RDONLY);
if(fd1<0)
{
perror("open");
exit(1);
}
int maxlength=300;
char buffer[maxlength];
size_buffer=read(fd1,buffer,maxlength);
if(size_buffer<0)
{
perror("read");
exit(2);
}
int fd2,size_file;
fd2=open("sample.csv",O_WRONLY|O_CREAT, 0666);
if(fd2<0)
{
perror("open");
exit(3);
}
size_file = write(fd2, buffer, maxlength);
if(size_file<0)
{
perror("write");
exit(4);
}
close(fd1);
close(fd2);
printf("Copy Successful \n");
}
