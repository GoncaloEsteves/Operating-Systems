#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	pid_t pid, filho;
	int aux, i, status, perror;

	for(i = 0; i < argc; i++){
		pid = fork();

		if(pid == 0){
			aux = execl(argv[i], "", NULL);
			perror("reached return");
			_exit(i+1);
		}
	}

	while((filho = wait(&status)) > 0);

	return 0;
}
