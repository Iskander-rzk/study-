#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency; // Min-heap (smallest frequency at the top)
    }
};

// Function to build the Huffman tree
Node* buildHuffmanTree(map<char, int> &frequencies) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    // Add all characters and their frequencies to the priority queue
    for (auto it : frequencies) {
        pq.push(new Node(it.first, it.second));
    }

    // Combine nodes until only one node remains (the root)
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new node with combined frequency
        Node* parent = new Node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

// Function to generate Huffman codes for each character
map<char, string> generateCodes(Node* root) {
    map<char, string> codes;
    string code = "";

    // Recursive function to traverse the tree and generate codes
    function<void(Node*, string)> traverse = [&](Node* node, string code) {
        if (node == nullptr) {
            return;
        }

        if (node->character != '\0') {
            codes[node->character] = code;
        }
        traverse(node->left, code + "0");
        traverse(node->right, code + "1");
    };

    traverse(root, code);
    return codes;
}

int main() {
    // Example frequencies (you can replace these with your own)
    map<char, int> frequencies = {
        {'a', 45},
        {'b', 13},
        {'c', 12},
        {'d', 16},
        {'e', 9},
        {'f', 5},
    };

    // Build the Huffman tree
    Node* root = buildHuffmanTree(frequencies);

    // Generate Huffman codes
    map<char, string> codes = generateCodes(root);

    // Print the codes
    cout << "Huffman Codes:" << endl;
    for (auto it : codes) {
        cout << it.first << ": " << it.second << endl;
    }

    // Clean up the tree (delete nodes)
    function<void(Node*)> cleanup = [&](Node* node) {
        if (node == nullptr) {
            return;
        }
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    };

    cleanup(root);

    return 0;
}
