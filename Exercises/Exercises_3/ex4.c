#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	pid_t filho, pid, atual;
	int status, i;

	for(i = 0; i < 10; i++){
		pid = fork();

		if(pid == 0)
			_exit(i+1);
	}

	while((filho = wait(&status)) > 0){

		if(WIFEXITED(status)){
			atual = getpid();
			status = WEXITSTATUS(status);
			printf("Sou o processo %d, pai do processo nº%d, com o pid %d\n", atual, status, filho);
		}
	}

	return 0;
}