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
    int maxSum = INT_MIN; 
    int PathCalc(TreeNode * root){
        if(!root) return 0;

        int left = PathCalc(root->left);
        int right = PathCalc(root->right);

        maxSum = max( {maxSum, root->val + left, root->val + right, root->val + left + right } );
        return max( 0, root->val + max(left, right) ); 
    }
    
    int maxPathSum(TreeNode* root) {
        PathCalc(root);
        return maxSum; 
    }
};
