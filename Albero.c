#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int p1 = fork();
    int p2, p3, p4, p5;

    if (p1 > 0)
    {
        p2 = fork();
        if (p2 > 0)
        {
            printf("Sono padre2 :%d \n", getpid());
        }
        else if (p2 == 0)
        {
            p4 = fork();
            if (p4 > 0)
            {

                p5 = fork();
                if (p5 > 0)
                {
                    printf("Sono filgio2 :%d \n", getpid());
                }
                else if (p5 == 0)
                {
                    printf("Sono figlio5 :%d \n", getpid());
                }
                else
                {
                    printf("Figlio storto");
                }
            }
            else if (p4 == 0)
            {
                printf("Sono filgio4 :%d \n", getpid());
            }
            else
            {
                printf("Figlio storto");
            }
        }
        else
        {
            printf("Figlio storto");
        }
    }
    else if (p1 == 0)
    {
        p3 = fork();
        if (p3 > 0)
        {
            printf("Sono figlio1 :%d \n", getpid());
        }
        else if (p3 == 0)
        {
            printf("Sono figlio3 :%d \n", getpid());
        }
        else
        {
            printf("Figlio storto");
        }
    }
    else
    {
        printf("Figlio nato storto");
    }

    return 0;
}
