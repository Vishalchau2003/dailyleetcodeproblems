## 🔹 Approach
1. **Initialize a hash array** of size `n^2 + 1` to store the frequency of numbers.
2. **Traverse the grid** and count occurrences of each number.
3. **Identify the repeated and missing numbers**:
   - If `hash[i] == 2`, then `i` is the repeated number.
   - If `hash[i] == 0`, then `i` is the missing number.
4. **Return the pair** `{repeated, missing}`.

## 🔹 Complexity Analysis
- **Time Complexity**: `O(n²)` (We iterate through the grid once and then iterate through `hash`).
- **Space Complexity**: `O(n²)` (Extra space for the frequency array).
*/
  
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> hash(n * n + 1, 0);
        
        // Count frequency of each number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hash[grid[i][j]]++;
            }
        }

        int rep = -1, miss = -1;
        for (int i = 1; i <= n * n; i++) { // Numbers range from 1 to n^2
            if (hash[i] == 2) rep = i;
            if (hash[i] == 0) miss = i;
        }
        
        return {rep, miss};
    }
};
