class Solution {
private:
    int nextNum(int n){
        int newnum = 0;
        while(n>0){
            int lastdig = n%10;
            newnum = newnum + lastdig*lastdig;
            n = n/10;
        }
        return newnum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = nextNum(n);
        while(fast!=1 && fast!=slow){
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }
        if(fast==1) return 1;
        return 0;
    }
};