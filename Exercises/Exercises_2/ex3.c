#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	char* s = malloc(sizeof(argc));
	int i = 0;

	while(i = read(STDIN_FILENO, s, argc) && i < argc)
		i = write(STDOUT_FILENO, s, argc);

	if(i == -1)
		printf("ERRO\n");

	return 0;
}