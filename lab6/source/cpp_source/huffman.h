#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief Node for Huffman tree.
 * 
 */
struct Node {
    // character
    char data;
    // frequency
    int freq;
    Node* left;
    Node* right;
};

/**
 * @brief Compare function for priority queue.
 * 
 */
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};



class Huffman {   
public:
string text;
    // frequency map for each character
    unordered_map<char, int> freqm;
    // code map for each character
    unordered_map<char, string> codem;
    // decode map for each code
    unordered_map<string, char> decodem;
    // root of the Huffman tree
    Node* root;
    // encoded text
    string encoded;
    // decoded text
    string decoded;
    // bit length of each character(block code)(default 8)
    int bitlength;
    // compression ratio(percentage)
    float compressionRatio;

    Huffman(string text) : 
    text(text), root(nullptr), compressionRatio(-1), bitlength(8) {};
    ~Huffman() {};
    void buildHuffmanTree();
    void buildCodeTable(Node* root, string code);
    void encode();
    void decode();
    void writeEncoded(string filename);
    void writeDecoded(string filename);
    void printCodeTable(int base = 1);
    void getCompressionRatio();
};


#endif // HUFFMAN_H
