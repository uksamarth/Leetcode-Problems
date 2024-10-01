// Let's use i = 5 to illustrate how the function works:
// Binary Representation: 5 in binary is 101.
// Function Calls:
// check(5, dp)
// 5 % 2 = 1 (5 is odd, so the least significant bit is 1)
// Now, call check(5 / 2, dp) → check(2, dp)
// 2. check(2, dp)
// 2 % 2 = 0 (2 is even, so the least significant bit is 0)
// Now, call check(2 / 2, dp) → check(1, dp)
// 3. check(1, dp)
// 1 % 2 = 1 (1 is odd, so the least significant bit is 1)
// Now, call check(1 / 2, dp) → check(0, dp)
// 4. check(0, dp)
// Returns 0 (base case)
// Adding Up:
// check(1, dp) returns 1 + check(0, dp) = 1 + 0 = 1
// check(2, dp) returns 0 + check(1, dp) = 0 + 1 = 1
// check(5, dp) returns 1 + check(2, dp) = 1 + 1 = 2

class Solution {
private:
    int  check(int i, vector<int>&dp){
        if(i == 0) return 0 ;
        if(dp[i] != -1) return dp[i];
        dp[i] = (i%2) + check(i/2 , dp);
        return dp[i];
    }
public:
    vector<int> countBits(int n) {
        vector<int>dp(n + 1, -1);
        vector<int>ans(n  + 1 );
        for(int i=0; i<=n; i++){
            ans[i] = check(i, dp);
        }
        return ans; 
        
    }
};

// TABULATION 
