class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int> > order; 

        for(int num : nums) {
            order.push(num);
            if(order.size() > k) order.pop() ;
        }

        return order.top();
    }
};
