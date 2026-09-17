class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        /*
            We are given an array and a target, and we need to find two non-overlapping subarrays where both subarrays have a sum equal to the target.

            And among all possible pairs , we need the minimum sum of their lengths.

            If we cannot find two such subarrays , we return -1.
        */

        /*
            Intuition

            How do we find a subarray whose sum is equal to target?

            Since all the numbers are positive, we can use a sliding window.

            But there's another problem.

            We need two subarrays , and they must be non-overlapping.

            For exammple :
            arr [7,3,4,7]
            target = 7
            We have three valid subarrays :
            [7] -> length  1
            [3,4] -> length 2
            [7] -> length 1
            The answer is 2 (1+1)

            So just finding the valid subarrays is not enough.

            For every valid subarrays, we need to know:

            What is the shortest valid subarray that appears completely before this one?

            And that's where we use DP.


            DP Idea ->

            We define dp[l] -> as the minimum length of a valid subarray found in the first l elements.

            so if our current subarray is : [l.......r]

            we use dp[l]

            Why dp[l]?

            Because dp[l] only looks at the elements beofre index l.

            So visually: 
            [previous subarray] [current subarray]

            dp[l] -> which is completely before l

            Therefore, the two subarrays are guaranteed to be non overlapping.

            This is the main idea of the problem.

            Sliding Window->

            We keep a variable s for the current window sum:

            int s  = 0;

            for(int l=0,r=0;r<n;r++) s+=arr[r];

            We keep moving r to the right and add arr[r] to our sum (s)

            If the sum becomes greater than the target, we move l forward:

            while(s>target) s-=arr[l++];

            When we Find a Valid Subarray

            Now suppose:
            s==target

            Current window -> r-l+1 is valid subarray

            Now comes the important line:

            ans = min(ans,r-l+1 + dp[l]);

            dp[l] -> gives the shortest valid subarray before index l/

            And notice that we use dp[l] not dp[r].

            That's important becuase dp[l] guarantees that the previous subarray doesn;t overlap with our current subarray.


            Updating DP:

            First we do : dp[r+1] = dp[r]

            This simply means : If I don't use the current subarray, I'll keep the best subarray I've already found.

            But if the current window is valid , we can also consider its length.

            dp[r+1] = min(dp[r],r-l+1);

            So dp[r+1] stores the shortest valid subarray we;ve seen to this point.


            Dry Run:

            arr = [3,2,2,4,3] target =3

            3 -> length =1
            
            1 + 1 = 2
         */

         int n = arr.size();
         int ans = n+1;
         int s = 0; // sum

        vector<int>dp(n+1,n);

        for(int l = 0 , r = 0 ; r<n;r++){
            s+= arr[r];

            while(s>target) s-=arr[l++];

            dp[r+1] = dp[r];

            if(s==target){
                ans = min(ans,r-l+1+dp[l]);
                dp[r+1] = min(dp[r],r-l+1);
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};