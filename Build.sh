#!/bin/bash

if [ ! -e ./dxlib.zip ]; then
  curl -o dxlib.zip https://dxlib.xsrv.jp/DxLib/DxLib_Android3_24b.zip
  unzip dxlib.zip
fi

mkdir out || true
rm out/* || true
node main.mjs out DxLib_Android/help/function/*.html
