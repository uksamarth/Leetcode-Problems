class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for(char c: s){
            int num = c - 'a'+1;
            while(num>0){
                int last = num%10;
                res +=last;
                num/=10;
            }
        }
        k = k-1;
        while(k--){
            int new_res=0;
            while(res>0){
                new_res +=res%10;
                res/=10;
            }
            res = new_res;
        }
        return res;
    }
};