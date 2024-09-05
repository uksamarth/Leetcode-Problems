class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int m = word1.length(), n = word2.length();
        int l=0,r=0;
        while(l<m || r<n){
            if(l<m){
                res.push_back(word1[l]);
                l++;
            }
            if(r<n){
                res.push_back(word2[r]);
                r++;
            }
        }
        return res;
    }
};