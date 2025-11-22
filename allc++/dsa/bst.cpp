#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left = nullptr;
    node *right = nullptr;
};

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *r, vector<int> &k)
{
    if (r == NULL)
    {
        return;
    }
    inorder(r->left, k);
    k.push_back(r->data);

    inorder(r->right, k);
}
void preorder(TreeNode *r, vector<int> &k)
{
    if (r == NULL)
    {
        return;
    }
    k.push_back(r->data);
    preorder(r->left, k);
    preorder(r->right, k);
}
void pstorder(TreeNode *r, vector<int> &k)
{
    if (r == NULL)
    {
        return;
    }
    pstorder(r->left, k);

    pstorder(r->right, k);
    k.push_back(r->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> k1, k2, k3;

    inorder(root, k1);
    preorder(root, k2);
    pstorder(root, k3);
    ans.push_back(k1);
    ans.push_back(k2);
    ans.push_back(k3);

    return ans;
}

// vector<vector<int>> levelOrder(TreeNode *root)
// {
//     queue<TreeNode *>q;
//     vector<vector<int>>ans;
//     if (!root) return ans;

//     q.push(root);

//     while (!q.empty())
//     {
//         vector<int>temp;
//         int size = q.size();

//         for (int i = 0; i < size; i++)
//         {
//             TreeNode *n = q.front();
//             q.pop();

//             if (n->left!=nullptr)
//             {
//                 q.push(n->left);
//             }
//             if (n->right!=nullptr)
//             {
//                 q.push(n->right);
//             }
//             temp.push_back(n->val);
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }
int main()
{

    node *r = new node();
    node *ltree = new node();
    node *rtree = new node();
    r->data = 1;
    r->left = ltree;
    r->right = rtree;
    ltree->data = 0;
    rtree->data = 2;

    return 0;
}