// The solution uses a method called the Aho-Corasick algorithm. Let’s see how it works:

// Building a Trie: We first create a special kind of tree called a ‘trie’ from the patterns we’re looking for. Each pattern is a path in the trie from the root to a node.
// Failure Links: We then add “failure links” to the trie. These links help us jump back efficiently in the trie when a character doesn’t match.
// Searching: We go through the given string, character by character, moving along the paths in the trie. If we reach the end of a path (a pattern), we know that pattern exists in the string.
// Counting: While searching, we keep track of how many times we reach each node (pattern). This tells us how many times each pattern appears in the string.
// This method is fast because it checks all patterns at the same time, instead of one by one.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// The main string and other structures
string mainString;
int totalNodes = 1;              // Start with one node (root)
vector<int> patternFound;        // To store the results for patterns
vector<int> trieAdjList[500005]; // Adjacency list for trie nodes

// TrieNode structure to hold node information
struct TrieNode
{
    int failureLink;            // Failure link for Aho-Corasick
    int child[26] = {};         // Array to hold children (26 alphabets)
    int occurrences = 0;        // Number of occurrences
    vector<int> patternIndices; // Stores indices of patterns
} trie[500005];                 // Maximum of 500005 nodes

// Function to insert a pattern into the trie
void insertPattern(const string &pattern, int patternIndex)
{
    int currentNode = 1; // Start at the root node
    for (char ch : pattern)
    {
        int idx = ch - 'a'; // Convert char to index (0-25)
        if (trie[currentNode].child[idx] == 0)
        {
            trie[currentNode].child[idx] = ++totalNodes; // Create a new node if it doesn't exist
        }
        currentNode = trie[currentNode].child[idx]; // Move to the next node
    }
    trie[currentNode].patternIndices.push_back(patternIndex); // Store the pattern index
}

// Function to build the failure links for Aho-Corasick algorithm
void buildFailureLinks()
{
    queue<int> nodeQueue;
    int rootNode = 1;

    trie[rootNode].failureLink = rootNode; // Root's failure link is itself
    for (int i = 0; i < 26; i++)
    {
        int childNode = trie[rootNode].child[i];
        if (childNode)
        {
            trie[childNode].failureLink = rootNode;
            nodeQueue.push(childNode); // Push child nodes of the root
        }
        else
        {
            trie[rootNode].child[i] = rootNode; // Point missing children to root
        }
    }

    // Build failure links with BFS
    while (!nodeQueue.empty())
    {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        int failureLink = trie[currentNode].failureLink;
        for (int i = 0; i < 26; i++)
        {
            int childNode = trie[currentNode].child[i];
            if (childNode)
            {
                trie[childNode].failureLink = trie[failureLink].child[i];
                nodeQueue.push(childNode);
            }
            else
            {
                trie[currentNode].child[i] = trie[failureLink].child[i];
            }
        }
    }

    // Build adjacency list for failure links
    for (int i = 2; i <= totalNodes; i++)
    {
        trieAdjList[trie[i].failureLink].push_back(i);
    }
}

// Function to run Aho-Corasick on the main string
void runAhoCorasick(const string &s)
{
    int currentNode = 1;
    for (char ch : s)
    {
        currentNode = trie[currentNode].child[ch - 'a']; // Navigate through trie based on the character
        trie[currentNode].occurrences++;                 // Count occurrences
    }
}

// Function to propagate occurrences with DFS
int dfs(int currentNode)
{
    int totalOccurrences = trie[currentNode].occurrences;

    for (int childNode : trieAdjList[currentNode])
    {
        totalOccurrences += dfs(childNode); // Accumulate occurrences recursively
    }

    // Set occurrences for all patterns at this node
    for (int patternIndex : trie[currentNode].patternIndices)
    {
        patternFound[patternIndex] = totalOccurrences;
    }

    return totalOccurrences;
}

// Main function to process input and output results
int main()
{
    // Read the main string from input
    cin >> mainString;
    int k; // Number of patterns
    cin >> k;

    patternFound.resize(k, 0); // Initialize patternFound with size k and default values 0

    vector<string> patterns(k);
    for (int i = 0; i < k; i++)
    {
        cin >> patterns[i];
    }

    // Insert patterns into trie
    for (int i = 0; i < k; i++)
    {
        insertPattern(patterns[i], i);
    }

    // Build failure links
    buildFailureLinks();

    // Run Aho-Corasick algorithm on the main string
    runAhoCorasick(mainString);

    // Propagate occurrences with DFS
    dfs(1);

    // Output results for each pattern
    for (int i = 0; i < k; i++)
    {
        cout << (patternFound[i] > 0 ? "YES" : "NO") << "\n"; // Output "YES" or "NO"
    }

    return 0;
}
