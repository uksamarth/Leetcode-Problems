#include <limits>

class Solution {
public:
    int reverse(int x) {
        int revn = 0;
        while (x != 0) {
            int last = x % 10;
            x = x / 10;

            // Check for overflow before multiplying and adding
            if (revn > std::numeric_limits<int>::max() / 10 || 
                (revn == std::numeric_limits<int>::max() / 10 && last > 7)) return 0;
            if (revn < std::numeric_limits<int>::min() / 10 || 
                (revn == std::numeric_limits<int>::min() / 10 && last < -8)) return 0;

            revn = revn * 10 + last;
        }

        return revn;
    }
};
