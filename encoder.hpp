#include <map>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
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

vector<pair<int, char>> freqPairs;

struct Node
{
    char c;
    int freq;
    Node *left;
    Node *right;
};

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printTree(root->left);
    cout << root->c << ": " << root->freq << endl;
    printTree(root->right);
}

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

map<char, string> huffmanMap;

void generateCodes(Node *root, string code)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        huffmanMap[root->c] = code;
        // cout << root->c << ": " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");

    generateCodes(root->right, code + "1");
}

void makeTree()
{
    // making pairs
    for (auto &[key, value] : freqMap)
    {
        freqPairs.push_back({value, key});
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;

    // making nodes and pushing into min heap
    for (int i = 0; i < freqPairs.size(); i++)
    {
        Node *node = new Node;

        node->freq = freqPairs[i].first;
        node->c = freqPairs[i].second;
        node->left = NULL;
        node->right = NULL;

        pq.push(node);
    }

    // making the tree
    while (pq.size() != 1)
    {
        Node *n1 = pq.top();
        pq.pop();
        Node *n2 = pq.top();
        pq.pop();

        Node *newNode = new Node;
        newNode->freq = n1->freq + n2->freq;
        newNode->c = '\0';
        newNode->left = n1;
        newNode->right = n2;

        pq.push(newNode);
    }

    Node *root = pq.top();

    cout << "Inorder Traversal of a valid Huffman Tree: " << endl;
    printTree(root);
    cout << endl;
    // cout << "The Codes: " << endl;
    generateCodes(root, "");
}