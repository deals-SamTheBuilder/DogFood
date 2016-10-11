#!/bin/bash

配Wifi网络：

adb push wpa_supplicant.conf /data/misc/wifi/wpa_supplicant.conf

adb shell svc wifi enable # open wifi
adb shell svc wifi disable # close wifi

adb shell netcfg # 查看IP
