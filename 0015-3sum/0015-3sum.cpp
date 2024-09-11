#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());  // Sort the array
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for `i`
            
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];  // Calculate the sum
                
                if(sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    
                    // Skip duplicates for `l` and `r`
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    
                    l++;
                    r--;
                }
                else if(sum < 0){
                    l++;  // Move the left pointer to increase the sum
                }
                else{
                    r--;  // Move the right pointer to decrease the sum
                }
            }
        }
        return res;
    }
};
