#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

unordered_map<char, int> freqm;

Node*
buildHuffmanTree(string text) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters and their frequencies into the priority queue
    // unordered_map<char, int> freq;
    for (char c : text) {
        //only need a-z, A-Z, 0-9, and punctuation(all characters without space, tab, newline)
        if (c == ' ' || c == '\t' || c == '\n') {
            continue;
        }
        freqm[c]++;
    }
    for (auto it : freqm) {
        Node* node = new Node;
        node->data = it.first;
        node->freq = it.second;
        node->left = nullptr;
        node->right = nullptr;
        pq.push(node);
    }

    // Build Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node;
        parent->data = '\0';
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // Root of Huffman tree
    Node* root = pq.top();
    return root;
}


unordered_map<char, string> codes;

void
printHuffmanCodes(Node* root, string code) {
    ofstream file("../table.txt", ios::app);
    if (root == nullptr) {
        return;
    }
    if (root->data != '\0') {
        codes[root->data] = code;
        cout << root->data << ": " << freqm[root->data] << "  " << code << endl;
        file << root->data << ": " << freqm[root->data] << "  " << code << endl;
    }
    file.close();
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

float
getCompressionRatio(string text) {
    // int size = 0;
    // for(auto it : freqm) {
    //     size += it.second;
    // }
    int size = freqm.size();
    int bitlength = (int) log2(size) + 1;
    int originalSize = 0;
    int compressedSize = 0;
    for (auto it : codes) {
        originalSize += bitlength * freqm[it.first];
        compressedSize += it.second.size() * freqm[it.first];
    }
    // return (float) originalSize / compressedSize;
    return (float) compressedSize / originalSize * 100;
}

int
main() {
    // string text = "Huffman coding is a data compression algorithm.";
    // read text from file
    string text;
    ifstream file("../original.txt");
    ofstream file2("../table.txt", ios::trunc);
    file2.close();
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            text += line;
        }
        file.close();
    }
    Node* root = buildHuffmanTree(text);

    printHuffmanCodes(root, "");
    cout << "Compression ratio: " << getCompressionRatio(text) << '%' << endl;
    cout << (int) log2(size(freqm)) + 1 << endl;
    return 0;
}
