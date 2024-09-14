class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        map<int, int>::iterator it = mpp.begin();

        while(it != mpp.end()){
            if(it->second == 1){
                return it->first;
            }
            it++;
        }
        return -1;
    }
};