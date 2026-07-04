/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts; 
        vector<int> ends; 

        for(int i = 0 ; i < intervals.size(); i++){
            starts.push_back(intervals[i].start);
            ends.push_back(intervals[i].end);
        }

        int s = 0; 
        int e = 0;

        int res = 0, count = 0; 

        sort(starts.begin(), starts.end());
        sort(ends.begin() , ends.end());

        while(s < intervals.size()){
            if(starts[s] < ends[e]) {
                s++;
                count ++; 
            }

            else {
                e++;
                count--;
            }

            res = max(res, count);

        }


        return res; 
        
    }
};
