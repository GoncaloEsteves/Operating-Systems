#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	pid_t atual, pai, pid;
	int status;

	pid = fork();

	if(pid == 0){
		atual = getpid();
		pai = getppid();
		printf("Sou o processo %d e o meu pai é o processo %d.\n", atual, pai);
		if(pai == 1)
			printf("Fiquei orfao :'(\n");
	}

	else{
		pid_t filho = wait(&status);
		atual = getpid();
		pai = getppid();
		printf("Sou o processo %d, o meu pai é o processo %d e o meu filho é o processo %d.\n", atual, pai, filho);
	}

	return 0;
}