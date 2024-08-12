class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int num = x,lastdig;
        while(num>0){
            lastdig = num%10;
            rev = rev*10+lastdig;
            num = num/10;
        }
        if(x==rev){
            return true;
        }
        return false;
    }
};