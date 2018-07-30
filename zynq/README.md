# zynq
**Zynqberry上で実行するファイル・コード群**

## src
**ソースファイルを格納**

### zynq_nn_hd.cpp
ニアレストネイバー回路を実行するテストベンチ．Zynqberry上で実行する．

### nearest_neighbor_axim.cpp
ニアレストネイバー回路を実行するコード．`zynq_nn_hd.cpp`上で使用する．

## include
**ヘッダファイルを格納**

### main.h
メモリ番地や画像サイズのマクロを明記したもの．

### xnearest_neighbor_axim_hw.h
Vivado HLSから出力されたニアレストネイバー回路を制御するためのメモリ番地が書かれたヘッダファイル．

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