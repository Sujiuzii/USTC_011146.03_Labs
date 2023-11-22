## 文件结构

- `source/writeup.pdf`、`source/writeup.md`：实验报告
- `source/cpp_source/`：实验源码
  1. `optimalscheduling.h`：相关类定义
  2. `optimalscheduling.cpp`：实验主体部分
  3. `main.cpp`：主函数入口
  4. `test*.cpp`：供测试使用
  5. `tests/`：实验用例

## 运行

```shell
cd cpp_source
# make
./main
```

for test: 

```shell
cd cpp_source
make test
```

如在 windows 环境出现多个 main 的报错（或是无 cmake 环境），请手动使用`g++ main.cpp optimalscheduling.cpp rw.cpp timer.cpp -o main`进行编译，或是将`test*.cpp`移出当前工作目录

