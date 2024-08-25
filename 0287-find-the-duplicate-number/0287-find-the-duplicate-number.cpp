class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0 ;
        int right= nums.size()-1;

        while(left<right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            for(int num:nums){
                if(num<=mid){
                    cnt++;
                }
            }
            if(cnt > mid){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};