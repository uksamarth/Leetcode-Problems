class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonzeros = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]!=0){
                nums[nonzeros] = nums[i];
                nonzeros ++;
            }
        }
        for(int i = nonzeros;i<n;i++){
            nums[i] = 0;        }
    }
};