class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res {0};
        auto it = prices.cbegin() + 1;
        while (true) {
            //Find local minimum of the prices:
            while (it != prices.cend() && *it <= *(it - 1)) ++it;
            if (it == prices.cend()) break;
           
            int min = *(it - 1);
            int max = *it;
            //Find gap down bigger than fee:
            while (++it != prices.cend() && max - *it < fee) {
                if (*it < min) min = *it;
                if (*it > max) max = *it;
            }
            
            //Add the transaction iff it's profitable:
            int diff = max - min - fee;
            if (diff > 0) res += diff;
        }
        return res;
    }
};