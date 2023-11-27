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
    double time = 0;
    ofstream fout = ofstream(argv[2]);
    readfile(edges, argv[1]);
    GraphAdjMat g(edges);
    timer.reset();
    g.bfs(0);
    time = timer.elapsed();
    for (int i = 0; i < g.vertexs.size(); ++i){
        if (g.vertexs[i].distance == -1){
            fout << i << " to " << i << ":" << "inf" << endl;
        }
        else{
            fout << i << " to " << i << ":" << g.vertexs[i].distance << endl;
        }
    }
    cout << "bfs: " << time << " us" << endl;
    cout << endl;

    return 0;
}
