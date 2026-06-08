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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; 
        if(!root) return res; 

        deque<TreeNode*> dq; 
        dq.push_back(root); 


        while(!dq.empty()){
            vector<int> level; 
            int size = dq.size(); 
            for(int i = dq.size(); i > 0; i--){
                TreeNode* node = dq.front(); 
                dq.pop_front(); 
                if(node){
                    level.push_back(node->val); 
                    dq.push_back(node->left);
                    dq.push_back(node->right); 
                }
            }

            if(!level.empty()){
                int n = level.size(); 
                res.push_back(level[n-1]); 
            }


        }

        return res; 
    }
};
