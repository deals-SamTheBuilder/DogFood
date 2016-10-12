# 启动程序
adb shell am start -n com.xxx.xxx/.MainActivity

# 关闭程序
adb shell am force-stop com.aispeech.aios

# 拉取文件
adb pull <remote-directory>  <local-directory>

# 推送文件
adb push <local-directory> <remote-directory>

# 程序列表
adb shell pm list packages

# 安装程序
adb install xxx.apk

# 卸载程序
# 包名在xml文件中查看
adb uninstall com.xxx.xxx

# 查看IP
adb shell netcfg

# 查看日志,并打印时间,进程,线程.
adb logcat -v threadtime
