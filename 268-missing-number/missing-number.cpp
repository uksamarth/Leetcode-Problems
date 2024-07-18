class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2; // Sum of first n natural numbers
        int arraySum = 0;
        
        for (int num : nums) {
            arraySum += num;
        }
        
        return totalSum - arraySum;
    }
};
