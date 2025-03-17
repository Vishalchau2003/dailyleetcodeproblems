
// solution.cpp

/*
Approach:
- We use **Binary Search** to determine the minimum possible capability.
- The search space is between the minimum and maximum values in the `nums` array.
- For each `mid` value, we check if it's possible to rob at least `k` houses without robbing adjacent ones.
- The `canSteal` function simulates the robbery process and verifies if `k` houses can be robbed within the given capability.
- If `canSteal` returns true, we update `ans` and try a lower capability (`high = mid - 1`), otherwise, we increase `low`.
- This ensures an **O(N log M)** solution where `M` is the range of house values.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSteal(vector<int>& nums, int n, int mid, int k) {
        int houseCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                houseCnt++;
                i++; // Skip next house
            }
        }
        return houseCnt >= k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSteal(nums, n, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

