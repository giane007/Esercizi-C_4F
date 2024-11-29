#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int p1, p2, p3;

    printf("Io sono il padre A, il mio PID=%d\n", getpid());

    // Primo figlio
    p1 = fork();
    if (p1 == 0) {
        printf("Io sono il figlio B, il mio PID=%d, il mio nome è Qui\n", getpid());
        exit(0); // Termina il figlio B
    } else if (p1 > 0) {
        // Secondo figlio
        p2 = fork();
        if (p2 == 0) {
            printf("Io sono il figlio C, il mio PID=%d, il mio nome è Quo\n", getpid());
            exit(0); // Termina il figlio C
        } else if (p2 > 0) {
            // Terzo figlio
            p3 = fork();
            if (p3 == 0) {
                printf("Io sono il figlio D, il mio PID=%d, il mio nome è Qua\n", getpid());
                exit(0); // Termina il figlio D
            } else if (p3 > 0) {
                
            } else {
                printf("Errore nella creazione del terzo figlio");
                exit(1);
            }
        } else {
            printf("Errore nella creazione del secondo figlio");
            exit(1);
        }
    } else {
        printf("Errore nella creazione del primo figlio");
        exit(1);
    }
    return 0;
}
