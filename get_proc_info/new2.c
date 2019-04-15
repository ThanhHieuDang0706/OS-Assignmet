#include <get_proc_info.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/kernel.h>

void printinfo (const struct procinfos *info) {
    printf("MSSV : %ld\n", info->studentID);
    printf("Process PID : %d\n", info->proc.pid);
    printf("Process Name : %s\n", info->proc.name);
    printf("Parent PID : %d\n", info->parent_proc.pid);
    printf("Parent Name : %s\n", info->parent_proc.name);
    printf("Oldest child PID : %d\n", info->oldest_child_proc.pid);
    printf("Oldest Child Name : %s\n", info->oldest_child_proc.name);
}


int main () {
    int mypid = getpid();
    printf("PID: %d\n", mypid);
    struct procinfos info;
    if (fork() > 0) {
    if (sys_get_proc_info(mypid, &info) == 0) {
        printinfo(&info);
    }  else {
        printf("Cannot get information from my process PID %d", mypid);
    }
    }
    else if (fork() > 0);
    sleep(100);
    return 0;

}