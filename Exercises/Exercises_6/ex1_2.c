#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	int fildes[2];
	pid_t pid;
	int pi, res, status;
	char buf[20];
	char line[] = "Olá Mundo!";

	pi = pipe(fildes);

	if(pi == 0){
		pid = fork();

		if(pid != 0){
			close(fildes[0]);
			sleep(5);
			printf("Pai: Vou escrever\n");
			res = write(fildes[1], &line, sizeof(line));
			printf("Pai: escrevi %s no pipe\n", line);
			close(fildes[1]);
			_exit(0);
		}

		else{
			close(fildes[1]);
			res = read(fildes[0], &buf, sizeof(buf));
			printf("Filho: li %s do pipe\n", buf);
			close(fildes[0]);
			wait(&status);
		}
	}

	return 0;
}