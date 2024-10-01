class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        stack<int> st;
        bool ispos = asteroids[0] > 0 ? 1 : 0;
        for(int i = 0; i < asteroids.size(); i++){
            bool iscurp = asteroids[i] > 0 ? 1 : 0, psh = 1, fl = 1;
            if(!iscurp){
                while(st.size() && ispos && st.top() <= abs(asteroids[i])){
                    if(st.top() == abs(asteroids[i])) {
                        psh = 0;
                        st.pop();
                        ispos = st.size() ? st.top() > 0 ? 1 : 0 : 0;
                        fl = 0;
                        break;
                    }
                    st.pop();
                    ispos = st.size() ? st.top() > 0 ? 1 : 0 : 0;
                }
                if(st.size() && st.top() > abs(asteroids[i])) {
                    fl = 0;
                    psh = 0;
                }
            }
            if(fl) ispos = asteroids[i] > 0 ? 1 : 0;
           if(psh) st.push(asteroids[i]);
        }
        while(st.size()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(begin(v),end(v));
        return v;
    }
};