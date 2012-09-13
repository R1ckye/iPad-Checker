//
//  main.c
//  iPad Checker
//
//  Created by Richard Murvai on 2012.09.13..
//

#include <stdio.h>
#include <libusb.h>

int main(void) {
    libusb_init(NULL);
    libusb_device **devices;
    libusb_get_device_list(NULL, &devices);
    
    libusb_device *dev;
	int i = 0;
    
	while ((dev = devices[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		libusb_get_device_descriptor(dev, &desc);
        if (desc.idProduct == 4767) {
            printf("This is an older version of iPad 2!\n\n");
            printf("iPad Checker from Rickye, @R1cqye\n");
            libusb_free_device_list(devices, 1);
            libusb_exit(NULL);
            return 0;
        }
        else if (desc.idProduct == 4777) {
            printf("This is a newer version of iPad 2!\n\n");
            printf("iPad Checker from Rickye, @R1cqye\n");
            libusb_free_device_list(devices, 1);
            libusb_exit(NULL);
            return 0;
        }
	}
    libusb_free_device_list(devices, 1);
	libusb_exit(NULL);
    printf("No iPad 2 found!\n\n");
    printf("iPad Checker from Rickye, @R1cqye\n");    
    return 0;
}

