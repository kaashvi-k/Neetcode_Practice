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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int mid = it - inorder.begin();

        vector<int> preleftSub(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> inleftSub(inorder.begin(), inorder.begin() + mid);

        root->left = buildTree( preleftSub, inleftSub );

        vector<int> prerightSub(preorder.begin() + mid + 1, preorder.end());
        vector<int> inrightSub(inorder.begin() + mid + 1 , inorder.end()) ;

        root->right = buildTree(prerightSub, inrightSub);

        return root; 

    }
};
