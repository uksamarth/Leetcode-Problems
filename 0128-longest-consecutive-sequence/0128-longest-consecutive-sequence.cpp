class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int prev_cnt = 1, cur_cnt=1;
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]){
                continue;
            }
            else if(nums[i-1]+1== nums[i]){
                cur_cnt++;
            }
            else{
                prev_cnt = max(prev_cnt,cur_cnt);
                cur_cnt = 1;
            }
        }

        return max(cur_cnt,prev_cnt);

    }
};