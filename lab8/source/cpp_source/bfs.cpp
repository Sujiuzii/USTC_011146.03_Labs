#include "bfs.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

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

void
GraphAdjList::bfs(int s){
    queue<int> Q;
    vertexs[s].color = GRAY;
    vertexs[s].distance = 0;
    vertexs[s].parent = -1;
    Q.push(s);
    while (!Q.empty()) {
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
