/* This file is generated with usbsnoop2libusb.pl from a usbsnoop log file. */
/* Latest version of the script should be in http://iki.fi/lindi/usb/usbsnoop2libusb.pl */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#include <usb.h>
#include "alphamote.h"

int main(int argc, char **argv) {
    int ret;
    char buf[65535];

    init_usb();

    ret = usb_get_descriptor(devh, 0x0000001, 0x0000000, buf, 0x0000012);
    usleep(4*1000);
    ret = usb_get_descriptor(devh, 0x0000002, 0x0000000, buf, 0x0000009);
    usleep(3*1000);
    ret = usb_get_descriptor(devh, 0x0000002, 0x0000000, buf, 0x0000027);
    usleep(4*1000);
    ret = usb_release_interface(devh, 0);
    if (ret != 0) printf("failed to release interface before set_configuration: %d\n", ret);
    ret = usb_set_configuration(devh, 0x0000001);
    ret = usb_claim_interface(devh, 0);
    if (ret != 0) printf("claim after set_configuration failed with error %d\n", ret);
    ret = usb_set_altinterface(devh, 0);
   
    // get info (bulk read 62)
    usleep(100*1000);
    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x02\x10\x00\x00\x00\x00\x01\x00\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("1%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("2%d\n", ret);
    
    memcpy(buf, "\x0c\x00\x00\x00\x01\x00\x01\x10\x01\x00\x00\x00", 0x000000c);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x000000c, 1000);
    usleep(100*1000);
    if(ret < 0) printf("3%d\n", ret);
    
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x000000ff, 1030);
    usleep(100*1000);
    if(ret < 0) printf("4%d\n", ret); 
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("5%d\n", ret);

    memcpy(buf, "\x0c\x00\x00\x00\x01\x00\x04\x10\x02\x00\x00\x00", 0x000000c);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x000000c, 1000);
    usleep(100*1000);
    if(ret < 0) printf("6%d\n", ret);
    
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000014, 1030);
    usleep(100*1000);
    if(ret < 0) printf("7%d\n", ret); 
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("8%d\n", ret);
    memcpy(buf, "\x18\x00\x00\x00\x01\x00\x01\x92\x03\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 0x0000018);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000018, 1000);
    usleep(100*1000);
    if(ret < 0) printf("9%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000014, 1030);
    usleep(100*1000);
    if(ret < 0) printf("10%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("11%d\n", ret);
    memcpy(buf, "\x18\x00\x00\x00\x01\x00\x01\x92\x04\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 0x0000018);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000018, 1000);
    usleep(100*1000);
    if(ret < 0) printf("12%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000014, 1030);
    usleep(100*1000);
    if(ret < 0) printf("13%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("14%d\n", ret);
    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x02\x92\x05\x00\x00\x00\xc8\x00\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("15%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000005e, 1030);
    usleep(100*1000);
    if(ret < 0) printf("16%d\n", ret);   
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("17%d\n", ret);
    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x02\x92\x06\x00\x00\x00\xc8\x00\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("18%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000005e, 1030);
    usleep(100*1000);
    if(ret < 0) printf("19%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("20%d\n", ret);
    memcpy(buf, "\x18\x00\x00\x00\x01\x00\x01\x92\x07\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 0x0000018);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000018, 1000);
    usleep(100*1000);
    if(ret < 0) printf("21%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000014, 1030);
    usleep(100*1000);
    if(ret < 0) printf("22%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("23%d\n", ret);
    memcpy(buf, "\x0c\x00\x00\x00\x01\x00\x09\x92\x08\x00\x00\x00", 0x000000c);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x000000c, 1000);
    usleep(100*1000);
    if(ret < 0) printf("24%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000200, 1030);
    usleep(100*1000);
    if(ret < 0) printf("25%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000200, 1030);
    usleep(100*1000);
    if(ret < 0) printf("26%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000035, 1030);
    usleep(100*1000);
    if(ret < 0) printf("27%d\n", ret);  
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("28%d\n", ret);
    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x07\x92\x09\x00\x00\x00\xc1\xd2\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("29%d\n", ret);
    memcpy(buf, "\x0e\x00\x00\x00\x02\x00\x07\x92\x09\x00\x00\x00\x01\x00", 0x000000e);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000000e, 1000);
    usleep(100*1000);
    if(ret < 0) printf("30%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("31%d\n", ret); 
    memcpy(buf, "\x0c\x00\x00\x00\x01\x00\x09\x92\x0a\x00\x00\x00", 0x000000c);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x000000c, 1000);
    usleep(100*1000);
    if(ret < 0) printf("32%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000200, 1030);
    usleep(100*1000);
    if(ret < 0) printf("33%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000200, 1030);
    usleep(100*1000);
    if(ret < 0) printf("34%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x00000035, 1030);
    usleep(100*1000);
    if(ret < 0) printf("35%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("36%d\n", ret);
    
    usleep(5000*1000);

    //making the shot
    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x07\x92\xeb\x01\x00\x00\xc7\xd2\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("37%d\n", ret);
    memcpy(buf, "\x0e\x00\x00\x00\x02\x00\x07\x92\xeb\x01\x00\x00\x02\x00", 0x000000e);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000000e, 1000);
    usleep(100*1000);
    if(ret < 0) printf("38%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(100*1000);
    if(ret < 0) printf("39%d\n", ret);

    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x07\x92\xec\x01\x00\x00\xc2\xd2\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("40%d\n", ret);
    memcpy(buf, "\x0e\x00\x00\x00\x02\x00\x07\x92\xec\x01\x00\x00\x01\x00", 0x000000e);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000000e, 1000);
    usleep(100*1000);
    if(ret < 0) printf("41%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(1000*1000);
    if(ret < 0) printf("42%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000083, buf, 0x00000010, 1030);
    usleep(1000*1000);
    if(ret < 0) printf("43%d\n", ret);

    memcpy(buf, "\x10\x00\x00\x00\x01\x00\x07\x92\xed\x01\x00\x00\xc1\xd2\x00\x00", 0x0000010);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000010, 1000);
    usleep(100*1000);
    if(ret < 0) printf("44%d\n", ret);
    memcpy(buf, "\x0e\x00\x00\x00\x02\x00\x07\x92\xed\x01\x00\x00\x01\x00", 0x000000e);
    ret = usb_bulk_write(devh, 0x00000002, buf, 0x0000000e, 1000);
    usleep(100*1000);
    if(ret < 0) printf("45%d\n", ret);
    ret = usb_bulk_read(devh, 0x00000081, buf, 0x0000000c, 1030);
    usleep(1000*1000);
    if(ret < 0) printf("46%d\n", ret);

    ret = usb_release_interface(devh, 0);
    usleep(1000*1000);
    if(ret < 0) printf("47%d\n", ret);
    assert(ret == 0);
    ret = usb_close(devh);
    assert(ret == 0);
    return 0;
}
