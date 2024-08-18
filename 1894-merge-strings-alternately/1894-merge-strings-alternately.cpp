class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length() + word2.length();
        string res(n, ' ');  // Initialize a string with n spaces
        int i = 0, j = 0, k = 0;
        
        // Merge characters alternately
        while (i < word1.length() && j < word2.length()) {
            if (k % 2 == 0) {
                res[k++] = word1[i++];
            } else {
                res[k++] = word2[j++];
            }
        }
        
        // Append the remaining characters from word1
        while (i < word1.length()) {
            res[k++] = word1[i++];
        }
        
        // Append the remaining characters from word2
        while (j < word2.length()) {
            res[k++] = word2[j++];
        }
        
        return res;
    }
};
