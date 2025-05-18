#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
        wait(NULL);  // Wait for child to terminate (avoids zombie)
        printf("Parent ends.\n");
    } else if (pid == 0) {
        // Child process
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());

        // Uncomment for Zombie demonstration
        // exit(0);  // Child terminates quickly, parent sleeps

        // Uncomment for Orphan demonstration
        sleep(5);  // Sleep to allow parent to terminate first
        printf("Child (Orphan) New Parent: %d\n", getppid());

        char *args[] = {"/bin/ls", "-l", NULL};  // execve example
        execve(args[0], args, NULL);  // Replaces child with ls
        perror("execve failed");
    } else {
        perror("fork failed");
    }

    return 0;
}
