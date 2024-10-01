class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pass;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++)
        {
            int lo = 0, hi = potions.size() - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if ((long long)spells[i] * potions[mid] >= success)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            pass.push_back(potions.size() - lo);
        }
        return pass;
    }
};