class Trie {
public:
    unordered_set<string>st;
    Trie() {
        unordered_set<string>st;
    }
    
    void insert(string word) {
        st.insert(word);
    }
    
    bool search(string word) {
        if(st.find(word)!=st.end()) return 1;
        return 0;
    }
    
    bool startsWith(string prefix) {
        for(string str : st)
            if(str.find(prefix)==0)
                return 1;
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */