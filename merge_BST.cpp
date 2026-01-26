#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* buildFromSortedArray(vector<int>& arr, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildFromSortedArray(arr, start, mid - 1);
        root->right = buildFromSortedArray(arr, mid + 1, end);

        return root;
    }

    TreeNode* buildBST(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;

        inorder(root1, list1);
        inorder(root2, list2);

        vector<int> merged;
        int i = 0, j = 0;

        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j])
                merged.push_back(list1[i++]);
            else
                merged.push_back(list2[j++]);
        }

        while (i < list1.size()) merged.push_back(list1[i++]);
        while (j < list2.size()) merged.push_back(list2[j++]);

        return buildFromSortedArray(merged, 0, merged.size() - 1);
    }
};

// Inorder print to "show" the BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    Solution sol;
    TreeNode* mergedRoot = sol.buildBST(root1, root2);

    cout << "Inorder traversal of merged BST: ";
    printInorder(mergedRoot);

    return 0;
}
