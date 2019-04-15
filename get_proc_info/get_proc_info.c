#include"get_proc_info.h"
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>

long sys_get_proc_info(pid_t pid,struct procinfos* info) {
    // TODO: implement the wrapper here.
    return syscall(335, pid, info);
}