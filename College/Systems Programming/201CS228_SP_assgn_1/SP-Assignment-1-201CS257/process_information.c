#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/rcupdate.h>
#include <linux/timekeeping.h>
#include <linux/ktime.h>

/*
	Shashank SM
	201CS257
	SP Assignment 1
*/

SYSCALL_DEFINE0(process_infomation){

	// The below program is used to get the parent process ID, process ID, process state, and time since epoch
	int parent_pid;  
	struct timespec64 ts; 
	int program_pid; 
	
	ktime_get_real_ts64(&ts); 
	
	rcu_read_lock(); 
	parent_pid = task_tgid_vnr(rcu_dereference(current->real_parent)); // Getting the parent process ID
	rcu_read_unlock(); 
	
	program_pid = task_tgid_vnr(current);  // Getting the process ID
	
	printk("Time : %lld seconds, %ld nanoseconds\n", ts.tv_sec, ts.tv_nsec);
	printk("Task state: %c\n", task_state_to_char(current)); 
	printk("Task PID: %d\n", program_pid);
	printk("Parent Process's PID: %d\n", parent_pid);
	return 0;
}
