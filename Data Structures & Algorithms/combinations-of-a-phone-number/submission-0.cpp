class Solution {
public:
    vector<string> chars = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"
    };

    string dc;
    vector<string> result; 

    void backtrack(string seq, int i){
        if(seq.size() == dc.size()){
            result.push_back(seq);
            return;
        }

        string chs = chars[dc[i] - '0'];

        for(char c: chs){
            backtrack( seq + c , i+1);
        }

    }

    vector<string> letterCombinations(string digits) {
        dc = digits; 
        if(digits.empty()) return {};
        backtrack({}, 0);
        return result;
        
    }
};
