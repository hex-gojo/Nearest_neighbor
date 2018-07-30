# Nearest_neighbor
**ニアレストネイバー回路の作成**

## nearst_neighbor.c
ニアレストネイバーIPになる元のコード．Vivado HLS上で使用．64×64のbmp画像を128×128のbmp画像に拡大する．top function の引数はポインタ型にする．最適化は行っていない．

## nearest_neighbor_tb.c
Vivado HLS上で使用するテストベンチコード．シミュレーション時に使用する．`test.bmp`を入力とし，回路となるnearst_neighbor.cの`nearest_neighbor_axim`の実行結果と`nn_soft`の実行結果を比較し`nearest_neighbor_axim`の実行結果を`result.bmp`に出力する．`SCALE`は拡大(縮小)倍率である．

## zynq_nn_hd.cpp
ニアレストネイバー回路を実行するテストベンチ．ソフトウェア上で実行する．

## nearest_neighbor_axim.cpp
ニアレストネイバー回路を実行するコード．`zynq_nn_hd.cpp`上で使用する．

## Makefile
C++の分割コンパイル用Makefile．以下のような構成になる．
```
root/
  ├ bin/
  ├ include/
  ├ src/
  ├ build/
  └ Makefile
```
- bin : 実行ファイルが入っているディレクトリ．自動生成される．
- include : インクルードファイル( .h )が入っているディレクトリ．
- src : ソースファイルが入っているディレクトリ．
- build : 中間ファイル( .o .d )が入っているディレクトリ．自動生成される．
    - .d : ソースファイルの依存関係が明記されているファイル．
    - .o : オブジェクトファイル．

## Task
- include fileの作成
- 実機での実装・実行

---
*Update 2018-07-30*