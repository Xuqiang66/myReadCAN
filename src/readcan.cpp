#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <iostream>
#include "im1_a_evb_v1_0_0_211018.h"


int main(int argc, char **argv)
{
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;
    int nbytes;
    char *ifname = "can0"; // 选择一个 CAN 接口，比如 can0
    double parsed_value = 0.0;
    struct im1_a_evb_v1_0_0_211018_imu_accel_raw_t accel_raw;

    // 创建 socket
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Error while opening socket");
        return -1;
    }
    printf("create socket success\n");

    // 指定 can0 设备
    strcpy(ifr.ifr_name, ifname);
    ioctl(s, SIOCGIFINDEX, &ifr);

    // 将 socket 绑定到 can0 设备
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error in socket bind");
        return -2;
    }
    printf("bind success\n");

    // 读取 CAN 数据帧
    while (1) {
        nbytes = read(s, &frame, sizeof(struct can_frame));
        if (nbytes < 0) {
            perror("Error in socket read");
            return -3;
        }
	/*
        printf("CAN ID: 0x%X, DLC: %d, Data: ", frame.can_id, frame.can_dlc);
        for (int i = 0; i < frame.can_dlc; i++) {
            printf("%02X ", frame.data[i]);
        }
        printf("\n");*/

	//jiexishuju--only z
	if(frame.can_id == 1025) {
		im1_a_evb_v1_0_0_211018_imu_accel_raw_unpack(&accel_raw, frame.data, frame.can_dlc);
		printf("Z: %.3lf\n", im1_a_evb_v1_0_0_211018_imu_ang_rate_raw_ang_rate_raw_z_decode(accel_raw.accel_raw_z));
		im1_a_evb_v1_0_0_211018_imu_ang_rate_raw_ang_rate_raw_z_decode(accel_raw.accel_raw_z);
	}
    }

    close(s);
    return 0;
}
