# myReadCAN
read CAN data

> 系统：ubuntu1804

## 简述：
通过CAN口读取陀螺仪输出数据，并解析出Z轴加速度数据

该陀螺仪输出数据包含两个CANID（0x401和0x402），demo中只解析了401的Z轴数据


401h	IMU_AccelRaw	AccelRawX

401h	IMU_AccelRaw	AccelRawY

401h	IMU_AccelRaw	AccelRawZ

402h	IMU_AngRateRaw	AngRateRawX

402h	IMU_AngRateRaw	AngRateRawY

402h	IMU_AngRateRaw	AngRateRawZ

