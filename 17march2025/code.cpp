// solution.cpp

/*
Approach 1: Using Map (O(N))
- We use an unordered map to count the frequency of each element in `nums`.
- After counting, we iterate through the map to check if each element appears an even number of times.
- If any count is odd, return `false`.
- This approach runs in **O(N)** time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto it : freq) {
            if (it.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};

/*
Approach 2: Using Frequency Array (O(N + max(nums)))
- We determine the maximum value in `nums` and create a frequency array `v`.
- We iterate over `nums`, incrementing the count for each number.
- Finally, we check if all counts are even; if any count is odd, return `false`.
- This solution runs in **O(N + max(nums))** time complexity.
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> v(maxi + 1, 0);
        
        for (int i = 0; i < n; i++) {
            v[nums[i]]++;
        }
        
        for (int i = 0; i < maxi + 1; i++) {
            if (v[i] % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
