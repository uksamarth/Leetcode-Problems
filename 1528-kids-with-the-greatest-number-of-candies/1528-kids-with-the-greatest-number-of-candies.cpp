class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int total = candies.size();
        int maxi = -1;
        for(int i=0;i<total;i++){
            if(candies[i]>maxi){
                maxi = candies[i];
            }
        }
        for(int i=0;i<total;i++){
            if(candies[i]+extraCandies>=maxi){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};