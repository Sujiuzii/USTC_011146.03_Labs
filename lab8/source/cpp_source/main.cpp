#include <iostream>
#include <vector>
#include "bfs.h"

using namespace std;

int
main()
{
    Timer timer;
    vector<Edge> edges;
    readfile(edges, "../data/data.txt");
    GraphAdjList g(edges);
    timer.reset();
    g.bfs(0);
    // for (auto v : g.vertexs) {
    //     cout << v.distance << " ";
    // }
    cout << "bfs: " << timer.elapsed() << " us" << endl;
    cout << endl;
    GraphCSR g2(edges);
    timer.reset();
    g2.bfs(0);
    // for (auto v : g2.vertexs) {
    //     cout << v.distance << " ";
    // }
    cout << "bfs: " << timer.elapsed() << " us" << endl;
    cout << endl;

    return 0;
}
