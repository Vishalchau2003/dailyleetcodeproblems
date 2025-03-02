#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 2570: Merge Two 2D Arrays by Summing Values

Problem Statement:
You are given two 2D integer arrays nums1 and nums2.
Each array contains unique ids and is sorted in ascending order by id.
Merge both arrays into one, summing values for common ids.

Constraints:
- 1 <= nums1.length, nums2.length <= 200
- 1 <= idi, vali <= 1000
*/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        
        // Merge both sorted arrays using two pointers
        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
                // If same id exists, sum values
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++; j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                // If id in nums1 is smaller, add it
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else {
                // If id in nums2 is smaller, add it
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < n) {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        // Add remaining elements from nums2
        while (j < m) {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return ans;
    }
};

// 🔹 Time Complexity: O(N + M) → Efficient merging
// 🔹 Space Complexity: O(N + M) → Output array storage
