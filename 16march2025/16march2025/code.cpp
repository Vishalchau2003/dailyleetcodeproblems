
// solution.cpp

/*
Approach:
- We use **Binary Search** on the minimum time required to repair all cars.
- The search space is between `min_rank * 1` (minimum possible time) and `max_rank * cars^2` (worst-case scenario).
- The `isPossible` function checks if it's feasible to repair all cars in `mid` minutes by assigning cars optimally to mechanics.
- If possible, we try a smaller time (`high = mid - 1`), otherwise, increase the time (`low = mid + 1`).
- This ensures an **O(N log T)** solution where `T` is the range of time values.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars) {
        long long sum = 0;
        for (int i = 0; i < ranks.size(); i++) {
            sum += sqrt(mid / ranks[i]); 
            if (sum >= cars) return true; // If we can repair required cars, return early
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = (*min_element(ranks.begin(), ranks.end())) * (long long)1;
        long long high = (*max_element(ranks.begin(), ranks.end())) * (long long)cars * (long long)cars;
        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(ranks, mid, cars)) {
                result = mid;  // Try to minimize time
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
