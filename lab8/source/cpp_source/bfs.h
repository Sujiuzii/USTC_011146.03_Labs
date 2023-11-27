#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <unordered_map>

using namespace std;

enum color_t { WHITE, GRAY, BLACK };

/**
 * @brief u and v are two vertexs of an edge, for directed edge, u is the source vertex, v is the destination vertex
 * 
 */
struct Edge {
    int u, v;
};

/**
 * @brief vertex for indirected graph
 * 
 */
struct Vertex {
    color_t color;
    int distance;
    int parent;
};

/**
 * @brief adjacent list for directed graph
 * 
 */
struct linklist {
    int v;
    linklist *next;
    linklist *previous;
};

/**
 * @brief vertex for directed graph
 * 
 */
struct VertexAdj {
    color_t color;
    int distance;
    int parent;
    linklist *adjacent;
    int flag;
};

/**
 * @brief Graph represented by adjacent list, for directed graph
 * 
 */
class GraphAdjList {
public:
    // key is vertex index, value is vertex structure
    unordered_map<int, VertexAdj> vertexs;
    int V, E;
    int largestindex = 0;
    vector<Edge> edges;

    /**
     * @brief Construct a new Graph Adj List object
     * 
     * @param edges edges of the graph
     */
    GraphAdjList(vector<Edge> edges) : V(0), E(edges.size()) {
        for (auto e : edges) {
            this->edges.push_back(e);
        }
        for (auto e : edges) {
<<<<<<< HEAD
            if (max(e.u, e.v) > largestindex) {
                largestindex = max(e.u, e.v);
            }
=======
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
            if (vertexs.find(e.u) == vertexs.end()) {
                vertexs[e.u].color = WHITE;
                vertexs[e.u].distance = -1;
                vertexs[e.u].parent = -1;
                vertexs[e.u].adjacent = new linklist;
                vertexs[e.u].adjacent->previous = vertexs[e.u].adjacent;
                vertexs[e.u].adjacent->next = new linklist;
                vertexs[e.u].adjacent->next->v = e.v;
                if (vertexs.find(e.v) == vertexs.end()) {
                    vertexs[e.v].color = WHITE;
                    vertexs[e.v].distance = -1;
                    vertexs[e.v].parent = -1;
                    vertexs[e.v].adjacent = new linklist;
                    vertexs[e.v].adjacent->previous = vertexs[e.v].adjacent;
                    vertexs[e.v].adjacent->next = nullptr;
                    V++;
                    vertexs[e.v].flag = 0;
                }
                vertexs[e.u].adjacent->next->previous = vertexs[e.u].adjacent;
                vertexs[e.u].adjacent->next->next = nullptr;
                vertexs[e.u].flag = 0;
                V++;
            }
            else {
<<<<<<< HEAD
                int fg = 0;
=======
                int fg=0;
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
                linklist *p = vertexs[e.u].adjacent;
                while (p->next != nullptr) {
                    p = p->next;
                    if (p->v == e.v) {
                        fg = 1;
                        break;
                    }
                }
                if (!fg) {
                    p->next = new linklist;
                    p->next->v = e.v;
                    if (vertexs.find(e.v) == vertexs.end()) {
                        vertexs[e.v].color = WHITE;
                        vertexs[e.v].distance = -1;
                        vertexs[e.v].parent = -1;
                        vertexs[e.v].adjacent = new linklist;
                        vertexs[e.v].adjacent->previous = vertexs[e.v].adjacent;
                        vertexs[e.v].adjacent->next = nullptr;
<<<<<<< HEAD
                        vertexs[e.v].flag = 0;
=======
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
                        V++;
                    }
                    p->next->previous = p;
                    p->next->next = nullptr;
                }
            }
        }
    }
    ~GraphAdjList(){}
    /**
     * @brief bfs
     * 
     * @param s start vertex
     */
    void bfs(int s);
};

/**
 * @brief Graph represented by adjacent matrix, for indirected graph
 * 
 */
class GraphAdjMat {
public:
    int V, E;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<Vertex> vertexs;

    /**
     * @brief Construct a new Graph Adj Mat object
     * 
     * @param edges edges of the graph
     */
    GraphAdjMat(vector<Edge> edges) : V(0), E(edges.size()) {
        for (auto e : edges) {
            this->edges.push_back(e);
            V = max(V, max(e.u, e.v));
        }
        adj.resize(V);
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
    /**
     * @brief bfs
     * 
     * @param s start vertex
     */
    void bfs(int s);
};

void readfile(vector<Edge> &edges, string filename);

/**
 * @brief timer for performance test
 * 
 */
class Timer {
public:
    /**
     * @brief Construct a new Timer object
     * 
     */
    Timer() : start_(chrono::high_resolution_clock::now()) {}
    ~Timer() {}
    /**
     * @brief Reset timer
     * 
     */
    void reset();
    /**
     * @brief Get elapsed time
     * 
     * @return Elapsed time in microseconds(us)
     */
    double elapsed() const;

private:
    // start time
    chrono::time_point<chrono::high_resolution_clock> start_;
};

#endif // BFS_H
