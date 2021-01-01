#include <unistd.h>
#include <fcntl.h>

ssize_t readln (int fildes, void *buf, size_t nbyte){
	int r;
	ssize_t bytesRead = 0;

	while(r = read(fildes, buf+bytesRead, 1) && ((char*)buf)[bytesRead] != '\n')
		bytesRead++;

	if(((char*)buf)[bytesRead] == '\n')
		bytesRead++;

	return bytesRead;
}