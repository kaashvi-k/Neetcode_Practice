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
    bool Valid(TreeNode* node, int left, int right) {
        if(node == NULL) return true;

        if(node->val <= left || node->val >= right ) return false; 

        return Valid(node->left, left, node->val) && Valid(node->right, node->val, right);




    }
    bool isValidBST(TreeNode* root) {
        return Valid(root, INT_MIN, INT_MAX);
    }
};
