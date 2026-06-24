class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        endOfWord = false; 
        for(int i = 0 ; i < 26; i++){
            children[i] = nullptr;
        }
    }
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root; 
        for(char ch : word){
            int i = ch - 'a';
            if(curr -> children[i] == nullptr) {
                curr->children[i] = new TrieNode();
            }

            curr = curr->children[i];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root; 

        for(char ch : word) {
            int i = ch -'a';

            if(curr->children[i] == nullptr) {
                return false; 
            }

            curr = curr->children[i];
        }

        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root; 

        for(char c : prefix){
            int i = c - 'a';
            if(curr->children[i] == nullptr){
                return false; 
            }

            curr = curr->children[i];
        }

        return true;
    }
};
