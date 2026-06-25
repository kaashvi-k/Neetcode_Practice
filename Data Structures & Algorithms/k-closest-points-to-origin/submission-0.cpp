class Node{
    public: 
    int dist; 
    int row; 
    int col; 

    Node() {
        dist = 0; 
        row = 0; 
        col = 0; 
    }

    bool operator<(const Node& other) const {
        return dist > other.dist; 
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<Node> distances; 
        
        for(vector<int> coords : points) {

            Node node;

            node.row = coords[0]; 
            node.col = coords[1]; 

            node.dist =  node.row*node.row + node.col*node.col ;

            distances.push(node);
        }

        vector<vector<int>> ans ; 

        for( int i = 0 ; i < k ; i++) {
            Node curr = distances.top() ;
            distances.pop();
            ans.push_back({curr.row , curr.col});
        }

        return ans; 
    }
};
