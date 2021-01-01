#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void mybash(const char* linha){
	int i = 0;
	int status;
	pid_t pid;
	char* exec = strdup(linha);
	char* token;
	char s[2] = " ";
	token = strtok(exec, s);
	char* word[10];

	while(token != NULL){
		word[i] = strdup(token);
		token = strtok(NULL, s);
		i++;
	}

	word[i] = strdup(token);

	pid = fork();

	if(strcmp(word[i-1], "&") == 0){
		if(pid == 0){
			execvp(word[0], word);
			_exit(0);
		}
		else
			wait(&status);

	}

	else{
		if(pid != 0)
			execvp(word[0], word);
	}

}

int main(int argc, char* argv[]){
	
	for(int i = 0; i < argc; i++){
		if(strcmp(argv[i], "exit") != 0)
			mybash(argv[i]);
	}

	return 0;
}