class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights; 

        for(int weight : stones) {
            weights.push(weight);
        }

        while(weights.size() > 1){
            int x = weights.top();
            weights.pop();
            int y = weights.top();
            weights.pop();

            weights.push(x-y);
        }

        if(weights.size() == 1) {
            int ans = weights.top();
            return ans;
        }
        else return 0;
    }
};
