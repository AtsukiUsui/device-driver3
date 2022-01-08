// SPDX-License-Identifier: GPL-3.0

/*
 * Copyright (C) 2021 Atsuki Uusui and Ryuichi Ueda.  All rights reserved.
 */






#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/delay.h>

MODULE_AUTHOR("Ryuichi Ueda");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;

static volatile u32 *gpio_base = NULL;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	char c;
	if(copy_from_user(&c,buf,sizeof(char)))
		return -EFAULT;

	int i;
	if(c == '0'){
		for(i = 0 ; i < 5 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '1'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 4 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '2'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '3'){
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '4'){
		for(i = 0 ; i < 4 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 1 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	if(c == '5'){
		for(i = 0 ; i < 5 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '6'){
		for(i = 0 ; i < 1 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 4 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '7'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '8'){
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '9'){
		for(i = 0 ; i < 4 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 1 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}


	else if(c == 'A'||c == 'a'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);
	}

	else if(c == 'B'||c == 'b'){
		for(i = 0 ; i < 1 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}	
		 msleep(2000/3);
	}

	else if(c == 'C'||c == 'c'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == 'D'||c == 'd'){
		for(i = 0 ; i < 1 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == 'E'||c == 'e'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	else if(c == 'F'||c == 'f'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	else if(c == 'G'||c == 'g'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	if(c == 'H'||c == 'h'){
		for(i = 0 ; i < 4 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
			 msleep(2000/3);
		}
	}

	if(c == 'I'||c == 'i'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
			 msleep(2000/3);
		}
	}

	else if(c == 'J'||c == 'j'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		       	msleep(2000/3);
		}
	}

	else if(c == 'K'||c == 'k'){
		gpio_base[7] = 1 <<25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 <<25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);
	}

	else if(c == 'L'||c == 'l'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
			 msleep(2000/3);
		}
	}

	if(c == 'M'||c == 'm'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
			 msleep(2000/3);
		}
	}

	else if(c == 'N'||c == 'n'){

		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	if(c == 'O'||c == 'o'){
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
			 msleep(2000/3);
		}
	}

	else if(c == 'P'||c == 'p'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	else if(c == 'Q'||c == 'q'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 << 25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	else if(c == 'R'||c == 'r'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 1 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	if(c == 'S'||c == 's'){
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	if(c == 'T'||c == 't'){
		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);
	}

	else if(c == 'U'||c == 'u'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);
	}

	else if(c == 'V'||c == 'v'){
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);
	}

	else if(c == 'W'||c == 'w'){
		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == 'X'||c == 'x'){

		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 <<25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}

		gpio_base[7] = 1 <<25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);
		 msleep(2000/3);

	}

	else if(c == 'Y'||c == 'y'){
		gpio_base[7] = 1 << 25;
		msleep(1000);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		gpio_base[7] = 1 <<25;
		msleep(1000/3);
		gpio_base[10] = 1 <<25;
		msleep(1000/3);

		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		} 
		 msleep(2000/3);
	}

	else if(c == 'Z'||c == 'z'){
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		for(i = 0 ; i < 2 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		}
		 msleep(2000/3);
	}

	else if(c == '.'){
		for(i = 0 ; i < 3 ; i++){
			gpio_base[7] = 1 << 25;
			msleep(1000/3);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);

			gpio_base[7] = 1 << 25;
			msleep(1000);
			gpio_base[10] = 1 <<25;
			msleep(1000/3);
		
		}
		msleep(2000/3);
	}

	else if(c == ' '){
		gpio_base[10] = 1 << 25;
		msleep(7000/3);
	}

	return 1;
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.write = led_write
};

static int __init init_mod(void)
{
	int retval;

	gpio_base = ioremap_nocache(0x3f200000, 0xA0);

	const u32 led = 25;
	const u32 index = led/10;
	const u32 shift = (led%10)*3;
	const u32 mask = ~(0x7 << shift);
	gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);

	retval =  alloc_chrdev_region(&dev, 0, 1, "myled");
	if(retval < 0){
		printk(KERN_ERR "alloc_chrdev_region failed.\n");
		return retval;
	}
	printk(KERN_INFO "%s is loaded. major:%d\n",__FILE__,MAJOR(dev));

	cdev_init(&cdv, &led_fops);
	cdv.owner = THIS_MODULE;
	retval = cdev_add(&cdv, dev, 1);
	if(retval < 0){
		printk(KERN_ERR "cdev_add failed. major:%d, minor:%d",MAJOR(dev),MINOR(dev));
		return retval;
	}

	cls = class_create(THIS_MODULE,"myled");
	if(IS_ERR(cls)){
		printk(KERN_ERR "class_create failed.");
		return PTR_ERR(cls);
	}
	device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));
	return 0;
}

static void __exit cleanup_mod(void)
{
	cdev_del(&cdv);
	device_destroy(cls, dev);
	class_destroy(cls);
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
	iounmap(gpio_base);
}


module_init(init_mod);
module_exit(cleanup_mod);
