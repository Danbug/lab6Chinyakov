// A C program to demonstrate Zombie Process.
// Child becomes Zombie as parent is sleeping
// when child process exits.
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// Fork returns process id
	// in parent process
	pid_t child_pid = fork();

	// Parent process
	if (child_pid > 0){
        printf("Before sleep\n\n\n");
        system("ps -l");
        sleep(10);
        printf("After wait\n\n\n");
        wait();
        system("ps -l");
    }

	// Child process
	else		
		exit(0);

	return 0;
}
