# Partition Array According to Given Pivot (LeetCode 2161)

## Problem Statement
You are given a 0-indexed integer array `nums` and an integer `pivot`. Rearrange `nums` such that:
1. Every element less than `pivot` appears before every element greater than `pivot`.
2. Every element equal to `pivot` appears in between.
3. The relative order of elements is maintained.

### Example 1:
**Input:**  
`nums = [9,12,5,10,14,3,10]`, `pivot = 10`  
**Output:**  
`[9,5,3,10,10,12,14]`

### Example 2:
**Input:**  
`nums = [-3,4,3,2]`, `pivot = 2`  
**Output:**  
`[-3,2,4,3]`

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^6 <= nums[i] <= 10^6`
- `pivot` is guaranteed to be in `nums`.
