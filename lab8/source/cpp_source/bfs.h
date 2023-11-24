#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

enum color_t { WHITE, GRAY, BLACK };

struct Edge {
    int u, v;
};

struct Vertex {
    color_t color;
    int distance;
    int parent;
};

class GraphAdjList {
public:
    int V, E;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<Vertex> vertexs;

    GraphAdjList(vector<Edge> edges) : V(0), E(edges.size()) {
        for (auto e : edges) {
            this->edges.push_back(e);
            V = max(V, max(e.u, e.v));
        }
        // cout << "V: " << V << endl;
        adj.resize(V);
        for (auto e : edges) {
            adj[e.u - 1].push_back(e.v - 1);
            adj[e.v - 1].push_back(e.u - 1);
        }
        // cout << "check loop2" << endl;
        vertexs.resize(V);
        for (auto i = 0; i < V; i++) {
            vertexs[i].color = WHITE;
            vertexs[i].distance = -1;
            vertexs[i].parent = -1;
        }
        // cout << "check loop3" << endl;
    }
    ~GraphAdjList() {}
    void bfs(int s);
};
class GraphCSR {
public:
    int V, E;
    vector<int> col_index;
    vector<int> row_ptr;
    vector<int> edges;
    vector<Vertex> vertexs;

    // CSR: Compressed Sparse Row
    GraphCSR(vector<Edge> edges){
        for (auto e : edges) {
            this->edges.push_back(e.u - 1);
            this->edges.push_back(e.v - 1);
        }
        V = 0;
        E = edges.size();
        for (auto e : edges) {
            if (e.u > V)
                V = e.u;
            if (e.v > V)
                V = e.v;
        }
        col_index.resize(V + 1);
        row_ptr.resize(V + 1);
        for (auto i = 0; i < V + 1; i++) {
            col_index[i] = 0;
            row_ptr[i] = 0;
        }
        for (auto e : this->edges) {
            col_index[e + 1]++;
        }
        for (auto i = 1; i < V + 1; i++) {
            col_index[i] += col_index[i - 1];
        }
        for (auto i = 0; i < E; i++) {
            row_ptr[this->edges[2 * i]]++;
            row_ptr[this->edges[2 * i + 1]]++;
        }
        for (auto i = 1; i < V + 1; i++) {
            row_ptr[i] += row_ptr[i - 1];
        }
        for (auto i = 0; i < V; i++) {
            Vertex v;
            v.color = WHITE;
            v.distance = -1;
            v.parent = -1;
            vertexs.push_back(v);
        }
    }
    ~GraphCSR() {}
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
