class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        while(k--){
            int mine = *min_element(nums.begin(),nums.end());
            int idx = -1;
            for(int i=0;i<nums.size();i++){
                if(nums[i] == mine){
                    nums[i] *= mul;
                    break;
                }
            }
        }
        return nums;
    }
};