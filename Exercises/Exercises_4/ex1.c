#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int aux, perror;
	aux = execl("/bin/ls", "/bin/ls", "-l", NULL);
	perror("reached return");
	return 0;
}
