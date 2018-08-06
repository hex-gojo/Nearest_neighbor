# 参考:
# "汎用的に使えそうなMakefileを書いてみた" ,(URL)http://boysenberrypi.hatenadiary.jp/entry/2014/03/15/113703
# "wildcardを利用したシンプルな汎用Makefile" ,(URL)https://qiita.com/szkny/items/07b4c93702b3f8090fa3

# コンパイラの宣言
CC = g++

# ソースファイルの拡張子
SUFFIX = .cpp

# コンパイラオプションの宣言
CFLAGS = -g -MMD -MP

# ライブラリの宣言
LDFLAGS = `pkg-config --cflags --libs opencv`
LIBS =

# ヘッダファイルのディレクトリの宣言
INCLUDE = -I ./include

# ソースファイルのディレクトリの宣言
SRC_DIR = ./src

# 中間ファイルのディレクトリの宣言
OBJ_DIR = ./build

# 実行ファイルのディレクトリの宣言
EXE_DIR = ./bin

# ソースファイルの宣言
SOURCES = $(shell ls $(SRC_DIR)/*$(SUFFIX))

# オブジェクトファイルの宣言
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SOURCES:$(SUFFIX)=.o))

# 実行ファイルの宣言
EXES = $(EXE_DIR)/$(TARGET)

# ターゲットネーム(実行ファイル名)の宣言
TARGET = main

# 中間ファイルの宣言
DEPENDS = $(OBJS:.o=.d)

# allターゲット
all: $(TARGET)

# TARGETの依存関係
$(TARGET): $(OBJS) $(LIBS)
	@if [ ! -d $(EXE_DIR) ]; \
		then echo "mkdir -p $(EXE_DIR)"; mkdir -p $(EXE_DIR); \
		fi
	$(CC) -o $(EXE_DIR)/$@ $(OBJS) $(LDFLAGS)

# オブジェクトの依存関係
$(OBJ_DIR)/%.o: $(SRC_DIR)/%$(SUFFIX)
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
		fi
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(DEPENDS) $(EXES)

# DEPENDSのインクルード
-include $(DEPENDS)

# .PHONYターゲット
.PHONY: all clean
