/*                                                     
 * $Id: hellop.c,v 1.4 2004/09/26 07:02:43 gregkh Exp $ 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("LDD3, Silviu-Mihai Popescu");
MODULE_DESCRIPTION("'Hello World with params' module in LDD3.\
			with modern practices.");

/*                                                        
 * These lines, although not shown in the book,           
 * are needed to make hello.c run properly even when      
 * your kernel has version support enabled                
 */                                                       
                                                          

/*
 * A couple of parameters that can be passed in: how many times we say
 * hello, and to whom.
 */
static char *whom = "world";
static int howmany = 1;
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init hello_init(void)
{
	int i;
	for (i = 0; i < howmany; i++)
		pr_alert("(%d) Hello, %s\n", i, whom);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_alert("Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
