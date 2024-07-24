class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m + n); // Correct size of nums3
        int left = 0, right = 0, index = 0;

        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                nums3[index++] = nums1[left++];
            } else {
                nums3[index++] = nums2[right++];
            }
        }
        
        // Copy remaining elements from nums1
        while (left < m) {
            nums3[index++] = nums1[left++];
        }

        // Copy remaining elements from nums2
        while (right < n) {
            nums3[index++] = nums2[right++];
        }

        // Copy merged elements back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};
