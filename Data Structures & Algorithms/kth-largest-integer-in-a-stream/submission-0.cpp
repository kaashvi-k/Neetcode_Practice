class KthLargest {
public:
    priority_queue<int> pq;
    int k ; 

    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        for(int i = 0 ; i < nums.size() ; i++) {
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val); 
        return Kth(pq, this->k); 
    }

    int Kth(priority_queue<int> pq, int k){

        priority_queue<int> copy = pq; 

        for(int i = 0 ; i < k-1; i++) {
            copy.pop(); 
        }

        return copy.top(); 


    }
};
