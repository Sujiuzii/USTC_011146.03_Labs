#include "bfs.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

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
GraphCSR::bfs(int s){
    queue<int> Q;
    vertexs[s].color = GRAY;
    vertexs[s].distance = 0;
    vertexs[s].parent = -1;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto i = col_index[u]; i < col_index[u + 1]; i++) {
            int v = edges[i];
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
