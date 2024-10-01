class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        bitset<32> nc(c);
        bitset<32> nb(b);
        bitset<32> na(a);

        int cnt=0;
        int maxn = max(a,max(b,c));
        maxn = ceil(log2(maxn));

        for(int i=0 ; i<=maxn ;i++)
        {
            if((na[i] || nb[i]) == nc[i]) 
                continue;
            else if(nc[i]==0 && na[i] && nb[i]){
                cnt+=2;
            }   
            else{
                cnt++; 
            }  
        }

        return cnt;
    }
};