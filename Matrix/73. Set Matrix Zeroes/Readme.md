# 73. Set Matrix Zeroes

## 🧩 Problem

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire **row** and **column** to `0`.

You must do it **in-place**.

---

## 📌 Example

### Input
```
matrix = 
[
 [1,1,1],
 [1,0,1],
 [1,1,1]
]
```

### Output
```
[
 [1,0,1],
 [0,0,0],
 [1,0,1]
]
```

---

# 💡 Approach (Optimal O(1) Space)

Instead of using extra arrays to store rows and columns containing `0`, we **use the first row and first column of the matrix as markers**.

### Key Idea

- Use `matrix[i][0]` → to mark that **row i should be zero**
- Use `matrix[0][j]` → to mark that **column j should be zero**

Since `matrix[0][0]` belongs to both row and column, we use a separate variable to track the **first column**.

---

# 🧠 Algorithm

1. Traverse the matrix and mark rows and columns when `0` is found.
2. Use the markers stored in the first row and column to update the matrix.
3. Traverse from **bottom-right to top-left** to avoid overwriting markers.
4. Handle the first column separately.

---

# 💻 C++ Implementation

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstCol = false;

        // Step 1: Mark rows and columns
        for(int i=0;i<rows;i++){
            if(matrix[i][0] == 0) firstCol = true;

            for(int j=1;j<cols;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Update matrix using markers
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }

            if(firstCol){
                matrix[i][0]=0;
            }
        }
    }
};
```

---

# ⏱ Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | **O(m × n)** |
| Space Complexity | **O(1)** |

---

# 📂 GitHub Repository Path

```
LeetCode-Solutions/
└── Arrays/
    └── 73-Set-Matrix-Zeroes/
        ├── Solution.cpp
        └── README.md
```

---

# 🔑 Key Concept

This problem teaches **in-place matrix manipulation**.

Instead of extra memory, we reuse the **matrix itself as storage**.

---

# 📚 Related Problems

- Rotate Image
- Spiral Matrix
- Game of Life

These problems also involve **matrix traversal and in-place transformations**.
