#ifndef _GET_PROC_INFO_H_
#define _GET_PROC_INFO_H_

#include <linux/types.h>
#include <unistd.h>

struct proc_info {
    pid_t pid;
    char name[16];
};

struct procinfos {
    long studentID;
    struct proc_info proc;
    struct proc_info parent_proc;
    struct proc_info oldest_child_proc;
};

long sys_get_proc_info(pid_t pid, struct procinfos * info);
#endif