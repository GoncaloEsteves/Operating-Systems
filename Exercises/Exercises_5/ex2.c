#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int res, nLinhas, i, pid, status;
	char buffer;
	char line[1024];

	int ifd = open("/etc/passwd", O_RDONLY);
	int ofd = open("saida.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	int efd = open("erros.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);

	res = dup2(ifd, STDIN_FILENO);
	res = dup2(ofd, STDOUT_FILENO);
	res = dup2(efd, STDERR_FILENO);

	close(ifd);
	close(ofd);
	close(efd);

	i = 0;
	nLinhas = 12;

	pid = fork();

	if(pid == 0){
		while(nLinhas > 0){
			while(read(STDIN_FILENO, &buffer, 1) != 0){
				line[i] = buffer;
				i++;
				if(buffer == '\n')
					break;
			}

			write(STDOUT_FILENO, line, i);
			write(STDERR_FILENO, line, i);

			nLinhas--;
			i = 0;
		}

		perror("reached return");
		_exit(0);
	}

	else{
		wait(&status);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	return 0;
}