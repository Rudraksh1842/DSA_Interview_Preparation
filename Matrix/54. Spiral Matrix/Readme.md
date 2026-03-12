# 54. Spiral Matrix

## Problem

Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

Spiral order means traversing the matrix in the following pattern:

1. Left → Right
2. Top → Bottom
3. Right → Left
4. Bottom → Top

Repeat this process until all elements are visited.

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
[1,2,3,6,9,8,7,4,5]
```

Explanation:

```text
Spiral traversal:

→ → →
      ↓
      ↓
← ← ←
↑
```

Traversal order:

```text
1 → 2 → 3 → 6 → 9 → 8 → 7 → 4 → 5
```

---

# Approach

We maintain **four boundaries**:

| Variable   | Meaning         |
| ---------- | --------------- |
| `rowStart` | Top boundary    |
| `rowEnd`   | Bottom boundary |
| `colStart` | Left boundary   |
| `colEnd`   | Right boundary  |

And traverse the matrix in **four directions**.

---

## Step 1: Traverse Left → Right

Traverse the **top row** from `colStart` to `colEnd`.

Then move the top boundary down:

```
rowStart++
```

---

## Step 2: Traverse Top → Bottom

Traverse the **right column** from `rowStart` to `rowEnd`.

Then move the right boundary left:

```
colEnd--
```

---

## Step 3: Traverse Right → Left

Traverse the **bottom row** from `colEnd` to `colStart`.

Then move the bottom boundary up:

```
rowEnd--
```

---

## Step 4: Traverse Bottom → Top

Traverse the **left column** from `rowEnd` to `rowStart`.

Then move the left boundary right:

```
colStart++
```

---

## Continue Until

```
count < m * n
```

This ensures all elements are visited.

---

# C++ Implementation

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int count = 0;
        int rowStart = 0, rowEnd = m - 1;
        int colStart = 0, colEnd = n - 1;

        while(count < m * n){

            for(int i = colStart; count < m * n && i <= colEnd; i++){
                ans.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;

            for(int i =
```
