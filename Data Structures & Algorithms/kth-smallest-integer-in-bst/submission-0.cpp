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
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void makeHeap(TreeNode* root){
        if(!root) return; 

        minHeap.push(root->val); 
        makeHeap(root->left);
        makeHeap(root->right);

        return;

    }
    
    int kthSmallest(TreeNode* root, int k) {
        makeHeap(root);

        for(int i = 0 ; i < k-1 ; i++) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
