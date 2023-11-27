#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "bfs.h"

using namespace std;

int
main(int argc, char** argv)
{
    Timer timer;
    vector<Edge> edges;
<<<<<<< HEAD
    cout << "checking input file..." << endl;
    readfile(edges, argv[1]);
    cout << "input file checked" << endl;
=======
    readfile(edges, argv[1]);
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
    GraphAdjList g(edges);
    int start = -1;
    double time = 0;
    int count = 1;
    ofstream fout = ofstream(argv[2]);
    fout << "vertex distance for file " << argv[1] << endl;
    fout << "vertex #: " << g.V << endl;
    fout << "edge #: " << g.E << endl;
<<<<<<< HEAD
    // cout << g.largestindex << endl;
    for (int i = 0; i < g.largestindex; i++) {
=======
    for (int i = 0; i < g.vertexs.size(); i++) {
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
        if (g.vertexs.find(i) != g.vertexs.end()) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        cout << "start vertex not found" << endl;
        return 0;
    }
    timer.reset();
    g.bfs(start);
    time = timer.elapsed();
    for (auto v : g.vertexs) {
        if (v.second.flag == start){
            fout << start << " to " << v.first << ":" << v.second.distance << endl;
            count++;
        }
    }
    while (count != g.V) {
<<<<<<< HEAD
        timer.reset();
=======
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
        for (auto v : g.vertexs) {
            if (v.second.flag != start) {
                start = v.first;
                count++;
                break;
            }
        }
<<<<<<< HEAD
=======
        timer.reset();
>>>>>>> 1e3791873ae206343f3610f3f933b7dd4c9367ea
        g.bfs(start);
        time += timer.elapsed();
        for (auto v : g.vertexs) {
            if (v.second.flag == start){
                fout << start << " to " << v.first << ":" << v.second.distance << endl;
                count++;
            }
        }
    }
    cout << "bfs: " << time/1000 << " ms" << endl;
    cout << endl;

    return 0;
}
