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

int main()
{
    ifstream inputFile("input.txt");

    string line;

    while (getline(inputFile, line))
    {

        mapper(line);
    }

    printMap(freqMap);
}