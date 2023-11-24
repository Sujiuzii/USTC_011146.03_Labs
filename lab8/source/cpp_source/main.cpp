#include <iostream>
#include <vector>
#include <string>
#include "bfs.h"

using namespace std;

int
main(int argc, char** argv)
{
    Timer timer;
    vector<Edge> edges;
    // string filename;
    readfile(edges, argv[1]);
    cout << "check" << endl;
    GraphAdjList g(edges);
    cout << "check" << endl;
    timer.reset();
    g.bfs(0);
    cout << "check" << endl;
    for (auto v : g.vertexs) {
        cout << v.distance << " ";
    }
    cout << "bfs: " << timer.elapsed() << " us" << endl;
    cout << endl;
    edges.clear();
    readfile(edges, argv[2]);
    // cout << "check" << endl;
    // GraphAdjListDirected g1(edges);
    // cout << "check" << endl;
    // timer.reset();
    // g1.bfs(0);
    // cout << "check" << endl;
    // for (auto v : g1.vertexs) {
    //     cout << v.distance << " ";
    // }
    // cout << "bfs: " << timer.elapsed() << " us" << endl;
    // cout << endl;
    GraphCSR g2(edges);
    timer.reset();
    g2.bfs(0);
    for (auto v : g2.vertexs) {
        cout << v.distance << " ";
    }
    cout << "bfs: " << timer.elapsed() << " us" << endl;
    cout << endl;

    return 0;
}
