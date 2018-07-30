# Nearest_neighbor
**ニアレストネイバー回路の作成**

## nearst_neighbor.c
ニアレストネイバーIPになる元のコード．Vivado HLS上で使用．64×64のbmp画像を128×128のbmp画像に拡大する．top function の引数はポインタ型にする．最適化は行っていない．

## nearest_neighbor_tb.c
Vivado HLS上で使用するテストベンチコード．シミュレーション時に使用する．`test.bmp`を入力とし，回路となるnearst_neighbor.cの`nearest_neighbor_axim`の実行結果と`nn_soft`の実行結果を比較し`nearest_neighbor_axim`の実行結果を`result.bmp`に出力する．`SCALE`は拡大(縮小)倍率である．

## zynq
Zynqberry上で実行するファイル・コード群

## Task
- 実機での実装・実行

---
*Update 2018-07-30*