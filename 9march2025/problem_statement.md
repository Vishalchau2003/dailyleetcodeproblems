# Alternating Groups in a Circular Array

## 📝 Problem Statement  
You are given an array of integers `colors` representing a circle of red and blue tiles, and an integer `k`. The color of tile `i` is represented by `colors[i]`:

- `colors[i] == 0` means that tile `i` is red.
- `colors[i] == 1` means that tile `i` is blue.

An **alternating group** is defined as any `k` contiguous tiles in the circle where:
- The colors **strictly alternate** (each tile in the group except the first and last one has a different color from its left and right tiles).

Since `colors` represents a **circular** arrangement, the first and last tiles are considered adjacent.
### 🔹 Example Cases  
#### **Example 1**  
**Input:**  
```cpp
colors = [0,1,0,1,0]
k = 3
```
**Output:**  
```cpp
3
```
**Explanation:**  
Valid alternating groups:
1. (0,1,0)
2. (1,0,1)
3. (0,1,0) (circular)

#### **Example 2**  
**Input:**  
```cpp
colors = [0,1,0,0,1,0,1]
k = 6
```
**Output:**  
```cpp
2
```
**Explanation:**  
Valid alternating groups:
1. (0,1,0,1,0,1)
2. (1,0,1,0,1,0)

#### **Example 3**  
**Input:**  
```cpp
colors = [1,1,0,1]
k = 4
```
**Output:**  
```cpp
0
```
**Explanation:**  
No valid alternating groups exist.

### 🔹 Constraints  
- `3 <= colors.length <= 10^5`
- `0 <= colors[i] <= 1`
- `3 <= k <= colors.length`
