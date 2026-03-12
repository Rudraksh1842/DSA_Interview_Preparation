# 48. Rotate Image

## Problem

Given an `n x n` 2D matrix representing an image, rotate the image by **90 degrees (clockwise)**.

You must rotate the image **in-place**, meaning you have to modify the input matrix directly without using another matrix.

---

## Example

### Example 1

Input:

```text
matrix = [
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

Output:

```text
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]
```

---

## Approach

To rotate the matrix **90° clockwise**, we can perform two steps:

### Step 1: Transpose the Matrix

Swap `matrix[i][j]` with `matrix[j][i]`.

Example:

```text
Original
1 2 3
4 5 6
7 8 9

Transpose
1 4 7
2 5 8
3 6 9
```

---

### Step 2: Reverse Each Row

After transposing, reverse every row.

```text
Before reverse
1 4 7
2 5 8
3 6 9

After reverse
7 4 1
8 5 2
9 6 3
```

This results in a **90° clockwise rotation**.

---

# C++ Implementation

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

# Complexity Analysis

| Complexity       | Value     |
| ---------------- | --------- |
| Time Complexity  | **O(n²)** |
| Space Complexity | **O(1)**  |

Explanation:

* We traverse the matrix twice.
* No extra matrix is used.

---

# Key Concepts

* Matrix Transpose
* In-place Matrix Manipulation
* 2D Array Operations

---

# Repository Path

```text
DSA_Interview_Preparation/
└── Matrix/
    └── 48_Rotate_Image/
        └── README.md
```
