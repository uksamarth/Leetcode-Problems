class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mpp;
        for(char c: s){
            mpp[c]++;
        }
        for(char c: t){
            mpp[c]--;
            if(mpp[c]<0){
                return c;
            }
        }
        return '\0';
    }
};