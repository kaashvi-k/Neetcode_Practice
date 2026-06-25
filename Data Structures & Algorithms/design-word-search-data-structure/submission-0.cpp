class TrieNode{
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

class WordDictionary {
public:
    TrieNode* root; 
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root; 

        for(char ch : word) {
            int i = ch - 'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new TrieNode();
            }

            curr = curr->children[i];
        }

        curr->endOfWord = true; 
    }

    bool dfs(TrieNode* node, string &word, int index) {

            if (index == word.size())
                return node->endOfWord;

            if (word[index] == '.') {

                for (int i = 0; i < 26; i++) {
                    if (node->children[i] &&
                        dfs(node->children[i], word, index + 1))
                        return true;
                }

                return false;
            }

            int idx = word[index] - 'a';

            if (node->children[idx] == nullptr)
                return false;

            return dfs(node->children[idx], word, index + 1);
}
            
    bool search(string word) { 

        TrieNode* curr = root; 

        return dfs(curr, word, 0);
    }
};
