// The problem can be solved by constructing a suffix tree, which represents all suffixes of the string. Then, we perform a Depth-First Search (DFS) traversal of the suffix tree to find the kth smallest distinct substring.

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

// Define a Node struct representing each node in the suffix tree
struct Node
{
    long long count;          // Number of distinct substrings in the subtree rooted at this node
    int length;               // Length of the longest suffix in the subtree rooted at this node
    int link;                 // Suffix link
    map<char, int> nextNodes; // Next nodes in the trie structure

    // Constructor to initialize node properties
    Node()
    {
        count = 0;
        length = 0;
        link = -1;
    }
};

// Global variables
Node nodes[2 * MAX_N];
int nodeCount, last;
vector<char> result;

// Initialize the suffix tree
void init()
{
    nodes[0].length = 0;
    nodes[0].link = -1;
    nodeCount = 1; // Rename 'size' to 'nodeCount'
    last = 0;
}

// Extend the suffix tree with a new character
void extend(char character)
{
    int current = nodeCount++; // Use 'nodeCount' instead of 'size'
    nodes[current].length = nodes[last].length + 1;
    int previous = last;
    while (previous != -1 && nodes[previous].nextNodes.find(character) == nodes[previous].nextNodes.end())
    {
        nodes[previous].nextNodes[character] = current;
        previous = nodes[previous].link;
    }
    if (previous == -1)
    {
        nodes[current].link = 0;
    }
    else
    {
        int next = nodes[previous].nextNodes[character];
        if (nodes[previous].length + 1 == nodes[next].length)
        {
            nodes[current].link = next;
        }
        else
        {
            int clone = nodeCount++; // Use 'nodeCount' instead of 'size'
            nodes[clone].length = nodes[previous].length + 1;
            nodes[clone].nextNodes = nodes[next].nextNodes;
            nodes[clone].link = nodes[next].link;
            while (previous != -1 && nodes[previous].nextNodes[character] == next)
            {
                nodes[previous].nextNodes[character] = clone;
                previous = nodes[previous].link;
            }
            nodes[next].link = clone;
            nodes[current].link = clone;
        }
    }
    last = current;
}

// Calculate the number of distinct substrings in each subtree
void calculate(int nodeIndex)
{
    nodes[nodeIndex].count = 1; // Initialize the count for the current node
    for (auto &entry : nodes[nodeIndex].nextNodes)
    {
        int nextNodeIndex = entry.second;
        if (nodes[nextNodeIndex].count == 0)
        {
            calculate(nextNodeIndex); // Recursively calculate for child nodes
        }
        nodes[nodeIndex].count += nodes[nextNodeIndex].count;
    }
}

// DFS traversal to find the kth smallest distinct substring
void dfs(int nodeIndex, long long k)
{
    if (k < 0)
        return; // If k is negative, we stop
    for (auto &entry : nodes[nodeIndex].nextNodes)
    {
        char character = entry.first;
        int nextNodeIndex = entry.second;
        if (nodes[nextNodeIndex].count <= k)
        {
            k -= nodes[nextNodeIndex].count; // Subtract the count of this branch
        }
        else
        {
            result.push_back(character); // If we find the desired node, add the character to result
            dfs(nextNodeIndex, k - 1);   // Continue DFS with decremented k
            return;
        }
    }
}

int main()
{
    string inputString;
    cin >> inputString;
    long long kthSmallest;
    cin >> kthSmallest;

    init(); // Initialize the suffix tree
    for (char c : inputString)
    {
        extend(c); // Add each character to the suffix tree
    }

    calculate(0);            // Calculate distinct substrings starting from the root
    dfs(0, kthSmallest - 1); // Find the kth smallest distinct substring

    for (char c : result)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}
