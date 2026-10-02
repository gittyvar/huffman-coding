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

void printHuffmanMap(map<char, string> huffmanMap)
{
    for (auto &[key, freq] : huffmanMap)
    {
        cout << key << ": " << freq << endl;
    }
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

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

    inputFile.clear();
    inputFile.seekg(0);

    string lineToEncode;

    for (auto &[key, freq] : huffmanMap)
    {
        outputFile << (int)key << " " << freq << endl;
    }

    while (getline(inputFile, lineToEncode))
    {
        string encodedString = "";
        for (int i = 0; i < lineToEncode.size(); i++)
        {
            encodedString += huffmanMap[lineToEncode[i]];
        }
        outputFile << encodedString;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}