#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include"quicksort.h"

using namespace std;

vector<int> splitString(const string& input, char delimiter) {
    vector<int> result;
    string::size_type start = 0;
    string::size_type end = input.find(delimiter);

    while (end != string::npos) {
        result.push_back(stoi(input.substr(start, end - start)));
        start = end + 1;
        end = input.find(delimiter, start);
    }
    
    return result;
}

vector<int>
ReadArr(string filename)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
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

void
WriteArr(vector<int> &Arr, string filename)
{

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Failed to open the file." << endl;
    }

    for (size_t i = 0; i < Arr.size(); ++i) {
        outputFile << Arr[i];
        
        if (i != Arr.size() - 1) {
            outputFile << " ";
        }
    }

    outputFile.close();
    cout << "Array content has been written to the file " << filename << endl;
}