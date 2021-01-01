#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	for(int i = 0; i < argc; i++){
		write(STDOUT_FILENO, argv[i], strlen(argv[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return 0;
}
