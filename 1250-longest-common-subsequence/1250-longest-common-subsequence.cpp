class Solution {
public:

    //as i and j dono change ho rahe 
    //2D dp lagega 
    vector<vector<int>> dp;
    int f(string &s1,string &s2,int i,int j)
    {

        //base case
        //if i and j dono string ke bahar toh no subsequence hence return 0
        if(i>=s1.size())
        {
            return 0;
        }
        if(j>=s2.size())
        {
            return 0;
        }
        // dp condtition
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //if the s1[i]==s2[j]
        //then 1+ karke as ek subsequnece mil gaya 
        //i and j ko aage bada 
        if(s1[i]==s2[j])
        {
            return dp[i][j]=1+f(s1,s2,i+1,j+1);
        }

        //if s1[i] != s2[j]
        //toh 2 option hai 
        //we can move i+1 and keep j as it is 
        //or we can keep i as it is and move j+1
        //dono me joh max hoga wo return kardenge 
        else
        {
            return dp[i][j]=max({f(s1,s2,i+1,j),f(s1,s2,i,j+1)});
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        //function call
        //ek i pointer starting at text 1
        //ek j pointer starting at text 2
        dp.clear();
        dp.resize(1005,vector<int>(1005,-1));
        return f(text1,text2,0,0);
    }
};