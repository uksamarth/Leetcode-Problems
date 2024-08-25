class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;
        int ans=0;
        for(int i=0;i<n;i++){
            string s1=to_string(nums[i]);
            unordered_map<int,int> mp1;
            mp1[nums[i]]++;
            for(int j=0;j<s1.length();j++){
                for(int k=j+1;k<s1.length();k++){
                    swap(s1[j],s1[k]);
                    mp1[stoi(s1)]++;
                    
                    string s2=s1;
                    for(int l=0;l<s2.length();l++){
                        for(int m=l+1;m<s2.length();m++){
                            swap(s2[l],s2[m]);
                            mp1[stoi(s2)]++;
                            swap(s2[l],s2[m]);
                        }
                    }
                    
                    swap(s1[j],s1[k]);
                }
            }
            for(auto& p:mp1){
                ans+=mp[p.first]-(p.first==nums[i]);
                if(to_string(p.first).length()!=to_string(nums[i]).length()){
                    ans+=mp[p.first]-(p.first==nums[i]);
                }
                // cout<<p.first<<" "<<ans<<"\n";
            }
        }
        // cout<<"\n";
        return ans/2;
    }
};