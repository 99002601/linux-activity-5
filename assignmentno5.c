#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int return,returni;
	ret=fork();
	char *s;
	char *ss;
	s="s.out";

	if(return<0)
	{
		perror("fork");
		exit(1);
	}
	if(return==0)
	{
    	execl("/bin/g++","g++","-c","samp.cpp",NULL) ;
	}
	else
	{
	waitpid(return, &returni, 0);
	execl("/bin/g++","g++","samp.o","-o",s,NULL);
	}
	exit(0);
}
