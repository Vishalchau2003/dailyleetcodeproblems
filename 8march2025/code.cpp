/*
    Solution for: 2379. Minimum Recolors to Get K Consecutive Black Blocks

    Approaches:
    1. Brute Force: Check all windows of size k, count 'W' blocks, and take the minimum (O(n * k)).
    2. Optimized Sliding Window: Use a sliding window to maintain the count dynamically in O(n) time.
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    // Brute Force Approach (O(n * k))
    int minimumRecolorsBruteForce(string blocks, int k) {
        int n = blocks.size();
        int minop = INT_MAX;

        // Check all windows of size k
        for (int i = 0; i <= n - k; i++) {
            int white = 0;
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') white++;
            }
            minop = min(minop, white);
        }
        
        return minop;
    }

    // Optimized Sliding Window Approach (O(n))
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minop = INT_MAX;
        int i = 0, j = 0;
        int white = 0;

        while (j < n) {
            // Count 'W' in the window
            if (blocks[j] == 'W') {
                white++;
            }

            // If window size is k
            if (j - i + 1 == k) {
                minop = min(minop, white);

                // Remove the effect of i before moving the window
                if (blocks[i] == 'W') {
                    white--;
                }
                i++;  // Move window forward
            }

            j++;  // Expand the window
        }
        
        return minop;
    }
};

// Test the solutions
int main() {
    Solution sol;
    string blocks = "WBBWWBBWBW";
    int k = 7;
    
    cout << "Brute Force Result: " << sol.minimumRecolorsBruteForce(blocks, k) << endl;
    cout << "Sliding Window Result: " << sol.minimumRecolors(blocks, k) << endl;
    
    return 0;
}
