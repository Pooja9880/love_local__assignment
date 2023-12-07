#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }

    int mid = nums.size() / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    vector<int> leftSubarray(nums.begin(), nums.begin() + mid);
    vector<int> rightSubarray(nums.begin() + mid + 1, nums.end());

    root->left = sortedArrayToBST(leftSubarray);
    root->right = sortedArrayToBST(rightSubarray);

    return root;
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* result = sortedArrayToBST(nums);

    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(result);

    return 0;
}