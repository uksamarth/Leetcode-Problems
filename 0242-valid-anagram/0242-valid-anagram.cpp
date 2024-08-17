class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.length()!=t.length()) return false;
        for(char c: s) mp[c]++;
        for(char c: t) mp[c]--;
        for(auto it: mp){
            if(it.second!=0) return false;
        }
        return true;
        
    }
};