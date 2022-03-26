//
// Created by kip on 3/26/22.
//
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sigfpeHandler(int signum){
    printf("Signal received: %d\n", signum);
    int currentProcessId = getpid();
    int ret = kill(currentProcessId, SIGKILL); //terminate the current process by sending a SIGKILL signal.
}
int main(int argc, char *argv[]){
    int array1[5]  = {34, 98, 72, 27, 85} ;
    int array2[5]  = {34, 98, 72, 0, 85} ;
    int divisionResult;
    signal(SIGFPE, sigfpeHandler);
    for (int i = 0; i <sizeof(array1)/sizeof(int) ; ++i) {
        printf("numbers chosen: %d and %d\n", array1[i], array2[i]);
        divisionResult = array1[i]/array2[i];
    }

    return 0;
}

