Suno
====

[![Build Status](https://travis-ci.org/eliza0x/Suno.svg?branch=master)](https://travis-ci.org/eliza0x/Suno)

SunoはESP8266(ESP-WROOM-02)で制御する無線ソーラーカーです、てさぐりで頑張ります。

## USAGE

SSIDが`taiyoooo`,Passwordが`mofumofu`のWifiスポットを準備してください。
接続後`http://$ESP8266_IP_ADDRESS$/Move/Right`のようにアクセスすれば制御できます。

`$ESP8266_IP_ADDRESS$`は環境によって変動します、シリアル通信で確認してください。ESP8266の起動後すぐに送られてくる筈です。

使える命令
- Move
- Stop
- Right
- Center
- Left

命令がURLにふくまれていればその通り動作するはずです。

## CIRCUIT

![Circuit](https://raw.githubusercontent.com/eliza0x/Suno/master/Circuit.png)

## PROGRAMMING

[PlatformIO](http://platformio.org/)でESP8266にプログラムを書き込んでいます。

書き込み: `$ platformio run --target=upload`
シリアルモニタに接続: `$ platformio serialports monitor`

![UML](https://raw.githubusercontent.com/eliza0x/Suno/master/UML.png)

## VERSION

0.0.1

## LICENCE

MIT LICENCE
