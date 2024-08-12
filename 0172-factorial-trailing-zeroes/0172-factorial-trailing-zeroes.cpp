class Solution {
public:
    int trailingZeroes(int n) {
        int zeros=0;
        while(n>=5){
            n = n/5;
            zeros = zeros+n;
        }
        return zeros;
    }
};