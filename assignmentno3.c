
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int* fd;
int nbytes;
char c;
int word=0;
int char=0;
int line=0;
fd=fopen("Result.csv",O_RDONLY);
if(fd<0)
{
perror("open");
exit(1);
}
for (c = getc(fd); c != EOF; c = getc(fd)) 
{
char++;
if (c == '\n') // Increment count if this character is newline 
line++;
if (c == ' ' | c == ',')
word++;
}
printf("cc = %d,wc = %d,lc = %d",char,word,line); 
}
