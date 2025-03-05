/*
## 🔹 Approach 1: Brute Force (O(n))
### Idea:
- Simulate the process for `n` minutes.
- Each minute, expand outward by adding `4 * m` new cells, where `m` is the minute count.

### Implementation:
- Start with `1` colored cell.
- Each minute, add `4 * m` new cells to the count.
- Repeat for `n-1` minutes.

### Complexity:
- **Time Complexity**: O(n) (Linear growth)
- **Space Complexity**: O(1) (Only basic variables used)
*/
class Solution {
public:
    long long coloredCells(int n) {
        n = n - 1;
        long long colored = 1;
        long long m = 1;
        while (n > 0) {
            colored += 4 * m;
            m++;
            n--;
        }
        return colored;
    }
};

/*
## 🔹 Approach 2: Optimized (O(1))
### Idea:
/*- Identify the pattern:
  - `n = 1` → `1`
  - `n = 2` → `1 + 4`
  - `n = 3` → `1 + 4 + 8`
  - `n = 4` → `1 + 4 + 8 + 12`
- Sum of first `(n-1)` terms of an arithmetic series:
1 + 4 × (1 + 2 + 3 + ... + (n-1))

- Using the formula for the sum of the first (n-1) natural numbers:
1 + 4 × [(n-1) * n / 2]

Which simplifies to:
2n(n-1) + 1
*/

- This allows us to compute the answer **in constant time O(1)**.

### Complexity:
- **Time Complexity**: O(1) (Direct computation)
- **Space Complexity**: O(1) (Only basic variables used)
*/
class Solution {
public:
  long long coloredCells(int n) {
      return 2LL * n * (n - 1) + 1;
  }
};

/*
### 🔹 Comparison of Approaches:
| Approach   | Time Complexity | Space Complexity | Notes |
|------------|----------------|------------------|--------|
| Brute Force (Loop) | O(n) | O(1) | Works but slow for large `n` |
| Optimized Formula  | O(1) | O(1) | Best approach for `n ≤ 10^5` |

*/
