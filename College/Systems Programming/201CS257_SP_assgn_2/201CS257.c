#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shashank SM - 201CS257");

// Entry point of the module
static int __init entryPoint(void) {
	struct task_struct *task;	
	
	printk(KERN_INFO "Starting to list tasks\n");

	for_each_process(task) {
		printk(KERN_INFO "Process ID: %d, Command: %s, State: %ld\n", task->pid, task->comm, task->__state);
	}
	
	printk(KERN_INFO "Stopped listing tasks\n");
	return 0;
}

// Exit point of the module
static void __exit exitPoint(void) {
	printk(KERN_INFO "Removing the tasklist module\n");
}

// Registering the entry and exit points of the module
module_init(entryPoint);
module_exit(exitPoint);


