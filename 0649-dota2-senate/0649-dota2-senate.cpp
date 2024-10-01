class Solution {
public:
    string helper(string &s, int count) {
        if(abs(count) >= s.size()) {
            return s[0] == 'D' ? "Dire" : "Radiant";
        }
        string x = "";
        for(auto i : s) {
            if(i == 'R') {
                if(count >= 0) x += 'R';
                count++;
            }else {
                if(count <= 0) x += 'D';
                count--;
            }
        }
        return helper(x, count);

    }
    string predictPartyVictory(string senate) {
        return helper(senate, 0);
    }
};