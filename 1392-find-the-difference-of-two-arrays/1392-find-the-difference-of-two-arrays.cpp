class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>arr1(2);
        unordered_set<int>a(nums1.begin(),nums1.end());
        unordered_set<int>b(nums2.begin(),nums2.end());
        for(int i:a){
            if(b.find(i)==b.end()){
                arr1[0].push_back(i);
            }
        }
        for(int j:b){
            if(a.find(j)==a.end()){
                arr1[1].push_back(j);
            }
        }
        return arr1;
        
    }
};