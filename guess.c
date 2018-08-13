#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int g_min = 0;
int g_max = 1024;
int guess;

void handler(int code) {
    if (code == SIGUSR1) { // hi
        if (guess < g_max) {
            g_max = guess;
        }
    } else if (code == SIGUSR2) { // lo
        if (guess > g_min) {
            g_min = guess + 1;
        }
    } else if (code == SIGINT) { // correct
        printf("The correct number is %d! YEAH!\n", guess);
        exit(0);
    } else {
        return;
    }
    guess = random() % (g_max - g_min) + g_min;
    printf("[PARENT] guess %d\n", guess);
}

int main(int argc, char **argv) {
    pid_t r = fork();
    if (r > 0) { // parent
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        signal(SIGINT, handler);
        signal(SIGCONT, handler);
        pause();

        guess = random() % 1024;
        printf("[PARENT] guess %d\n", guess);

        while (1) {
            kill(r, SIGCONT);
            pause();
        }

    } else if (r == 0) { // child
        signal(SIGCONT, handler);
        int n;
        do {
            printf("Please enter a secret number between 0 and 1023:\n");
            scanf("%d", &n);
        } while (!(n >= 0 && n <= 1023));

        kill(getppid(), SIGCONT);

        char input[8];
        while (1) {
            pause();
            printf("Judge: ");
            scanf("%s", input);
            if (strcmp("hi", input) == 0) {
                kill(getppid(), SIGUSR1);
                fprintf(stderr, "%d # SIGUSR1 # %d\n", getpid(), getppid());
            } else if (strcmp("lo", input) == 0) {
                kill(getppid(), SIGUSR2);
                fprintf(stderr, "%d # SIGUSR2 # %d\n", getpid(), getppid());
            } else if (strcmp("correct", input) == 0) {
                kill(getppid(), SIGINT);
                fprintf(stderr, "%d # SIGINT # %d\n", getpid(), getppid());
                exit(0);
            } else {
                fprintf(stderr, "Invaild input\n");
            }
        }

    } else { // error
        perror("fork");
        exit(-1);
    }

}
