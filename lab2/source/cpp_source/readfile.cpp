#include"closest_points.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void
ClosestPoints::ReadFile(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    Coordinates.clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int value1;
        float value2, value3;
        if (iss >> value1 >> value2 >> value3) {
            Coordinate tmp;
            tmp.index = value1;
            tmp.x = value2;
            tmp.y = value3;
            Coordinates.push_back(tmp);
        } else {
            cerr << "Invalid line: " << line << endl;
        }
    }
    file.close();
}
