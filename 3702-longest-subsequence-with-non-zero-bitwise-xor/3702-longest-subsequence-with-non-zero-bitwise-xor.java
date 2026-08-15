class Solution {
    public int longestSubsequence(int[] nums) {
        int totalXor = 0;
        boolean hasNonZero = false;
        
        // Calculate total XOR and check if there are any non-zero elements
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        
        // Case 1: The whole array already has a non-zero XOR
        if (totalXor != 0) {
            return nums.length;
        }
        
        // Case 2: Total XOR is 0, but we can remove one non-zero element
        if (hasNonZero) {
            return nums.length - 1;
        }
        
        // Case 3: Array consists entirely of zeros
        return 0;
    }
}