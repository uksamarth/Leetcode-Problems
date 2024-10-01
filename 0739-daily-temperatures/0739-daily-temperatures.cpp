class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<int>res(n,0);

        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            int count = 0 ; 
            while(!st.empty())
            {
                if(temp[st.top()]>temp[i])
                {
                    count++;
                    break;
                }
                else
                {
                    count+=res[st.top()];
                    st.pop();
                }
            }

            if(!st.empty() && temp[st.top()]>temp[i])
            res[i] = count ; 
            st.push(i);
        }

        return res;
    }
};