
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
pid_t ret;
int stat;
int cmd_exec;
Char CLIinp[10];
printf("Enter your command:");
scanf("%s", CLIinp); //read line
ret=fork();
//printf("%s\n",CLIinp);
if(ret<0)
{
perror("fork");
exit(1);
}
if(ret==0)
{
cmd_exec=execlp(CLIinp,CLIinp);
if(cmd_exec<0)
{
perror("execlp");
exit(2);
}
exit(0);
}
else
{
waitpid(-1,&stat,0); //wait(&stat);
printf("parent--child exit stat=%d\n",
WEXITSTATUS(stat));
}
}
