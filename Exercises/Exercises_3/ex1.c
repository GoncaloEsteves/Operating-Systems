#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	pid_t atual, pai;

	atual = getpid();
	pai = getppid();

	printf("Sou o processo %d e o meu pai é o processo %d.\n", atual, pai);

	return 0;
}