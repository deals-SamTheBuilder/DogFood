#!/bin/bash
#截取登录界面
#先切换到登录界面，然后再切换到文字界面，运行脚本，截图保存在/tmp目录下

sudo chvt 7
sleep 5
DISPLAY=:0.0 XAUTHORITY=/var/lib/lightdm:0.Xauth xwd -root > /tmp/shot.xwd
convert /tmp/shot.xwd /tmp/ss.png
