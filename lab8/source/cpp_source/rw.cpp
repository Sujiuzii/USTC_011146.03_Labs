#include "bfs.h"
#include <fstream>

using namespace std;

/**
 * @brief Read graph from file.
 * 
 * @param edges edges of graph
 * @param filename 
 */
void
readfile(vector<Edge> &edges, string filename) {
    ifstream fin(filename);
    int u, v;
    while (fin >> u >> v) {
        Edge e;
        e.u = u;
        e.v = v;
        edges.push_back(e);
    }
}
