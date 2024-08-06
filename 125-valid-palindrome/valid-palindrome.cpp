class Solution {
public:
    // Recursive helper function
    bool pal(int left, int right, const string &s) {
        // Move pointers to the next alphanumeric characters
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        // Base case: If left index is greater or equal to right, it means all characters have been checked
        if (left >= right) return true;

        // Compare characters in a case-insensitive manner
        if (tolower(s[left]) != tolower(s[right])) return false;

        // Recursive case: Move towards the center
        return pal(left + 1, right - 1, s);
    }

    bool isPalindrome(string s) {
        int n = s.size();
        return pal(0, n - 1, s);
    }
};