#include <unistd.h>
#include <fcntl.h>

int main(){
	char s;
	int i = 0;

	while(i = read(STDIN_FILENO, &s, 1))
		i = write(STDOUT_FILENO, &s, 1);

	if(i == -1)
		printf("ERRO\n");

	return 0;
}