#!/bin/bash
#实现输入密码时，不显示输入内容

echo -e "Enter password: "
stty -echo
read password
stty echo
echo
echo -e "Password read."
