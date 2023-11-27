# Lab 8:  图搜索 BFS 算法及存储优化

PB21020718 曾健斌

## 一、实验内容

针对图,根据给定的数据选择合适的存储方式(邻接矩阵和邻接表中的一种)进行存储，并进行图的广度优先遍历的过程。

**数据集 1**：使用 `data.txt` 中的数据，看做无向图，选择合适的方式进行存储(提示:其特征为节点数较少而边比较密集)，并以 A 为起始顶点输出遍历过程。

**数据集 2**： twitter 真实数据集,数据集规模如下:
twitter_small: Nodes 81306, Edges 1768149, 有向图;
twitter_large: Nodes 11316811, Edges 85331846, 有向图。
对 twitter_small,选择一种合适的存储方式存储数据,并输出 BFS 的遍历时间。twitter_large 不做要求。
提示:图可能不是连通图,且可能有重复边。



## 二、算法实现

### 相关结构体与枚举类


```cpp
// bfs颜色
enum color_t { WHITE, GRAY, BLACK };

// 边结构体，用于构造器，本实现中有向边与无向边均使用该结构体
struct Edge {
    int u, v;
};

// 无向图邻接矩阵实现中使用的结构体，后续将使用它实例化二重vector
struct Vertex {
    color_t color;
    int distance;
    int parent;
};

// 链表，用于邻接链表实现中作为邻接链表
struct linklist {
    int v;
    linklist *next;
    linklist *previous;
};

// 在邻接链表实现中作为顶点序列
struct VertexAdj {
    color_t color;
    int distance;
    int parent;
    linklist *adjacent;
    int flag;  // flag字段为考虑到可能有多个连通子图设立的字段
};
```

### 邻接链表实现

```cpp
class GraphAdjList {
public:
    // 用于顶点检索，使用无序的哈希map提高效率
    unordered_map<int, VertexAdj> vertexs;
    int V, E;
    vector<Edge> edges;
    // 构造器，本实现构造器比较繁琐
    GraphAdjList(vector<Edge> edges) : V(0), E(edges.size()) {
        for (auto e : edges) {
            this->edges.push_back(e);
        }
        // 对每一条边进行以下考虑
        for (auto e : edges) {
            if (vertexs.find(e.u) == vertexs.end()) { // 若该顶点已存在
                vertexs[e.u].color = WHITE;
                vertexs[e.u].distance = -1;
                vertexs[e.u].parent = -1;
                vertexs[e.u].adjacent = new linklist;
                vertexs[e.u].adjacent->previous = vertexs[e.u].adjacent;
                vertexs[e.u].adjacent->next = new linklist;
                vertexs[e.u].adjacent->next->v = e.v;
                if (vertexs.find(e.v) == vertexs.end()) { // 判断边的尾结点是否存在
                    vertexs[e.v].color = WHITE;
                    vertexs[e.v].distance = -1;
                    vertexs[e.v].parent = -1;
                    vertexs[e.v].adjacent = new linklist;
                    vertexs[e.v].adjacent->previous = vertexs[e.v].adjacent;
                    vertexs[e.v].adjacent->next = nullptr;
                    V++;
                    vertexs[e.v].flag = 0; // 初始化为0,后续用于存储bfs源点值
                }
                // 维护邻接链表
                vertexs[e.u].adjacent->next->previous = vertexs[e.u].adjacent;
                vertexs[e.u].adjacent->next->next = nullptr;
                vertexs[e.u].flag = 0;
                V++;
            }
            else { // 顶点已存在则直接修改邻接链
                int fg = 0;  // fg是考虑到重复边设置的标志位
                linklist *p = vertexs[e.u].adjacent;
                while (p->next != nullptr) {
                    p = p->next;
                    if (p->v == e.v) {  // 判断为重复边，放弃该边
                        fg = 1;
                        break;
                    }
                }
                if (!fg) {
                    p->next = new linklist;
                    p->next->v = e.v;
                    if (vertexs.find(e.v) == vertexs.end()) {  // 同样判断尾结点是否存在
                        vertexs[e.v].color = WHITE;
                        vertexs[e.v].distance = -1;
                        vertexs[e.v].parent = -1;
                        vertexs[e.v].adjacent = new linklist;
                        vertexs[e.v].adjacent->previous = vertexs[e.v].adjacent;
                        vertexs[e.v].adjacent->next = nullptr;
                        vertexs[e.v].flag = 0;
                        V++;
                    }
                    p->next->previous = p;
                    p->next->next = nullptr;
                }
            }
        }
    }
    ~GraphAdjList(){}
    void bfs(int s);
};
```

###  bfs 实现（邻接链表）

```cpp
void
GraphAdjList::bfs(int s){
    queue<int> Q;  // 用于bfs的队列
    vertexs[s].color = GRAY;
    vertexs[s].distance = 0;
    vertexs[s].parent = -1;
    Q.push(s);
    while (!Q.empty()) {  // 重复入队出队涂色等操作实现bfs
        int u = Q.front();
        Q.pop();
        for (linklist *tmp = vertexs[u].adjacent; tmp->next != nullptr;) {
            tmp = tmp->next;
            if (vertexs[tmp->v].color == WHITE) {
                vertexs[tmp->v].color = GRAY;
                vertexs[tmp->v].distance = vertexs[u].distance + 1;
                vertexs[tmp->v].parent = u;
                vertexs[tmp->v].flag = s;
                Q.push(tmp->v);
            }
        }
        vertexs[u].color = BLACK;
    }
}
```

### 邻接矩阵实现

```cpp
class GraphAdjMat {
public:
    int V, E;
    vector<Edge> edges;
    vector<vector<int>> adj; // 维护一个二维邻接矩阵
    vector<Vertex> vertexs;
	
    // 邻接矩阵实现的构造器相对简单，需要注意的是动态维护矩阵大小
    GraphAdjMat(vector<Edge> edges) : V(0), E(edges.size()) {
        for (auto e : edges) {
            this->edges.push_back(e);
            V = max(V, max(e.u, e.v)); // 维护最大顶点序号
        }
        adj.resize(V);  // 维护矩阵大小
        for (auto e : edges) {
            adj[e.u - 1].push_back(e.v - 1);
            adj[e.v - 1].push_back(e.u - 1);
        }
        vertexs.resize(V);
        for (auto i = 0; i < V; i++) {
            vertexs[i].color = WHITE;
            vertexs[i].distance = -1;
            vertexs[i].parent = -1;
        }
    }
    ~GraphAdjMat() {}
    void bfs(int s);
};
```

###  bfs 实现（邻接矩阵）

```cpp
// 此bfs与邻接链表处的实现思路一致，不再多言
void
GraphAdjMat::bfs(int s){
    queue<int> Q;
    vertexs[s].color = GRAY;
    vertexs[s].distance = 0;
    vertexs[s].parent = -1;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : adj[u]) {
            if (vertexs[v].color == WHITE) {
                vertexs[v].color = GRAY;
                vertexs[v].distance = vertexs[u].distance + 1;
                vertexs[v].parent = u;
                Q.push(v);
            }
        }
        vertexs[u].color = BLACK;
    }
}
```



## 三、实验结果

两个数据集耗时：

![time](../../../../snap/typora/86/.config/Typora/typora-user-images/image-20231127185602938.png)

输出 bfs 结果至文件

![assignment1](../../../../snap/typora/86/.config/Typora/typora-user-images/image-20231127185641178.png)

![assignment2](../../../../snap/typora/86/.config/Typora/typora-user-images/image-20231127185702554.png)

其中数据集 twitter_small 有两个连通分量

![connectedcomponents](../../../../snap/typora/86/.config/Typora/typora-user-images/image-20231127185719277.png)



## 四、实验总结

本次实验中邻接矩阵的实现较为简单，而邻接链表的实现相对复杂

- 领接矩阵使用二重 vector 实现
- 领接链表使用 unordered_map 与链表结构体实现，构造器较为复杂，但是在降低时间成本上颇有效果

关于存储方式选择的考虑

- 对于比较小的数据集使用邻接矩阵，因为该存储方式比较简单，而且由于数据点序号密集，我使用了与最大序号一样大小的矩阵
- 但是在对 twitter_small 的实验中，以上实现会把内存跑爆
- 对于后者，由于其边比较稀疏，且顶点数大，顶点序号分散的情况，采用邻接链表实现显然是更好的选择
