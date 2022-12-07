#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>


// https://stackoverflow.com/questions/3736320/executing-shell-script-with-system-returns-256-what-does-that-mean
// https://stackoverflow.com/questions/808541/any-benefit-in-using-wexitstatus-macro-in-c-over-division-by-256-on-exit-statu
int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        printf("Wrong amount of arguments");
        return 0;
    }

    int n = atoi(argv[1]);
    printf("Arg1: %d\n", n);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {

        execlp("./runnable.exe", "./runnable.exe", argv[1], NULL);
        perror("execv");
    }

    int status;
    pid_t wait_result;

    while ((wait_result = wait(&status)) != -1)
    {
        printf("\n\nProcess %lu returned result: %d\n", (unsigned long)wait_result, status / 256);
    }

    int m = (int)status / 256;

    printf("Result = %d\n", m);
    return 0;
}