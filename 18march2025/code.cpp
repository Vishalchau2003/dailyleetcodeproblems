
---

### **📜 code.cpp (All Three Solutions with Approaches)**
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
===================================================================================
🔹 **Brute Force Approach (O(N^3))**
===================================================================================
✔ Iterate over all subarrays `(i, j)`.
✔ For each subarray, check if it's nice using a bitwise mask.
✔ If the subarray is nice, update the maximum length.
✔ Stop checking when an invalid subarray is found (early termination).

🔹 **Time Complexity:** O(N^3)
🔹 **Space Complexity:** O(1)
*/
class Solution_BruteForce {
public:
    bool isnice(vector<int>& nums, int i, int j) {
        int mask = 0;
        for (int k = i; k <= j; k++) { 
            if ((mask & nums[k]) != 0)
                return false;
            mask |= nums[k]; 
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1; 

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isnice(nums, i, j)) {
                    maxi = max(maxi, j - i + 1);
                } else {
                    break; // Stop early if the subarray is not nice
                }
            }
        }
        return maxi;
    }
};

/*
===================================================================================
🔹 **Better Approach (O(N^2))**
===================================================================================
✔ Iterate over all subarrays `(i, j)`.
✔ Maintain a **bitmask** to check if adding a new element keeps the subarray nice.
✔ If adding `nums[j]` violates the nice condition, break.
✔ Update maximum length.

🔹 **Time Complexity:** O(N^2)
🔹 **Space Complexity:** O(1)
*/
class Solution_Better {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1; 

        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = i; j < n; j++) {
                if ((mask & nums[j]) != 0)  // If AND is non-zero, break
                    break; 
                else {
                    maxi = max(maxi, j - i + 1);
                    mask |= nums[j];  // Include nums[j] in the bitmask
                }
            }
        }
        return maxi;
    }
};

/*
===================================================================================
🔹 **Optimal Approach (Sliding Window - O(N))**
===================================================================================
✔ Use a **sliding window** with two pointers `i` and `j`.
✔ Maintain a **bitmask** that stores the OR of all elements in the current window.
✔ If `nums[j]` violates the nice condition, **shrink the window from the left**.
✔ Keep track of the **maximum window size**.

🔹 **Time Complexity:** O(N)
🔹 **Space Complexity:** O(1)
*/
class Solution_Optimal {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int i = 0, j = 0;
        int mask = 0;

        while (j < n) {
            while ((mask & nums[j]) != 0) {  // If AND is non-zero, remove nums[i]
                mask ^= nums[i];
                i++;
            }
            mask |= nums[j];  // Add nums[j] to the window
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};

/*
===================================================================================
🔹 **Driver Code for Testing**
===================================================================================
*/
int main() {
    vector<int> nums1 = {1, 3, 8, 48, 10};
    vector<int> nums2 = {3, 1, 5, 11, 13};

    Solution_BruteForce brute;
    Solution_Better better;
    Solution_Optimal optimal;

    cout << "Brute Force Output: " << brute.longestNiceSubarray(nums1) << endl;  // Output: 3
    cout << "Better Output: " << better.longestNiceSubarray(nums1) << endl;      // Output: 3
    cout << "Optimal Output: " << optimal.longestNiceSubarray(nums1) << endl;    // Output: 3

    cout << "Brute Force Output: " << brute.longestNiceSubarray(nums2) << endl;  // Output: 1
    cout << "Better Output: " << better.longestNiceSubarray(nums2) << endl;      // Output: 1
    cout << "Optimal Output: " << optimal.longestNiceSubarray(nums2) << endl;    // Output: 1

    return 0;
}
