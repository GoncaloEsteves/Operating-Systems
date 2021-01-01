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
	int N = 5;

	pi = pipe(fildes);

	if(pi == 0){
		pid = fork();

		if(pid == 0){
			close(fildes[0]);
			sleep(1);
			int i = 0;

			printf("Filho: Vou escrever\n");
			while(i < N){
				res = write(fildes[1], &line, sizeof(line));
				sleep(1);
				i++;
			}
			printf("Filho: escrevi %d vezes %s\n", N, line);

			close(fildes[1]);
			_exit(0);
		}

		else{
			close(fildes[1]);

			while(read(fildes[0], &buf, sizeof(buf)) != 0)
				printf("Pai: li %s do pipe\n", buf);

			close(fildes[0]);
			wait(&status);
		}
	}

	return 0;
}