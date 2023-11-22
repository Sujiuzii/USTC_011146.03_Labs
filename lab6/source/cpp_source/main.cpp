#include "huffman.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int
main()
{
    string text;
    string line;
    ifstream myfile("../original.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            text += line;
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file" << endl;
        return 0;
    }

    Huffman h(text);
    h.buildHuffmanTree();
    h.buildCodeTable(h.root, "");
    h.encode();
    h.decode();
    h.getCompressionRatio();

    h.writeEncoded("../encoded.txt");
    h.writeDecoded("../decoded.txt");

    h.printCodeTable();
    cout << "Compression ratio: " << h.compressionRatio << '%' << endl;

    return 0;
}
