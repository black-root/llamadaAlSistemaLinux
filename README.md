# llamadaAlSistemaLinux
Programa de usuario: ingresa 10 numeros enteros en un vector, hace una llamada al sistema
Llamada al sistema: obtiene un vector entero de lenght 10 y escoge el mayor, devuele ese valor



Para ver la respuesta: #dmesg(dmsg o tail -f /var/log/syslog) 

Configurando servidor ssh

VBoxManage list vms -l     
 VBoxManage startvm "jessie32"

Maquina Virtual → Configuracion→ Red → Adaptador Solo anfitrion → nombre: vboxnet0
Si no posee vboxnet0 habilitarlo
#cd /etc/network
# nano interfaces

source /etc/network/interfaces.d/*
# The loopback network interface
auto lo
iface lo inet loopback

allow-hotplug eth0
iface eth0 inet dhcp

allow-hotplug eth1
iface eth1 inet static
address 192.168.56.3
netmask 255.255.255.0



#/etc/init.d/networking stop
#/etc/init.d/networking start
#ifup eth0
#ifup eth1
Desde el sistema invitado conectarse al servidor ssh -p 22 usuario@192.168.56.3

Configurando el ambiente de trabajo.

Descargar el kernel 3.16 de linux  en el directorio /usr/src
# cd /usr/src
# wget https://cdn.kernel.org/pub/linux/kernel/v3.x/linux-3.16.49.tar.xz
# tar Jxvf  linux-3.16.49.tar.xz
# cd /usr/src/linux-source-3.16/arch/x86/syscalls

#nano syscall_32.tbl
357     i386    igmp                    sys_igmp
#cd /usr/src/linux-3.16.49/kernel
#nano igpm.c

Hacemos el programa
#nano Makefile
agregar en el inicio : 	
obj-y     	= fork.o exec_domain.o panic.o \
            cpu.o exit.o itimer.o time.o softirq.o resource.o \
            sysctl.o sysctl_binary.o capability.o ptrace.o timer.o user.o \
            signal.o sys.o kmod.o workqueue.o pid.o task_work.o \
            extable.o params.o posix-timers.o \
            kthread.o sys_ni.o posix-cpu-timers.o \
            hrtimer.o nsproxy.o \
            notifier.o ksysfs.o cred.o reboot.o \
            async.o range.o groups.o smpboot.o igmp.o


#cd  /usr/src/linux-source-3.16/include/linux

#nano syscalls.h
Al final del archivo agregamos esta linea:
asmlinkage long sys_igmp(int  *vector,  int  *mayor); 



Compilando e instalando kernels
#make localmodconfig
#make-kpkg --initrd --append-to-version=-escribir-lo-que-sea kernel-image kernel-headers
#dpkg -i *.deb
# dpkg -l | grep linux-image //aqui vemos qué imagen tenemos instalada
#mkinitramfs -k -o /boot/initrd.img-2.6.32.15+drm33.5 2.6.32.15+drm33.5
#update-initramfs -uk all

Borrar Kernels
#dpkg --get-selections | grep linux-image 	    o		 dpkg -l | grep linux-image
#apt-get remove --purge linux-image-X.X.X-X

