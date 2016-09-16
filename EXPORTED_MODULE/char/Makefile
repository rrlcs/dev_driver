INSTALLDIR= modules
ifneq ($(KERNELRELEASE),)
	obj-m := rr.o
	rr-objs := hello_kernel.o clean.o

else
	KERNDIR ?= /lib/modules/3.19.8-100.fc20.x86_64/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
	rm -rf $(INSTALLDIR)

endif

