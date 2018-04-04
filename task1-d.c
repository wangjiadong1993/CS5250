#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
MODULE_LICENSE("GPL");

//parameters
static char *who = "nobody";
module_param(who, charp, 0000);
MODULE_PARM_DESC(who, "who");

static int hello_init(void){
	printk(KERN_ALERT "hello %s\n", who);
	return 0;
}
static void hello_exit(void){
	printk(KERN_ALERT "Goodbye %s\n", who);
}
module_init(hello_init);
module_exit(hello_exit);
