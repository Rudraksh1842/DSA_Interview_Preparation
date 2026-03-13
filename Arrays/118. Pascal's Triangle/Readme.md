# 118. Pascal's Triangle

## Problem

Given an integer `numRows`, return the first **numRows** of **Pascal's Triangle**.

In Pascal's Triangle:

* The **first and last element of every row is 1**.
* Every other element is the **sum of the two elements directly above it**.

---

## Example

### Example 1

Input:

```text
numRows = 5
```

Output:

```text
[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]
```

Explanation:

```
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
```

Each number is formed by adding the two numbers above it.

---

# Approach

We build the triangle **row by row**.

### Step 1

Create a result vector to store all rows.

### Step 2

For every row `i`:

* Create a vector of size `i + 1`
* Initialize all elements with `1`

### Step 3

Fill the middle elements using:

```
triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
```

### Step 4

Push the row into the result.

---

# C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i = 0; i < numRows; i++){
            vector<int> row(i + 1, 1);

            for(int j = 1; j < i; j++){
                row[j] = res[i-1][j-1] + res[i-1][j];
            }

            res.push_back(row);
        }

        return res;
    }
};
```

---

# Dry Run

For `numRows = 5`

```
Row 0 → [1]

Row 1 → [1,1]

Row 2 → [1,2,1]

Row 3 → [1,3,3,1]

Row 4 → [1,4,6,4,1]
```

Final result:

```
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
```

---

# Complexity Analysis

| Complexity       | Value |
| ---------------- | ----- |
| Time Complexity  | O(n²) |
| Space Complexity | O(n²) |

Explanation:

* We generate `n` rows.
* Each row can contain up to `n` elements.

---

# Key Concepts

* 2D Vector
* Dynamic Construction
* Combinatorics Pattern

---

# Repository Path

```
DSA_Interview_Preparation/
└── Arrays/
    └── 118_Pascals_Triangle/
        └── README.md
```
