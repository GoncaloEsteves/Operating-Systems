#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int i, j;
	char* aux;
	char* token;
	const char s[2];
	char* words[10];

	i = 1;

	while(i < argc){

		if(strcmp(argv[i], "-i") == 0){

			int f1 = open(argv[i+1], O_CREAT | O_RDONLY | O_TRUNC, 0666);
			int res = dup2(f1, STDIN_FILENO);
			close(f1);
			i += 2;
		}

		else if(strcmp(argv[i], "-o") == 0){

			int f2 = open(argv[i+1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
			int res = dup2(f2, STDOUT_FILENO);
			close(f2);
			i += 2;
		}

		else{

			j = 0;

			while(i < argc){
				words[j] = strdup(argv[i]);
				j++;
				i++;
			}

			words[j] = NULL;

			return (execvp(words[0], words));
		}

	}

	return 0;
}