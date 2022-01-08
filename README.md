# device-draiver

ロボットシステム学 課題１


# Features

英数字(A～Z,0～9)や記号(.)から成る文章をモールス信号に変換する機能を有したデバイスドライバーである。

モールス信号は以下のルールに基づき作成する。

* 各記号の間は・

* 文字同士の間は・・・

* 単語同士の間は・・・・・・・

* 一線は・・・

* ・は1/3秒

# Requirement

* RaspberryPi 3B+

* Ubuntu 18.04 LTS


# DEMO

URL(youtube):https://youtu.be/x6RTnoR-vrE


# Usage

DEMOの実行は下記の回路、コマンドを用いて行う。

![IMG_2458](https://user-images.githubusercontent.com/92910077/146208050-606e1aa6-c0b4-42f0-808c-39b41afba6e5.jpg)

![image](https://user-images.githubusercontent.com/92910077/146677600-168b0fab-35a4-4827-8bca-9c6d889f5354.png)

```
$git clone 
$cd device-driver
$make
$sudo insmod myled.ko
$sudo chmod 666 /dev/myled0
$echo  It is been very cold these days. It is December 15th.> /dev/myled0
$sudo rmmod myled.ko
```

# Reference

* 【GitHub】シンプルなREADME.mdの書き方 -コピペで使えるテンプレート付き- : https://cpp-learning.com/readme/
* ryuichiueda(github) : https://github.com/ryuichiueda/robosys_device_drivers


# Author

* 作成者:AtsukiUsui
* E-mail:programmakeadrb@cocoro.uk


# License

SPDX-License-Identifier: GPL-3.0


