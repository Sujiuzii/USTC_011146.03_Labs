# Lab 4: 区间树上重叠区间的查找算法

PB21020718 曾健斌

## 一、实验内容

编程拓展红黑树使之成为区间树，并实现区间树上重叠区间的查找算法

- 由`insert.txt`文件中给定的区间信息建树
- 输入：需要查找的区间的左端与右端
- 输出：与查找区间重叠的区间

## 二、算法实现

本次实验内容较为简单，主题代码引用`Lab3`中红黑树相关代码，在此基础上在节点上赋予`interval`和`max`两个属性

```c++
typedef struct Interval       // 区间
{
    int low;
    int high;
}*Intervalptr;

struct RBTnode
{
    int max;                 // max为当前子树中最大区间右端
    Intervalptr interval;    // 区间信息，使用interval->low取代原来的key属性
    Color color;
    RBTnode* left;
    RBTnode* right;
    RBTnode* parent;
};
```

修改红黑树初始化函数，为`interval` new 一块新空间

```cpp
void
RBTinit(RBTreeptr T)
{
    T->NIL = new RBTnode;
    T->NIL->color = black;
    T->NIL->interval = new Interval;
    T->root = T->NIL;
    T->root->parent = T->NIL;
}
```

左右旋并不会影响 max 属性，故无需修改

`RBInsert()`和`RBInsertFixup()`算法有小修改，见注释标注处：

```cpp
void
Insert(RBTreeptr T, RBTnodelist z)
{
    RBTnodelist y = T->NIL;
    RBTnodelist x = T->root;
    while (x != T->NIL){
        y = x;
        if (z->interval->low < x->interval->low)    // 使用x->interval->low代替原x->key
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == T->NIL)
        T->root = z;
    else if (z->interval->low < y->interval->low)
        y->left = z;
    else
        y->right = z;
    z->left = T->NIL;
    z->right = T->NIL;
    z->color = red;
    InsertFixup(T, z);
    int tmp = z->max;
    while(z != T->NIL){
        if(tmp >= z->max){
            z->max = tmp;
            z = z->parent;
            continue;
        }
        break;
    }
    return;
}

void
InsertFixup(RBTreeptr T, RBTnodelist z)           // 无需打印出case，删除相关打印语句
{
    RBTnodelist y;
    while(z->parent->color == red){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
            if(y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->right){
                    z = z->parent;
                    LeftRotate(T, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                RightRotate(T, z->parent->parent);
            }
        }
        else{
            y = z->parent->parent->left;
            if(y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else{
                if (z == z->parent->left){
                    z = z->parent;
                    RightRotate(T, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                LeftRotate(T, z->parent->parent);
            }
        }
    }
    T->root->color = black;
}
```

寻找重叠区间的算法：

```cpp
bool
isOverlap(Intervalptr a, Intervalptr b)        // 判断区间是否重叠
{
    return (a->low <= b->high) && (b->low <= a->high);
}

void
IntervalSearch(RBTreeptr T, RBTnodelist x, Intervalptr i)
{
    while(x != T->NIL){
        if(isOverlap(i, x->interval)){         //1
            cout << "(" <<
            x->interval->low << ", " << x->interval->high
            << ")" << endl;
        }
        if(x->left != T->NIL && x->left->max >= i->low){
            x = x->left;
            RBTnodelist y = x->parent->right;
            if(y != T->NIL)         //2
                IntervalSearch(T, y, i);
        } 
        else						//3
            x = x->right;
    }
}
```

此处`IntervalSearch()`旨在检索出所有重叠区间，故与课本给出的算法思路有所差异（该算法旨在得出一个可能存在的重叠区间）

`//1`处将区间是否重叠的条件判断从 while 循环中剥离，使得算法不会在找到第一个区间时停止

`//2`处考虑到区间树搜索算法的特性：当搜索进入右子树时左子树中不可能存在重叠区间，但当搜索进入左子树时，右子树中仍有可能存在未被检索的重叠区间。故此处在进入左子树搜索的同时，对于右子树递归调用`IntervalSearch()`以免漏查。相对的，`//3`处进入右子树时并不需要作相应处理

## 三、实验结果

![image-20231030102946161](/home/zeng/snap/typora/86/.config/Typora/typora-user-images/image-20231030102946161.png)

## 四、复杂度分析

单次查找的时间复杂度为**$O(\min(n,k\log n))$**，下证
- 该算法为$O(n)$，由于算法最多遍历该区间树的每一个节点以判断是否重叠
- 该算法亦为$O(k\log n)$，由于该算法无需重复遍历，故其由于 k 次单区间查询，而由课本相关内容可知，单个重叠区间的查询算法时间复杂度为$O(\log n)$，故该算法的时间复杂度不会超过$O(k\log n)$
- 综上，该算法的时间复杂度为$O(\min(n,k\log n))$


## 五、实验总结

- 本次实验总体上较为简单，实验过程主要是扩展红黑树，并在相应的红黑树操作时维护扩展属性

- 由于红黑树的部分已在`lab3`实现，且课本已给出了区间树的相应实现，所以唯一需要注意的只有如何修改`IntervalSearch()`使其不重不漏地找到所有重叠区间
- 本次实验使我在数据结构的扩展与维护的实现方面有所收获
