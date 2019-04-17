#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/list.h>
#include <linux/errno.h>
#include "get_proc_info_sys.h"


SYSCALL_DEFINE2(get_proc_info, pid_t, pid, struct procinfos*, info) {

    // curent
    
    
    if (pid == -1) {
        
        struct task_struct *task_info = current;
        struct task_struct *oldest_child;
        struct procinfos tmp;

        tmp.studentID = 1810141;
        tmp.proc.pid = task_info->pid;
        tmp.parent_proc.pid = task_info->parent->pid;
        strcpy(tmp.proc.name, task_info->comm);
        strcpy(tmp.parent_proc.name, task_info->comm);

        if (!list_empty(&task_info->children)) //Check if there are any children, if there are find the youngest and store its PID
        {
            
            oldest_child = list_first_entry(&task_info->children, struct task_struct, sibling);
            tmp.oldest_child_proc.pid = oldest_child->pid;
            strcpy(tmp.oldest_child_proc.name, oldest_child->comm);
            
        }
        else 
        {
            tmp.oldest_child_proc.pid = -1;
            strcpy(tmp.oldest_child_proc.name, "Non-existent"); 
        }

        if(copy_to_user(info, &tmp, sizeof(tmp)))
            return EFAULT;
        
        
        printk("MSSV: %ld", info->studentID);
        printk("Parent PID : %d\n", info->parent_proc.pid);
        printk("Parent Name : %s \n", info->parent_proc.name);
        printk("Child PID : %d\n", info->oldest_child_proc.pid);
        printk("Child Name : %s\n" , info->oldest_child_proc.name);
        printk("Current PID : %d\n", info->proc.pid);
        printk("Current Name : %s \n", info->proc.name);
        

    }
    else 
    {
        struct pid *pid_struct;
        struct procinfos tmp;
        pid_struct = find_get_pid(pid);

        if (pid_struct == NULL) {
            info->studentID = 1810141;
            printk("MSSV: %ld", info->studentID);
            return EINVAL;
        }

        struct task_struct *oldest_child;
        struct task_struct *task_info;
        
        task_info = pid_task(pid_struct, PIDTYPE_PID);
        

        tmp.studentID = 1810141;
        tmp.proc.pid = task_info->pid;
        tmp.parent_proc.pid = task_info->parent->pid;
        strcpy(tmp.proc.name, task_info->comm);
        strcpy(tmp.parent_proc.name, task_info->comm);
        
        if (!list_empty(&task_info->children)) //Check if there are any children, if there are find the youngest and store its PID
        {
            
            oldest_child = list_first_entry(&task_info->children, struct task_struct, sibling);
            tmp.oldest_child_proc.pid = oldest_child->pid;
            strcpy(tmp.oldest_child_proc.name, oldest_child->comm);
            
        }
        else 
        {
            tmp.oldest_child_proc.pid = -1;
            strcpy(tmp.oldest_child_proc.name, "Non-existent"); 
        }

        if(copy_to_user(info, &tmp, sizeof(tmp)))
            return EFAULT;

        printk("MSSV: %ld", info->studentID);
        printk("Parent PID : %d\n", info->parent_proc.pid);
        printk("Parent Name : %s \n", info->parent_proc.name);
        printk("Child PID : %d\n", info->oldest_child_proc.pid);
        printk("Child Name : %s\n" , info->oldest_child_proc.name);
        printk("Task PID : %d\n", info->proc.pid);
        printk("Task Name : %s \n", info->proc.name);
                
    }
    return 0;   
}


// MODULE_LICENSE("GPL");
// MODULE_AUTHOR(DRIVER_AUTHOR);	
