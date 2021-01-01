#include <unistd.h>
#include <fcntl.h>

#define SIZE 10*1024*1024

int main(int argc, char* argv[]){
	int i, fd;

	fd = open(argv[0], O_CREAT || O_TRUNC || O_WRONLY, 0777);

	for(i = 0; i < SIZE; i++)
		write(fd, "a", 1);

	close(fd);
	
	return 0;
}