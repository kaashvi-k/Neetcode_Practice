class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq (26, 0); 

        for(char task: tasks) {
            freq[task - 'A'] ++; 
        }

        priority_queue<int> heap; 

        for(int i = 0 ; i < 26 ; i ++) {
           if(freq[i] != 0) heap.push(freq[i]);
        }

        queue< pair<int, int>> schedule; 

        int time = 0; 

        while(!schedule.empty() || !heap.empty()){ 

            while(!schedule.empty() && schedule.front().second == time){
                
                heap.push(schedule.front().first);
                schedule.pop();
            }

            if(heap.empty()) {
                time ++; 
                continue;
            }
            int t = heap.top() ; 
            heap.pop();
            t --; 
            time ++;

            if(t > 0) schedule.push( {t, time + n }); 
        }


        return time;

    }
};
