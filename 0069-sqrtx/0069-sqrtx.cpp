class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int l =1, r = x/2;
        int result = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long square = static_cast<long long>(mid) *mid;
            if(square == x){
                return mid;
            }
            else if(square<x){
                l = mid+1;
                result = mid;
            }
            else{
                r = mid-1;
            }
        }
        return result;
    }
};