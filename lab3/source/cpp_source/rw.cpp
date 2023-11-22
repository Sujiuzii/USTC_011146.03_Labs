#include"RBTInsert.h"
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

vector<int>
splitString(const string& input, char delimiter) {
    vector<int> result;
    string::size_type start = 0;
    string::size_type end = input.find(delimiter);

    while (end != string::npos) {
        result.push_back(stoi(input.substr(start, end - start)));
        start = end + 1;
        end = input.find(delimiter, start);
    }
    result.push_back(stoi(input.substr(start, input.size() - start)));
    
    return result;
}

vector<int>
ReadNodes(string filename)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        printf("error");
    }

    int firstLine;
    inputFile >> firstLine;
    string secondLine;
    getline(inputFile >> ws, secondLine);
    vector<int> integerList;
    integerList = splitString(secondLine, ' ');

    inputFile.close();


    return integerList;
}
