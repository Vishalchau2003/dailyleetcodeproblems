
#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. **Sort the Meetings**: Sorting ensures that we process meetings in chronological order.
2. **Iterate Through Meetings**:
   - If there is a gap between the current meeting's start and the last tracked end day, count those days as free.
   - Update the end day to reflect the latest occupied day.
3. **Handle Remaining Days**: If there are any free days left after the last meeting, add them to the result.

Time Complexity: O(N log N) (due to sorting) + O(N) (iterating through meetings) = O(N log N)
Space Complexity: O(1) (constant extra space usage)
*/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int n = meetings.size();
        int result = 0;
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < n; i++) {
            start = meetings[i][0];
            if (start > end) {
                result += start - end - 1;
            }
            end = max(end, meetings[i][1]);
        }
        
        if (days > end) {
            result += days - end;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    int days = 10;
    cout << "Free Days: " << sol.countDays(days, meetings) << endl;
    return 0;
}
