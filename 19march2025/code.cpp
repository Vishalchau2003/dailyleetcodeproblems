/*
Approach:
1. Traverse the array and find the first occurrence of `0`.
2. If a `0` is found, check if we can flip a window of size `3` starting from that position.
3. Flip the 3 elements (toggle 0 to 1 and 1 to 0) and increment the operation count.
4. Continue this process until the end of the array.
5. After the traversal, if any `0` remains, return -1 as it is impossible to make all elements `1`.
6. Otherwise, return the count of operations.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int j = 0;
        
        while (j < n) {
            while (j < n && nums[j] == 1) {
                j++;
            }
            
            if (j <= n - 3) {
                for (int k = j; k < j + 3; k++) {
                    nums[k] ^= 1;
                }
                cnt++;
            } else {
                break;
            }
            j++;
        }
        
        for (int x : nums) {
            if (x == 0) return -1;
        }
        return cnt;
    }
};
