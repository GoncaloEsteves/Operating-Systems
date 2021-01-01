#include <signal.h>
#include <sys/types.h>
typedef void (*sighandler_t) (int);

int next_process_index(){
	int next = -1;

	for(int i = current +1; i)
}

void change_running_processes(int signum){
	int next = next_process_index();

	if(current < 0){
		kill(pids[next], SIGCONT)
	}

	else if(remaining_processes)

	current = next;
	alarm(1);
}

int main(int arc, char* args[]){

	int commands = argc -1;



	int remaining_processes = 0;

	for(int i = 1; i < argc; i++){
		int pid;
		if((pid = fork()) == 0){
			pause();
			printf("starting process %s\n", argv[i]);
			execl()
		}

		else{
			pids[i-1] = pid;
			remaining_processes++;
		}
	}

	signal(SIGALRM, change_running_processes)



	return 0;
}