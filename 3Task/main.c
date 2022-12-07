#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

/*
    Задание №3 A
    
    В программе функция fork может быть вызвана более одного раза. 
    Ее можно вызывать как из родительского потока, так и из потоков — потомков. 
    Родительский процесс содержит локальную переменную. Напишите программу, 
    которая создает два под­процесса, а каждый из них, в свою очередь, свои два под­процесса. 
    После каждого вызова fork в новом процессе увеличить значение локальной переменной, 
    вывести на экран с помощью функции printf значение этой локальной переменной, 
    ее адрес и идентификаторы родительского и дочернего процессов. 
    Кроме того, каждый родительский процесс должен вывести идентификаторы своих дочерних процессов. 
    Обратить внимание на очередность создания процессов при каждом запуске программы.

    https://stackoverflow.com/questions/6542491/how-to-create-two-processes-from-a-single-parent
*/


int main(int argc, char const *argv[])
{
    pid_t c1_pid, c2_pid,c3_pid,c4_pid;
    int forkCounter = 0;
    printf("Пока всего один процесс\n"); 
    printf("Вызов функции fork...\n");
    c1_pid = fork();
    forkCounter++;
    if(c1_pid != 0){
        c2_pid = fork();
        forkCounter++;
    }
    // (c1_pid = fork()) && (); // Creates two children
    // forkCounter++;
    // forkCounter++;

    printf("\n================================\n");
    printf("Start print\n");
    printf("\n================================\n");
    printf("Fork counter = %d, adress = %p\n", forkCounter, &forkCounter);
    printf("c1 = %d,c2 = %d,c3 = %d,c4 = %d\n",c1_pid,c2_pid,c3_pid,c4_pid);
    printf("pid :%d\nppid:%d\n",getpid(),getppid());
    
    if (c1_pid == 0) {
        printf("\n================================\n");
        printf("c1 print\n");
        printf("\n================================\n");
        c3_pid = fork();
        forkCounter++;
        if(c3_pid != 0){
            c4_pid = fork();
            forkCounter++;
        }
        // (c3_pid = fork()) && (c4_pid = fork()); // Childer 1 creates two children
        // forkCounter++;
        // forkCounter++;
    } else if (c2_pid == 0) {
        printf("\n================================\n");
        printf("c2 print\n");
        printf("\n================================\n");
        c3_pid = fork();
        forkCounter++;
        if(c3_pid != 0){
            c4_pid = fork();
            forkCounter++;
        }

        // (c3_pid = fork()) && (c4_pid = fork()); // Childer 2 creates two children
        // forkCounter++;
        // forkCounter++;
    } else {
        printf("\n================================\n");
        printf("Paren print\n");
        printf("\n================================\n");
    }


    printf("\n================================\n");
    printf("End print\n");
    printf("\n================================\n");
    printf("Fork counter = %d, adress = %p\n", forkCounter, &forkCounter);
    printf("c1 = %d,c2 = %d,c3 = %d,c4 = %d\n",c1_pid,c2_pid,c3_pid,c4_pid);
    printf("pid :%d\nppid:%d\n",getpid(),getppid());

    return 0;
}
