
## 🔹 Approach

### **1️⃣ Precompute Next Consonant Indices**
- Store, for each position `i`, the **next consonant** index (`nextCons[i]`).
- This helps in counting valid substrings efficiently.

### **2️⃣Expand the Sliding Window (`j` moves right)**
- Maintain a **vowel frequency map** to track all vowels in the current window.
- Keep a **counter for consonants** to ensure exactly `k` consonants.

### **3️⃣ Shrink the Window (`i` moves right)**
- If **consonant count exceeds `k`**, remove elements from the left (`i++`).
- Ensure **all 5 vowels** are present before counting substrings.

### **4️⃣ Count Valid Substrings**
- If the window satisfies conditions, extend it **up to the next consonant** (using `nextCons[j]`).
- This gives us **all possible valid substrings starting from `j`**.

---

// solution.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        vector<int> nextCons(n, n); // Stores next consonant index
        int lastConsIdx = n;

        // Precompute next consonant index for each position
        for (int i = n - 1; i >= 0; i--) {
            if (!isVowel(word[i])) lastConsIdx = i;
            nextCons[i] = lastConsIdx;
        }

        int i = 0, j = 0, consonantCnt = 0;
        long long result = 0;
        unordered_map<char, int> vowelMap; // Track vowel frequency

        while (j < n) {
            char ch = word[j];

            if (isVowel(ch)) vowelMap[ch]++;
            else consonantCnt++;

            // Adjust `i` when consonant count exceeds `k`
            while (i <= j && consonantCnt > k) {
                char leftChar = word[i];
                if (isVowel(leftChar)) {
                    vowelMap[leftChar]--;
                    if (vowelMap[leftChar] == 0) vowelMap.erase(leftChar);
                } else {
                    consonantCnt--;
                }
                i++;
            }

            // If valid, count substrings up to the next consonant
            if (vowelMap.size() == 5 && consonantCnt == k) {
                int idx = nextCons[j]; // Find next consonant position
                result += (idx - j); // Count valid substrings
            }

            j++; // Expand window
        }

        return result;
    }
};
