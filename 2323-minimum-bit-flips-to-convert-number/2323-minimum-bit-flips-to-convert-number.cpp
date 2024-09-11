class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start^goal;
        int flips = 0;
        while(res>0){flips=flips +(res&1);
        res>>=1;
        }
        return flips;
    }
};