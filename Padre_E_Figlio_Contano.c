#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid; // Dichiarazione di un intero per il PID

    // Creazione del figlio
    pid = fork();

    if (pid > 0) {
         // Codice eseguito dal padre
        printf("Sono il Padre: PID = %d \n", getpid(), pid);
        for (int i = 0; i <= 19; i++) {
            printf("Padre (PID=%d): %d \n", getpid(), i);
        }    
    } else if (pid == 0) {
        // Codice eseguito dal figlio
        printf("Sono il Figlio: PID = %d \n", getpid(), getppid());
        for (int i = 0; i <= 9; i++) {
            printf("Figlio (PID=%d): %d \n", getpid(), i);
           
        }
    } else {
        // Errore durante la creazione del figlio
        perror("Errore durante la creazione del processo figlio");
        exit(1);
       
    }

    return 0;
}
//La conta del padre potrebbe avvenire nello stesso tempo di quella del figlio
