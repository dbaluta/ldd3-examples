/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("LDD3, Silviu-Mihai Popescu");
MODULE_DESCRIPTION("'Hello World' module in LDD3, with modern practices.");

static int __init hello_init(void)
{
	pr_alert("Hello, world\n");
	return 0;
}

static void __exit hello_exit(void)
{
	pr_alert("Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
