#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "S. Sylka <semen.sylka@emlid.com>"
#define DRIVER_DESC   "Simple 'Hello world' driver"
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static char *greeting_string __initdata = "Hello from the kernel";

/// initialize the driver
static int __init sample_kernel_init(void) {
  // printk(KERN_INFO, "%s\n", greeting_string);
  pr_info("Hello from the kernel\n");
  return 0;
}
/// exit method
static void __exit sample_kernel_exit(void) {
  // printk(KERN_INFO, "Bye from the kernel\n");
  pr_info("Bye from the kernel\n");
  return;
}

/// attach init/exit functions at kernel_module funcs
module_init(sample_kernel_init);
module_exit(sample_kernel_exit);
