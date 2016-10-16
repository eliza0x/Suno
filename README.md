Suno
====

[![Build Status](https://travis-ci.org/eliza0x/Suno.svg?branch=master)](https://travis-ci.org/eliza0x/Suno)

SunoはESP8266(ESP-WROOM-02)で制御する無線ソーラーカーです、てさぐりで頑張ります。

## USAGE

SSIDが`Taiyoooo`,Passwordが`mofumofu`のWifi(IEEE 802.11)を準備してください。
あとは`http://$ESP8266_IP_ADDRESS$/Forward/Right`のように接続すれば制御できます。

`$ESP8266_IP_ADDRESS$`は環境によって変動します、シリアル通信で確認してください。ESP8266の起動後すぐに送られてくる筈です。

使える命令
Motor
- Forward 
- Backward
- Stop
- Brake

ServoMotor
- Right
- Center
- Left

それぞれの命令がURLにふくまれていればその通り動作するはずです。

## CIRCUIT


## HACKING

[PlatformIO](http://platformio.org/)でESP8266にプログラムを書き込んでいます。

書き込み
`$ platformio run --target=upload`

シリアルモニタに接続
`$ platformio serialports monitor`

![UML](https://raw.githubusercontent.com/eliza0x/Suno/master/UML.png)

## VERSION

0.0.1

## LICENCE

MIT LICENCE
