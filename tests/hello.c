/**
 *  @file       hello.c
 *  @author     Shreyas Atre
 *  @date       2021-03-12
 *  @version    0.1
 *  @brief      An introductory lkm from exprloring embedded linux by Derek
 **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SHREYAS ATRE");
MODULE_DESCRIPTION("LINUX KERNEL MODULE INTRO");
MODULE_VERSION("0.1");

/**
 * @brief LKM argument
 * defaults to KERNEL
 */
static char *name = "KERNEL";


/**
 * @brief           LKModule parameters to be passed. More info https://stackoverflow.com/questions/27480369/why-should-the-permisson-attrbute-be-specified-for-every-variable-declared-in-ke
 * @param name      can be anything like your name, or anything sensible
 * @param charp     charp stands for charpointer 
 * @param S_IRUGO   S_IRUGO is a parameter for a word that can be read by anyone and cannot be changed
 */
module_param(name,charp,S_IRUGO);
MODULE_PARM_DESC(name, "Any name for kernel logs");

/**
 * @brief           Initializes the module. __init macro is important .
 *                  This function stays only upto initialization point and can be freed from memory   
 *                  thereafter 
 *
 * @return          0 if succesful
 */
static int __init hello_world_init(void)
{
    printk(KERN_INFO"POCKETBEAGLE: HELLO %s ! FIRST LKM\n",name);
    return 0;
}


/**
 * @brief           Similar to initialization it is static for this file 
 *                  more @ https://stackoverflow.com/questions/11680641/init-and-exit-macros-usage-for-built-in-and-loadable-modules
 * @return 
 */
static void __exit hello_world_exit(void)
{
    printk(KERN_INFO"POCKETBEAGLE: EXITING %s \n",name);
}

/**
 * @brief           Necessary for kernel to know the initialization functions
 *
 */
module_init(hello_world_init);
module_exit(hello_world_exit);

