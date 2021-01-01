#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int pi, status, aux;
	int wc = 0;
	int fildes[2];
	pid_t pid;

	pi = pipe(fildes);

	if(pi == 0){

		pid = fork();

		if(pid == 0){
			close(fildes[1]);
			dup2(fildes[0], STDIN_FILENO);
			close(fildes[0]);
			aux = open("OutEx4.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(aux, STDOUT_FILENO);
			execl("wc", "wc", "-l", NULL);
			_exit(0);
		}

		else{
			close(fildes[0]);
			dup2(fildes[1], STDOUT_FILENO);
			close(fildes[1]);
			execl("/bin/ls", "ls", "/etc", NULL);
			wait(&status);
		}
	}

	return 0;
}