#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

E_LICENSE("GPL");
E_AUTHOR("CS316");
E_DESCRIPTION("Hello World!!");

static int __init hello_init(void) // Function run when module is loaded
{
    printk(KERN_INFO "Hello, world!\n");
    return 0;
}

static void __exit hello_exit(void) // Fiunction run when module is removed
{
    printk(KERN_INFO "Goodbye, world!\n");
}

module_init(hello_init); // Registers the hello_init() function as the module's initialization function.
module_exit(hello_exit); // Registers the hello_exit() function as the module's cleanup function.
 
// make -C /lib/modules/`uname -r`/build M=$PWD
