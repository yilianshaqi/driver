#include <stdio.h>
#include <signal.h>

void sigterm_handler(int signo)
{
    printf("Have caught sig N.O. %d\n", signo);
    return;
}


int main(void)
{
    signal(SIGINT, sigterm_handler);
    signal(SIGTERM, sigterm_handler);
	signal(SIGSTKFLT, sigterm_handler);
	
    while(1);
    return 0;
} 
