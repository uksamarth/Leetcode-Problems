class Solution {
public:
    bool isPalindrome(int x) {
        // If x is negative or if it ends with 0 (but is not 0), it is not a palindrome
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        // Initialize a variable to store the reverse of the number
        int revNum = 0;

        // Iterate through each digit of the number until it becomes 0
        while (x > revNum) {
            // Extract the last digit of the number
            int ld = x % 10;
            // Build the reverse number by appending the last digit
            // Check for potential overflow before multiplying by 10
            if (revNum > (INT_MAX - ld) / 10) {
                return false;  // Overflow would occur
            }
            revNum = (revNum * 10) + ld;
            // Remove the last digit from the original number
            x = x / 10;
        }

        // Check if the original number is equal to its reverse
        // or if it's equal to the reverse number without the middle digit (in case of odd number of digits)
        return x == revNum || x == revNum / 10;
    }
};
