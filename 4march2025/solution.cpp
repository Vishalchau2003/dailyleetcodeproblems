
class Solution {
public:
    /*
    ✅ Approach 1: Brute Force (Iterative Subtraction)
    
    🔹 Idea:
      - Find the highest power of `3` less than or equal to `n`.
      - Try to subtract it while ensuring only **distinct** powers are used.
      - If we need to use the same power again, return `false`.  

    🔹 Complexity Analysis:
      - Time Complexity: O(log n) (Finding powers of 3)
      - Space Complexity: O(1)  
    */
    bool checkPowersOfThree_BruteForce(int n) {
        int p = 0;
        while (pow(3, p) < n) {
            p++;
        }
        while (n > 0) {
            if (n >= pow(3, p)) {
                n = n - pow(3, p);
            }
            if (n >= pow(3, p)) {
                return false;  // Can't use the same power again
            }
            p--;
        }
        return true;
    }

    /*
    ✅ Approach 2: Optimized Greedy Division
    
    🔹 Idea:
      - If `n` contains `2` when divided by `3`, return `false` (since we need distinct powers).
      - Keep dividing `n` by `3` until `n` becomes `0`.  

    🔹 Complexity Analysis:
      - Time Complexity: O(log n)
      - Space Complexity: O(1)  

    🔹 Why is this optimal?
      ✅ We only check the remainder of division by `3`, making it **fast**.
      ✅ Ensures we only use `0` or `1` coefficients for each power of `3`, maintaining **uniqueness**.  
    */
    bool checkPowersOfThree_Optimized(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};

