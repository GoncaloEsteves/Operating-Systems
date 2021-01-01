#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10

int mysistem(const char* command){
	int i = 0;
	char* exec = strdup(command);
	char* token;
	const char s[2] = " ";
	token = strtok(exec, s);
	char* words[BUFFER];


	while(token != NULL){
		words[i] = strdup(token);
		token = strtok(NULL, s);
		i++;
	}

	words[i] = NULL;

	return (execvp(words[0], words));
}

int main(int argc, char* argv[]){
	char* aux = malloc(sizeof(char*));
	int i;

	for(i = 1; i < argc; i++){
		aux = strcat(aux, argv[i]);
		aux = strcat(aux, " ");
	}

	return (mysistem(aux));
}
