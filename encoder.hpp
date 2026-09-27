#include <map>
#include <string>

using namespace std;

map<char, int> freqMap;

void mapper(string line)
{

    int n = line.size();

    for (int i = 0; i < n; i++)
    {
        if (freqMap.find(line[i]) == freqMap.end())
        {
            freqMap[line[i]] = 1;
        }
        else
        {
            freqMap[line[i]]++;
        }
    }
}