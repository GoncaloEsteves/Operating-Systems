#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int res;

	int ifd = open("/etc/passwd", O_RDONLY);
	int ofd = open("saida.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	int efd = open("erros.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);

	res = dup2(ifd, STDIN_FILENO);
	res = dup2(ofd, STDOUT_FILENO);
	res = dup2(efd, STDERR_FILENO);

	close(ifd);
	close(ofd);
	close(efd);

	res = execlp("wc", "/bin/wc", NULL);

	return 0;
}