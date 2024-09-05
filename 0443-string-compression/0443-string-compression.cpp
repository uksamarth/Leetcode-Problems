class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;  // This will track the position to modify in the `chars` vector
        int i = 0;
        
        while (i < n) {
            char current_char = chars[i];
            int count = 0;
            
            // Count the occurrences of the current character
            while (i < n && chars[i] == current_char) {
                i++;
                count++;
            }
            
            // Update the chars vector in place
            chars[idx++] = current_char;  // Add the character
            
            // If count is greater than 1, add the count as well
            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[idx++] = c;  // Add each digit of the count
                }
            }
        }
        
        return idx;  // The new length after compression
    }
};
