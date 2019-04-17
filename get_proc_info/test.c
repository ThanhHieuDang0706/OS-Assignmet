#include <stdio.h>
#include <get_proc_info.h>
#include <stdbool.h>

void printinfo (const struct procinfos *info) {
    printf("MSSV : %ld\n", info->studentID);
    printf("Process PID : %d\n", info->proc.pid);
    printf("Process Name : %s\n", info->proc.name);
    printf("Parent PID : %d\n", info->parent_proc.pid);
    printf("Parent Name : %s\n", info->parent_proc.name);
    printf("Oldest child PID : %d\n", info->oldest_child_proc.pid);
    printf("Oldest Child Name : %s\n", info->oldest_child_proc.name);
    printf("-----------------------------\n");
}


int main () {
    bool done = false;
    struct procinfos info;
    while (!done) {
        int pid;
        printf("Enter pid : ");
        scanf("%d", &pid);
        if (pid == 0) {
            done = true;
        } else {
        long retval = sys_get_proc_info(pid, &info);
        printinfo(&info);
        }
    }

    return 0;
}