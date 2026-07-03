class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin() , intervals.end());
        int it = 0 ;
        int n = intervals.size();
        vector<vector<int>> ans; 
        ans.push_back(intervals[0]);

        for(int i = 1 ; i < n ; i++){
            if(ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }

            else{
                ans.back() = 
                    {
                        min(ans.back()[0] , intervals[i][0]) ,
                        max(ans.back()[1] , intervals[i][1])
                    }
                ;
            }
        }


        return ans; 


    }
};
