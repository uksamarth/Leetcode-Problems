class Solution {
public:
    string mergeAlternately(string str1, string str2) {
        int i=0,j=0,k=0;
        int n = str1.length()+str2.length();
        string res(n, ' ');
        while(i<str1.length() && j<str2.length()){
            if(k%2==0){
                res[k++] = str1[i++];
            }
            else{
                res[k++] = str2[j++];
            }
        }
        while(i<str1.length()){
            res[k++] = str1[i++];
        }
        while(j<str2.length()){
            res[k++] = str2[j++];
        }
        return res;
    }
};