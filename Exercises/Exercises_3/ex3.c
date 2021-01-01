#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	pid_t atual, pai, pid;
	int status;
	int ordem = 1;

	while(ordem <= 10){

		pid = fork();

		if(pid == 0){
			atual = getpid();
			pai = getppid();
			printf("Sou o processo %d e o meu pai é o processo %d. - %dº processo\n", atual, pai, ordem);
			_exit(0);
		}

		else{
			pid_t filho = wait(&status);
			printf("O meu filho é o processo %d.\n", filho);
		}

		ordem++;
	}

	return 0;
}