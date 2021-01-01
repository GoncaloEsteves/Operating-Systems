#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define RANDOM_MAX 10

int main(){
	int matrix[5][200], num, i, j, status, existe;
	pid_t pid;
	srand(time(NULL));

	for(i = 0; i < 5; i++){
		for(j = 0; j < 200; j++)
			matrix[i][j] = rand() % RANDOM_MAX;
	}

	num = rand() % RANDOM_MAX;
	existe = 0;

	for(i = 0; i < 5; i++){
		pid = fork();

		if(pid == 0){
			for(j = 0; j < 200; j++){
				if(matrix[i][j] == num)
					existe = 1;
			}
			_exit(i);
		}
	}

	while(wait(&status) > 0);

	if(existe == 1)
		printf("O numero %d existe\n", num);

	else
		printf("O numero %d nao existe\n", num);
}