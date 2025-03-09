// Solution for counting alternating groups in a circular array

// Approach:
// 1. Extend the array to handle circular behavior.
// 2. Use a sliding window approach to check for valid alternating groups.
// 3. If two adjacent elements are the same, reset the window.
// 4. If a valid window of size 'k' is found, increase the count.
// 5. Return the total count of alternating groups.

#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> v(colors);
        
        // Extend the vector to simulate circular behavior
        for (int i = 0; i < k - 1; i++) {
            v.push_back(colors[i]);
        }

        int i = 0, j = 1, altercnt = 0;

        while (j < n + k - 1) {
            if (v[j] == v[j - 1]) { // If two adjacent elements are the same, restart window
                i = j;
                j++;
                continue; // Skip to the next element
            }
            if (j - i + 1 == k) { // Valid alternating window found
                altercnt++;
                i++; // Slide the window
            }
            j++;
        }

        return altercnt;
    }
};
