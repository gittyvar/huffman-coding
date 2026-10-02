#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "encoder.hpp"

using namespace std;

void printMap(map<char, int> freqMap)
{
    for (auto &[key, freq] : freqMap)
    {
        cout << key << ": " << freq << endl;
    }
}

void printHuffmanMap(map<char, string> freqMap)
{
    for (auto &[key, freq] : freqMap)
    {
        cout << key << ": " << freq << endl;
    }
}

int main()
{
    ifstream inputFile("input.txt");

    string line;

    while (getline(inputFile, line))
    {

        mapper(line);
    }

    cout << "Map: " << endl;
    printMap(freqMap);
    cout << endl;
    makeTree();
    cout << "Huffman Map: " << endl;
    printHuffmanMap(huffmanMap);
}