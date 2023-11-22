## 文件结构

- `source/writeup.pdf`、`source/writeup.md`：实验报告
- `source/original.txt`：原文本
- `source/table.txt `：Huffman编码对应表
- `source/encoded.txt`、`source/decoded.txt`：对原文本的编码以及解码
- `source/cpp_source/`：实验源码
  1. `huffman.h`：相关结构体以及类定义
  2. `huffman.cpp`：实验主体部分
  3. `main.cpp`：主函数入口
  4. `huffmantest.cpp`：供测试方便使用

## 运行

```shell
cd cpp_source
make
./main
```

程序默认只打印压缩率而将编码表输入文件，若欲将编码表输出至 console ：

```shell
cd cpp_source
make test
./test
```

如在 windows 环境出现多个 main 的报错（或是无 cmake 环境），请手动使用`g++ main.cpp huffman.cpp -o main`，或是将`huffmantest.cpp`移出当前工作目录

