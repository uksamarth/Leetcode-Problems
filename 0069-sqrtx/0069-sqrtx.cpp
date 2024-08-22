class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Handle edge cases for 0 and 1

        int left = 1, right = x / 2;  // Initialize search bounds
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long midSquare = static_cast<long long>(mid) * mid;  // Avoid overflow

            if (midSquare == x) {
                return mid;  // Found the exact square root
            } else if (midSquare < x) {
                left = mid + 1;
                result = mid;  // Update result to the current mid
            } else {
                right = mid - 1;
            }
        }

        return result;  // Result holds the integer part of the square root
    }
};
