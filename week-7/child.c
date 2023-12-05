Write a C program to create a child process and allow the parent to display “parent” and the child to display “child” on the screen.

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>  /* contains prototype for wait */
int main(void)
{
int pid;
int status;
printf("Hello World!\n");
pid = fork( );
if(pid==-1) /* check for error in fork */
{
perror("bad fork");
exit(1);
}
if (pid==0)
printf("I am the child process.\n");
else
{
wait(&status); /* parent waits for child to finish */
printf("I am the parent process.\n");
}
}
