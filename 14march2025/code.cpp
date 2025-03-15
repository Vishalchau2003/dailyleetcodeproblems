
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Approach:
    - Use Binary Search on the answer.
    - Define `low = 1` (minimum candies per child) and `high = max(candies)` (max candies possible per child).
    - Perform binary search to check if it's possible to distribute `mid` candies per child.
    - If possible, try to maximize `mid` by moving `low` up.
    - Otherwise, reduce `high` and continue searching.
    - The final `ans` will be the largest possible candies each child can get.
    */
    
    long long satisfy(int n, long long mid, vector<int>& candies) {
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += candies[i] / mid;
        }
        return cnt;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        
        if (sum < k) return 0;

        long long low = 1, high = *max_element(candies.begin(), candies.end());
        long long ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (satisfy(n, mid, candies) >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Example usage:
// int main() {
//     vector<int> candies = {5, 8, 6};
//     long long k = 3;
//     Solution sol;
//     cout << sol.maximumCandies(candies, k) << endl; // Output: 5
//     return 0;
// }
