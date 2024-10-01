class Solution {
public:
    int numTilings(int n) {
        long long ans=1,mod=1e9+7, a=0,b=1,c=1;
        for(int i=2;i<=n;i++){
            ans=c*2+a;
            a=b;
            b=c;
            c=ans%mod;
        }
        return ans%mod;
    }
};