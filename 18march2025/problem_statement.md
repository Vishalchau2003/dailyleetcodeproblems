# 2401. Longest Nice Subarray  

## 📝 Problem Statement  
You are given an array `nums` consisting of positive integers.  

A subarray is called **nice** if the **bitwise AND** of every pair of elements that are in different positions in the subarray is equal to `0`.  

Return the **length of the longest nice subarray**.  

A subarray is a contiguous part of an array.  
Note that subarrays of length `1` are always considered nice.  

### 🔹 Example Cases  

#### **Example 1**  
**Input:**  
```
nums = [1,3,8,48,10]
Output:
3
Explanation:
The longest nice subarray is [3,8,48].
It satisfies:

3 & 8 = 0
3 & 48 = 0
8 & 48 = 0
No longer nice subarray exists, so we return 3.

Example 2
Input:
nums = [3,1,5,11,13]
Output:
1
Explanation:
The length of the longest nice subarray is 1, since any single-element subarray is always nice.

🔹 Constraints
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
