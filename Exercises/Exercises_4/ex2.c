#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int aux, perror;
	int status;
	pid_t pid;

	pid = fork();

	if(pid == 0){
		aux = execl("/bin/ls", "/bin/ls", "-l", NULL);
		perror("reached return");
		_exit(0);
	}
	else{
		wait(&status);
	}

	return 0;
}
