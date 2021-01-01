#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
ssize_t readln (int fildes, void *buf, size_t nbyte){
	int r;
	ssize_t bytesRead = 0;

	while(r = read(fildes, buf+bytesRead, 1) && ((char*)buf)[bytesRead] != '\n')
		bytesRead++;

	if(((char*)buf)[bytesRead] == '\n')
		bytesRead++;

	return bytesRead;
}

void nl1(int nbyte){
	int r, linhas = 0;
	char s[nbyte], aux[3];

	while(r = readln(STDIN_FILENO, s, nbyte)){
		if(r > 1){
			sprintf(aux, "\t%d ", linhas++);
			write(STDOUT_FILENO, aux, 4);
			write(STDOUT_FILENO, s, r);
		}
		if(r == -1)
			printf("ERRO\n");
	}
}

void nl2(int nbyte, char* file){
	int fd = open(file, O_RDONLY, nbyte);
	int r, linhas = 0;
	char s[nbyte], aux[3];

	while(r = readln(fd, s, nbyte)){
		if(r > 1){
			sprintf(aux, "\t%d", linhas++);
			write(STDOUT_FILENO, aux, 4)
		}
		write(STDOUT_FILENO, s, r);
	}
}