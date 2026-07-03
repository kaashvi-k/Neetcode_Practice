class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin() , intervals.end());
        int count = 0 ; 
        int n = intervals.size();

        int curr = 0; 

        for(int i = 1; i < n ; i ++){
            if(intervals[curr][1] <= intervals[i][0]){
                curr = i ; 
                continue; 
            }

            else {
                if(intervals[i][1] < intervals[curr][1]) {
                    curr = i; 
                }
                count ++;
            }
        }

        return count;
    }
};
