/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/ */

class Trie {
    class Trie *children[26];
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isEnd = false;
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int index;
        Trie *trie = this;
        for(int i = 0; i < word.size(); i++){
            index = word[i] - 'a';
            if(trie->children[index] == NULL){
                trie->children[index] = new Trie();
            }
            trie = trie->children[index];
        }
        trie->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        Trie *trie = this;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(trie->children[index] == NULL){
                return false;
            }
            trie = trie->children[index];
        }
        return trie != NULL && trie->isEnd == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *trie = this;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] - 'a';
            if(trie->children[index] == NULL){
                return false;
            }
            trie = trie->children[index];
        }
        return trie != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
