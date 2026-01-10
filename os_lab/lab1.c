#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t child_pid;
    int status;
    
    child_pid = fork();

    if (child_pid < 0){
        perror("process failed\n");
        exit(1);
    }
    else if(child_pid == 0){
        printf("child (id:%d) is running...\n", getpid());
        // If this succeeds, the process "becomes" ls
        execlp("/bin/ls", "ls", NULL);

        // This line only prints if the command above fails
        perror("execlp failed"); 
        exit(1);
    }
    else{
        printf("parent process(pid:%d) is created child %d \n", getpid(), child_pid);
        wait(&status); // Wait for the child to finish its task
        
        if(WIFEXITED(status)){
            printf("child process pid:%d exited with status %d \n", child_pid, WEXITSTATUS(status));
        }
        else{
            printf("child process %d didnt exit normally \n", child_pid);
        }
    }
    return 0;
}