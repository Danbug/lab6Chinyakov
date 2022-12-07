#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    Задание №1
    Написать функцию, которая выводит в стандартный поток вывода информацию о процессе. 
    Дополнительное задание: предусмотреть аргумент, с помощью которого можно управлять той информацией, 
    что выводится в стандартный поток вывода.
*/

int main(int argc, char const *argv[])
{
    if(argc == 1){
        printf("PID = %d\n",getpid());
        printf("PPID = %d\n",getppid());
        printf("PGRP = %d\n",getpgrp());
        printf("UID = %d\n",getuid());
        printf("EUID = %d\n",geteuid());
        printf("GID = %d\n",getgid());
        printf("EGID = %d\n",getegid());
    }
    printf("Hello world!\n");
    return 0;
}
