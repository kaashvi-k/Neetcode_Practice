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
    int search(TreeNode* node, int maxVal){
        if(node == NULL) return 0; 
        
        int good; 
        if(node->val >= maxVal) good = 1 ;
        else good = 0; 
        
        maxVal = max(maxVal, node->val);
        good = good + search(node->left, maxVal) + search(node->right, maxVal);

        return good; 
    
    }
    int goodNodes(TreeNode* root) {
        return search(root, root->val);
    }
};
