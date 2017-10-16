 
#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>

asmlinkage long sys_igmp(int *vector, int *mayor){

       int i=0;
       for(i; i<10; i++){
               if(*vector > *mayor){
                       *mayor = *vector;
               }
       vector++;
       }

       printk(KERN_ALERT "El numero mayor es: %d\n", *mayor);

       return *mayor;
}

