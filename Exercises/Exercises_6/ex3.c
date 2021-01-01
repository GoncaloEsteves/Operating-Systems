#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

#define BUFFER 1024

int main(){
	int fildes[2];
	pid_t pid;
	int pi, q, r, status;
	char buf[BUFFER];
	char ler[BUFFER];

	pi = pipe(fildes);

	if(pi == 0){
		pid = fork();

		if(pid == 0){
			printf("Filho: entrei\n");
			close(fildes[1]);
			dup2(fildes[0], STDIN_FILENO);
			close(fildes[0]);

			while((q = read(STDIN_FILENO, &ler, sizeof(ler))) != 0)
				execlp("wc", ler, NULL);
			close(STDIN_FILENO);
			_exit(0);
		}

		else{
			printf("Pai: entrei\n");
			close(fildes[0]);

			printf("Pai: Vou comecar a ler\n");
			while((q = read(STDIN_FILENO, &buf, sizeof(buf))) != 0){
				write(fildes[1], buf, q);
				sleep(1);
			}
			printf("Pai: terminei a leitura\n");
			

			close(fildes[1]);
			wait(&status);
		}
	}

	return 0;
}