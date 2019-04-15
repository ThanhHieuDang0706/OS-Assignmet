#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/kernel.h>

#define SIZE 200

int main() {
    if (fork() > 0) {
    long sys_return_value;
    long new[SIZE];
    // sys_return_value = syscall(335, -1, &new);
    // printf("My student ID: %ld \n", new[0]);
    // printf("Sys return val: %ld\n", sys_return_value);
    sys_return_value = syscall(335, 0, &new);
    printf("My student ID: %ld \n", new[0]);
    printf("Sys return val: %ld\n", sys_return_value);
    
    sleep(2);
    return 0;
    } else {
        if (fork() > 0) {}
        else {
        sleep(2);
        
        }
    }
}