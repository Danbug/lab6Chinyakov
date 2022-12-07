#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*

    Задание №2
    Создать один процесс — потомок. 
    Продемонстрировать «непредсказуемость» алгоритма переключения процессов. 
    С помощью функции time() (получение количества секунд, прошедших с начала эры UNIX, 
    заголовочный файл time.h, вызов: time_t now = time(NULL);) 
    заставить проработать программу заданное количество секунд 
    (2, 3, 5, … можно указать с помощью макроопределения) и просчитать, 
    сколько раз в каждом процессе выполнится тело цикла — увеличения счетчика.
*/

#define WORK_TIME 2

int main(int argc, char const *argv[])
{
    fork();
    int counter = 0;
    time_t time_start = time(NULL);
    while( (time(NULL) - time_start) <= WORK_TIME ){
        counter++;
    }
    printf("%d\n",counter);
    return 0;
}
