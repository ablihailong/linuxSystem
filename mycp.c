#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int args, char *argv[])
{
	char buf[1024];

	int n = 0;
	int fd1 = open(argv[1], O_RDONLY);   //read
	if(fd1 == -1)
	{
		perror("open 1 error");
		exit(1);
	}
	int fd2 = open(argv[2],O_RDWR | O_CREAT | O_TRUNC, 0664);
	
	if(fd2 == -1)
	{
		perror("open 2 error");
		exit(1);
	}
	while(n = read(fd1, buf, 1024) != 0)
	{
		if(n == -1)
		{
			perror("open error");
			exit(1);
		}
		write(fd2, buf, n);

	}




	close(fd1);
	close(fd2);
	return 0;
}
