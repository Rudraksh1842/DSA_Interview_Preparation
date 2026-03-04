# 1582. Special Positions in a Binary Matrix

### 🔗 Problem Link
LeetCode - 1582. Special Positions in a Binary Matrix

---

## 🧠 Problem Statement

Given an `m x n` binary matrix `mat`, return the number of special positions in the matrix.

A position `(i, j)` is called **special** if:
- `mat[i][j] == 1`
- All other elements in row `i` are `0`
- All other elements in column `j` are `0`

---

## 📌 Example 1

Input:
mat = [[1,0,0],
       [0,0,1],
       [1,0,0]]

Output:
1

Explanation:
Only position (1,2) is special because:
- It contains 1
- Its row has only one 1
- Its column has only one 1

---

## 💡 Approach

### 🔥 Key Idea

1. Count the number of `1`s in each row.
2. Count the number of `1`s in each column.
3. Traverse the matrix again:
   - If `mat[i][j] == 1`
   - And `rowCount[i] == 1`
   - And `colCount[j] == 1`
   → Then it is a special position.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Count number of 1s in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int specialPositions = 0;
        
        // Check for special positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 &&
                    rowCount[i] == 1 &&
                    colCount[j] == 1) {
                    specialPositions++;
                }
            }
        }
        
        return specialPositions;
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(m × n)  
- First pass to count 1s  
- Second pass to check special positions  

Space Complexity: O(m + n)  
- Extra arrays for row and column counts  

---

## 🏷️ Tags

Matrix  
Array  
Counting  

---

## 🎯 Key Takeaways

- Precompute row and column counts to avoid repeated scanning.
- Use auxiliary arrays for efficient lookups.
- Two-pass traversal keeps the solution clean and readable.
