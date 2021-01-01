#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	pid_t filho, atual, pai, pid;
	int status, i;

	for(i = 0; i < 10; i++){

		pid = fork();

		if(pid !=0){
			waitpid(pid, &status, 0);

			if(WIFEXITED(status)){
				atual = getpid();
				pai = getppid();
				printf("Sou o processo %d e o meu pai é %d\n", atual, pai);
			}
			break;
		}
	}

	return 0;
}