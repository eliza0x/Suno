Suno
====

[![Build Status](https://travis-ci.org/eliza0x/Suno.svg?branch=master)](https://travis-ci.org/eliza0x/Suno)

Suno(仮)はESP8266(ESP-WROOM-02)で制御する無線ソーラーカーです、てさぐりで頑張ります。

## USAGE

SSIDが`SunoController`,Passwordが`password`のWifi(IEEE 802.11)を準備してください。
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

12,13番ピンはモータドライバへ、16番ピンはサーボモータの制御部へ繋いでください。
モータドライバは東芝のTA7291Pを想定しています。

## HACKING

[PlatformIO](http://platformio.org/)でESP8266にプログラムを書き込んでいます。

書き込み
`$ platformio run --target=upload`

情報をうけとる
`$ platformio serialports monitor`

## VERSION

0.0.1

## LICENCE

MIT LICENCE
