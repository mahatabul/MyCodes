#include <bits/stdc++.h>
using namespace std;

// --- 1. Node Structure ---
class node
{
public:
    int freq;
    char alp;
    node *left;
    node *right;

    // Default Constructor
    node()
    {
        this->freq = 0;
        this->alp = '\0';
        this->left = nullptr;
        this->right = nullptr;
    }

    // Parameterized Constructor for leaf nodes
    node(int f, char ch)
    {
        this->freq = f;
        this->alp = ch;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// --- 2. Comparator for Min-Heap (Priority Queue) ---
auto comp = [](node *a, node *b)
{
    return a->freq > b->freq;
};

// --- 3. Global Type Alias for Code Pair ---
using CodePair = pair<char, string>;

// --- 4. PreOrder Traversal to Generate Codes ---
void preOrderTraverse(node *root, vector<CodePair> &codes, string s)
{
    if (root == nullptr)
    {
        return;
    }

    // Case 1: Found a leaf node (a character)
    if (root->left == nullptr && root->right == nullptr)
    {
        // Special case: if s is empty (single node tree), use "0"
        codes.push_back({root->alp, s.empty() ? "0" : s});
        return;
    }

    // Recursive Step: Traverse left (append '0') and right (append '1')
    preOrderTraverse(root->left, codes, s + '0');
    preOrderTraverse(root->right, codes, s + '1');
}

// --- 5. Helper Function to Delete Tree (Prevent Memory Leaks) ---
void deleteTree(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// --- 6. Huffman Tree Construction Function ---
node* huffman(const vector<int> &freqArr, vector<CodePair> &codes)
{
    priority_queue<node *, vector<node *>, decltype(comp)> minHeap(comp);

    int n = 0;

    // Step A: Populate the min-heap with initial leaf nodes
    for (int i = 0; i < 26; i++)
    {
        if (freqArr[i] > 0)
        {
            n++;
            node *nd = new node(freqArr[i], char('a' + i));
            minHeap.push(nd);
        }
    }

    // Handle edge case: no characters
    if (n == 0)
    {
        return nullptr;
    }

    // Step B: Build the Huffman Tree
    // Special case: only one unique character
    if (n == 1)
    {
        node *root = minHeap.top();
        // Generate a code for the single character
        preOrderTraverse(root, codes, "");
        return root;
    }

    // General case: more than one unique character
    for (int i = 1; i < n; i++)
    {
        node *x = minHeap.top();
        minHeap.pop();

        node *y = minHeap.top();
        minHeap.pop();

        node *z = new node();
        z->left = x;
        z->right = y;
        z->freq = x->freq + y->freq;

        minHeap.push(z);
    }

    // Step C: Generate Codes
    node *root = minHeap.top();
    preOrderTraverse(root, codes, "");
    
    return root;
}

// --- 7. Character to Code Lookup (Binary Search) ---
string modBS(char x, const vector<CodePair> &codes)
{
    int l = 0;
    int r = codes.size() - 1;
    int mid;
    string code = "";

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (x == codes[mid].first)
        {
            code = codes[mid].second;
            break;
        }
        else if (x < codes[mid].first)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return code;
}

// --- 8. Main Encoding Logic ---
int main()
{
    string text = "aabbcdefg"; // Example text
    string encoded = "";

    // a) Frequency Array Initialization
    vector<int> freqArr(26, 0);
    vector<CodePair> codes;

    // b) Populate Frequency Array
    for (int i = 0; i < text.size(); i++)
    {
        freqArr[text[i] - 'a']++;
    }

    // c) Build Huffman Tree and Generate Codes
    node *root = huffman(freqArr, codes);

    // Check if tree was built
    if (root == nullptr)
    {
        cout << "Error: No characters to encode." << endl;
        return 1;
    }

    // d) Sort Codes by Character (required for binary search)
    sort(codes.begin(), codes.end());

    // e) Print Huffman Codes
    cout << "--- Huffman Codes ---" << endl;
    for (const auto &x : codes)
    {
        cout << x.first << " : " << x.second << endl;
    }
    cout << "---------------------" << endl;

    // f) Encode the Text
    for (const auto &x : text)
    {
        encoded += modBS(x, codes);
    }

    // g) Print Results
    cout << "Original Text: " << text << " (Size: " << text.size() * 8 << " bits)" << endl;
    cout << "Encoded Text: " << encoded << " (Size: " << encoded.size() << " bits)" << endl;
    cout << "Compression Ratio: " << fixed << setprecision(2) 
         << (1.0 - (double)encoded.size() / (text.size() * 8)) * 100 << "%" << endl;

    // h) Clean up memory
    deleteTree(root);

    return 0;
}