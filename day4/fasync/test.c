
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define SIZE 64

int fd;
char buf[SIZE] = {0};

void sigterm_handler(int signo)
{
    printf("Have caught sig N.O. %d\n", signo);
	read(fd, buf, 10);
	printf("read: %s\n", buf);	
    return;
}

int main()
{
	int ret;
	
	signal(SIGIO, sigterm_handler);
	
	fd = open("/dev/hello1", O_RDWR | O_NONBLOCK);
	//fd = open("/dev/hello1", O_RDWR );
	if( -1==fd ) {
		perror("open");
		return -1;
	}
	
	printf("open successfully!\n");
	
	fcntl(fd, F_SETOWN, getpid());
	
	fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | FASYNC);
	
	while(1){

	}
	
	close(fd);
	
	return 0;
}

