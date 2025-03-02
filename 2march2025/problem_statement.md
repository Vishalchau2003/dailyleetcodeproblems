# LeetCode 2570: Merge Two 2D Arrays by Summing Values

## 📝 Problem Statement
You are given two 2D integer arrays `nums1` and `nums2`, where:  
- `nums1[i] = [id_i, val_i]` represents an id-value pair.  
- `nums2[j] = [id_j, val_j]` represents another id-value pair.  
- Both arrays are **sorted in strictly ascending order** by `id`.  

### 🔹 **Objective**  
Merge both arrays such that:  
1. Each **unique id** appears only once in the result.  
2. If an id appears in both arrays, **sum their values**.  
3. The result must be **sorted in ascending order** by `id`.  

### 📌 Constraints
- `1 <= nums1.length, nums2.length <= 200`
- `nums1[i].length == nums2[j].length == 2`
- `1 <= id_i, val_i <= 1000`
- Both arrays contain **unique ids** and are sorted in ascending order.

---

## 📌 Example

### Example 1:
#### **Input:**
```cpp
nums1 = [[1,2],[2,3],[4,5]];
nums2 = [[1,4],[3,2],[4,1]];
