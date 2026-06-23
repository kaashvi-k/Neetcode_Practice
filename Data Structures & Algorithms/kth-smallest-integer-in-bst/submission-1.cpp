/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> arr;

    void makeVector(TreeNode* node){
        if(!node) return; 

        makeVector(node->left);
        arr.push_back(node->val);
        makeVector(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        makeVector(root); 

        return arr[k-1];
    }
};
