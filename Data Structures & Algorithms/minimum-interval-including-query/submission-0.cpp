class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        vector<pair<int,int>> size(intervals.size()); 
        vector<int> ans; 

        for(int i = 0 ; i < intervals.size() ; i++){
            size[i].second = i ; 
            size[i].first = (intervals[i][1] - intervals[i][0] +1 );
        }

        sort(size.begin() , size.end());

        for(int i = 0 ; i < queries.size() ; i++){
            int curr = queries[i];
            bool found = false; 
            for(int j = 0; j < size.size(); j++){
                
                if( !(curr >= intervals[size[j].second][0] && curr <= intervals[size[j].second][1])) continue;

                else {
                        ans.push_back(size[j].first) ;
                        found = true;
                    break;
                }
            }

            if(!found) ans.push_back(-1);

        }


        return ans; 
    }
};
