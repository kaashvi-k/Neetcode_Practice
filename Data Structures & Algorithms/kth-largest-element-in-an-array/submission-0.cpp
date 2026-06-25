class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> order; 

        for(int num : nums) {
            order.push(num);
        }

        for(int i = 0 ; i < k - 1 ; i++) {
            order.pop(); 
        }

        return order.top();
    }
};
