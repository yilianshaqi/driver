
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 64

int main()
{
	int fd;
	int ret;
	char buf[SIZE] = {0};
	pid_t pid;
	
	//fd = open("/dev/hello1", O_RDWR | O_NONBLOCK);
	fd = open("/dev/hello1", O_RDWR );
	if( -1==fd ) {
		perror("open");
		return -1;
	}
	
	printf("open successfully!\n");
	
	read(fd, buf, 10);
	
	printf("read: %s\n", buf);
	
	close(fd);
	
	return 0;
}

