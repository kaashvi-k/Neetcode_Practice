class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> hashset(26, 0);

        for( int i = 0; i < s.size(); i ++ ){

            hashset[ s[i] - 'a' ] = i; 
        }

        vector<int> intervals;
        int size = 0, end = 0; 

        for(int i = 0; i < s.size(); i ++){
            size++;

            end = max(end, hashset[s[i] - 'a']);

            if(i == end){
                intervals.push_back(size);
                size =0;
            }
        }


        return intervals; 

        





        
        
    }
};
