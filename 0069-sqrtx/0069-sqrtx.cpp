class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Handle edge cases for 0 and 1

        int l = 1, r = x / 2;
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long square = static_cast<long long>(mid) * mid;  // Use long long to avoid overflow

            if (square == x) {
                return mid;  // Found the exact square root
            } else if (square < x) {
                l = mid + 1;
                result = mid;  // This might be the largest integer whose square is <= x
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
