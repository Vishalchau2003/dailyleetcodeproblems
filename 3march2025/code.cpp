# Solution: Partition Array According to Given Pivot

## Approach:
1. **First Pass:** Collect all elements **less than pivot** in a new array.
2. **Count Occurrences:** Count how many times `pivot` appears.
3. **Insert Pivot:** Insert `pivot` elements in the middle.
4. **Second Pass:** Collect all elements **greater than pivot** while maintaining relative order.

### Time Complexity:
- **O(N)** because we iterate through `nums` a few times.

### Space Complexity:
- **O(N)** since we use an auxiliary array.

## Code:
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        int cnt = 0;
        
        for (int num : nums)
            if (num < pivot)
                ans.push_back(num);

        for (int num : nums)
            if (num == pivot)
                cnt++;

        ans.insert(ans.end(), cnt, pivot);

        for (int num : nums)
            if (num > pivot)
                ans.push_back(num);

        return ans;
    }
};
