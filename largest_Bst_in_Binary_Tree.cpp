#include <climits>
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Info {
public:
    bool isBST;
    int size;
    int minVal;
    int maxVal;
    int ans;
};

class Solution {
public:
    Info largestBSTUtil(Node* root) {
        // Base case
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN, 0};
        }

        // Leaf node
        if (!root->left && !root->right) {
            return {true, 1, root->data, root->data, 1};
        }

        // Recur for left and right
        Info left = largestBSTUtil(root->left);
        Info right = largestBSTUtil(root->right);

        Info curr;

        // Check BST condition
        if (left.isBST && right.isBST &&
            left.maxVal < root->data &&
            root->data < right.minVal) {

            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(left.minVal, root->data);
            curr.maxVal = max(right.maxVal, root->data);
            curr.ans = curr.size;
        } else {
            curr.isBST = false;
            curr.ans = max(left.ans, right.ans);
        }

        return curr;
    }

    int largestBST(Node* root) {
        return largestBSTUtil(root).ans;
    }
};
