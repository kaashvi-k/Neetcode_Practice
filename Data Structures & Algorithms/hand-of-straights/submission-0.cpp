class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0) return false; 

        unordered_map<int, int> hashset; 

        for(int card: hand ){
            hashset[card] ++;
        }

        sort(hand.begin(), hand.end());

        int curr = 0; 

        for(int card: hand){

            if(hashset[card] == 0) continue; 

            for(int x = card; x < card + groupSize; x++){

                if(hashset[x] == 0) return false; 

                hashset[x] --; 
            }

        }


        return true; 

    }
};
