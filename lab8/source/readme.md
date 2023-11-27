## 文件结构

* `source/writeup.pdf`、`source/writeup.md`：实验报告
* `source/data/`：实验数据

* `source/twitter_small_bfs`、`source/data_bfs`：实验结果

* `source/cpp_source/`：实验源码
  * `bfs.h`：相关类定义
  * `bfs.cpp`：实验主体部分
  * `timer.cpp`：计时器
  * `rw.cpp`：文件读写
  * `twitter.cpp`、`indirect.cpp`：有向图与无向图分别的测试主函数入口

## 运行

```shell
cd cpp_source
# make
./indirect ../data/data.txt ../data_bfs  # 实验 1
./direct ../data/twitter_small.txt ../twitter_small_bfs  # 实验 2
```


如在 windows 环境出现多个 main 的报错（或是无 make 环境），请手动使用`g++ twitter.cpp bfs.cpp rw.cpp timer.cpp -o direct`与`g++ indirect.cpp bfs.cpp rw.cpp timer.cpp -o indirect`进行编译
