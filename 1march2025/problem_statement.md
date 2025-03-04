
# 2460. Apply Operations to an Array  

## 📝 Problem Statement  
You are given a **0-indexed** array `nums` of size `n`, consisting of **non-negative** integers.  

You need to perform **(n - 1) operations** on this array, following these rules:  

1. If `nums[i] == nums[i + 1]`, **double** `nums[i]` and set `nums[i + 1] = 0`.  
2. Otherwise, skip this operation.  
3. After all operations, **shift all `0's` to the end** while maintaining the relative order of non-zero elements.  

Return the modified array after performing all operations.  

### 🔹 Example Cases  

#### **Example 1**  
**Input:**  
nums = [1,2,2,1,1,0]

**Output:**  
[1,4,2,0,0,0]

**Explanation:**  
- `nums[1] == nums[2]`, so `nums[1] *= 2` and `nums[2] = 0` → `[1,4,0,1,1,0]`  
- `nums[3] == nums[4]`, so `nums[3] *= 2` and `nums[4] = 0` → `[1,4,0,2,0,0]`  
- Finally, shift all `0's` to the end → `[1,4,2,0,0,0]`  

#### **Example 2**  
**Input:**  
nums = [0,1]

**Output:**  
[1,0]

**Explanation:**  
- No operations applied, just shifting `0` to the end.

### 🔹 Constraints  
- `2 <= nums.length <= 2000`  
- `0 <= nums[i] <= 1000`  
