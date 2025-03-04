**Explanation:**  
- No operations applied, just shifting `0` to the end.

### 🔹 Constraints  
- `2 <= nums.length <= 2000`  
- `0 <= nums[i] <= 1000`  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    ✅ Approach: Modify & Shift
    
    🔹 **Step 1: Modify the array**  
      - Traverse the array and check if `nums[i] == nums[i + 1]`.  
      - If true, double `nums[i]` and set `nums[i + 1]` to `0`.  

    🔹 **Step 2: Shift non-zero elements forward**  
      - Move all non-zero elements to the front while maintaining order.

    📌 **Time Complexity:** `O(N)` (Iterate twice)
    📌 **Space Complexity:** `O(1)` (Modify in place)
    */
    
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Modify the array based on given conditions
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) { 
                nums[i] = 2 * nums[i]; // Double the current element
                nums[i + 1] = 0;       // Set the next element to zero
            }
        }
        
        // Step 2: Move all non-zero elements to the front while maintaining their order
        
        int j = 0; // Pointer for placing non-zero elements
        
        // Move non-zero elements forward
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]); // Swap non-zero element with zero
                j++; // Move the zero pointer forward
            }
        }
        
        return nums;
    }
};
