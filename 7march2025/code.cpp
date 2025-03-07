#include <bits/stdc++.h>
using namespace std;

/*
🛠 APPROACH:
1️⃣ **Find Prime Numbers in the Given Range**  
   - Iterate from `left` to `right` and use a helper function `isPrime()` to check if each number is prime.  
   - Store all prime numbers in a vector.  

2️⃣ **Check If There Are at Least Two Primes**  
   - If we find fewer than 2 primes, return `[-1, -1]` because a valid pair cannot be formed.  

3️⃣ **Find the Closest Prime Pair**  
   - Iterate through the prime numbers and compute the difference between consecutive primes.  
   - Keep track of the minimum difference and update the answer accordingly.  

4️⃣ **Return the Pair with the Smallest First Element in Case of Tie**  
   - If multiple pairs have the same difference, return the one with the smaller first prime number.  

🕒 **Time Complexity**:  
   - Checking if a number is prime: `O(√N)`.  
   - Iterating from `left` to `right`: `O(R × √R)`.  
   - Finding the closest pair: `O(P)`.  
   - **Overall Complexity**: `O(R × √R)`.  

🗂 **Space Complexity**: `O(P)`, where `P` is the number of prime numbers in the range.
*/

class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int num) {
        if (num < 2) return false; // 0 and 1 are not prime
        for (int i = 2; i * i <= num; i++) { // Check divisibility from 2 to sqrt(num)
            if (num % i == 0) return false; // If divisible, it's not a prime
        }
        return true; // If no divisors found, it's prime
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes; // Stores prime numbers in the range

        // Step 1: Find all prime numbers in the given range
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }

        // Step 2: If there are less than 2 primes, return [-1, -1] as no valid pair exists
        if (primes.size() < 2) return {-1, -1};

        pair<int, int> ans = {-1, -1}; // Stores the closest prime pair
        int minDiff = INT_MAX; // Stores the minimum difference found

        // Step 3: Iterate through the prime numbers list to find the closest pair
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i]; // Compute difference between adjacent primes
            if (diff < minDiff) { // If a smaller difference is found, update the pair
                minDiff = diff;
                ans = {primes[i], primes[i + 1]};
            }
        }

        // Step 4: Return the closest prime pair
        return {ans.first, ans.second};
    }
};

// Driver code for testing
int main() {
    Solution sol;
    int left = 10, right = 19;
    vector<int> result = sol.closestPrimes(left, right);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
