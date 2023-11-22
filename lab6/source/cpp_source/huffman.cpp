#include "huffman.h"
#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

/**
 * @brief Build Huffman tree using priority queue.
 * 
 */
void
Huffman::buildHuffmanTree()
{
    priority_queue<Node*, vector<Node*>, Compare> pq;
    unordered_map<char, int> freqmtmp;

    for (char c : text) {
        // Only need a-z, A-Z, 0-9, and punctuation(all characters without space, tab, newline) for this project
        if (c == ' ' || c == '\t' || c == '\n') {
            continue;
        }
        freqmtmp[c]++;
    }
    for (auto it : freqmtmp) {
        Node* node = new Node;
        node->data = it.first;
        node->freq = it.second;
        node->left = nullptr;
        node->right = nullptr;
        pq.push(node);
    }

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
    freqm = freqmtmp;
    root = pq.top();
}

/**
 * @brief Huffman coding for each character. Get code at leaf node.
 * 
 * @param root the root of the current tree
 * @param code current code
 */
void
Huffman::buildCodeTable(Node* root, string code)
{
    // codem.clear();
    if (root == nullptr) {
        return;
    }
    if (root->data != '\0') {
        codem[root->data] = code;
        decodem[code] = root->data;
    }
    buildCodeTable(root->left, code + "0");
    buildCodeTable(root->right, code + "1");
}

/**
 * @brief Get compression ratio.
 * 
 */
void
Huffman::getCompressionRatio()
{
    bitlength = ceil(log2(codem.size()));
    int originalsize = 0;
    int compressedsize = 0;
    for (auto it : codem) {
        originalsize += freqm[it.first] * bitlength;
        // compressedsize += freqm[it.first] * size(it.second);
        compressedsize += freqm[it.first] * codem[it.first].size();
    }
    compressionRatio = (float) compressedsize / originalsize * 100;
}

/**
 * @brief Encode the text.
 * 
 */
void
Huffman::encode()
{
    encoded = "";
    for (char c : text) {
        encoded += codem[c];
    }
}

/**
 * @brief Decode the encoded text.
 * 
 */
void
Huffman::decode()
{
    string code = "";
    decoded = "";
    for (char c : encoded) {
        code += c;
        if (decodem.find(code) != decodem.end()) {
            decoded += decodem[code];
            code = "";
        }
    }
}

/**
 * @brief Write encoded text to file.
 * 
 * @param filename The name of the file to write to
 */
void
Huffman::writeEncoded(string filename)
{
    ofstream file1(filename, ios::trunc);
    file1.close();
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << encoded;
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

/**
 * @brief Write decoded text to file.
 * 
 * @param filename The name of the file to write to
 */
void
Huffman::writeDecoded(string filename)
{
    ofstream file1(filename, ios::trunc);
    file1.close();
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << decoded;
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

/**
 * @brief Print code table to console and file.
 * 
 * @param base 2 to print code to console, 1 to print code to file(default)
 */
void
Huffman::printCodeTable(int base)
{
    if(base == 1){
        ofstream file1("../table.txt", ios::trunc);
        file1.close();
        ofstream file("../table.txt", ios::app);
        if (file.is_open()) {
            for (auto it : codem) {
                
                file << it.first << "    \tfreq: " << freqm[it.first] << "    \tcode: " << it.second << endl;
            }
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
    else if(base == 2){
        for (auto it : codem) {
            cout << it.first << "    \tfreq: " << freqm[it.first] << "    \tcode: " << it.second << endl;
        }
    }
    else{
        cout << "Invalid base" << endl;
    }
}
