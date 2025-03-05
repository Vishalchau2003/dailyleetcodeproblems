# 2579. Count Total Number of Colored Cells  

## 📝 Problem Statement  
There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer `n`, indicating that you must do the following routine for `n` minutes:

- At the **first minute**, color any arbitrary unit cell blue.
- Every **minute thereafter**, color blue **every uncolored cell that touches a blue cell**.

Return the **number of colored cells** at the end of `n` minutes.

### 🔹 Example Cases  

#### **Example 1**  
**Input:**  
n = 1

**Output:**  
1

**Explanation:**  
After 1 minute, there is only 1 blue cell, so we return 1.

#### **Example 2**  
**Input:**  
n = 2

**Output:**  
5

