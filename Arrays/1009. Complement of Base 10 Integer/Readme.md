# 1009. Complement of Base 10 Integer

## Problem

Given a non-negative integer `n`, return the **bitwise complement** of its binary representation.

The complement of a binary number is obtained by **flipping all the bits** (`0 → 1` and `1 → 0`).

### Example 1

```
Input: n = 5
Output: 2
Explanation:
5 in binary  = 101
Complement   = 010
Decimal      = 2
```

### Example 2

```
Input: n = 0
Output: 1
Explanation:
Binary of 0 = 0
Complement  = 1
```

---

# Approach

### Step 1: Handle Edge Case

If `n = 0`, the complement is `1`.

### Step 2: Convert Decimal → Binary

Use division by `2` to extract binary digits.

```
n = 5
Binary = 101
```

Store digits in a vector.

### Step 3: Flip the Bits

Replace:

```
0 → 1
1 → 0
```

```
101 → 010
```

### Step 4: Convert Binary → Decimal

Reconstruct the number using:

```
res = res * 2 + bit
```

---

# Code (C++)

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int>ans;

        if(n==0){
            return 1;
        }

        // Convert decimal to binary
        while(n>0){
            int rem=n%2;
            ans.insert(ans.begin(),rem);
            n=n/2;
        }

        // Flip bits
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                ans[i]=1;
            }
            else if(ans[i]==1){
                ans[i]=0;
            }
        }

        // Convert binary back to decimal
        int res=0;
        for(int i:ans){
            res=res*2+i;
        }

        return res;
    }
};
```

---

# Complexity Analysis

| Complexity       | Value        |
| ---------------- | ------------ |
| Time Complexity  | **O(log n)** |
| Space Complexity | **O(log n)** |

Reason:
The number of binary digits of `n` is `log₂(n)`.

---

# Key Concepts

* Binary Representation
* Bit Flipping
* Base Conversion (Binary ↔ Decimal)

---

# Pattern

This problem belongs to **Bit Manipulation** problems.

Similar Problems:

* Number Complement
* Counting Bits
* Single Number

---

# Repository Structure

```
DSA_Interview_Preparation/
└── Bit Manipulation/
    └── 1009_Complement_of_Base_10_Integer/
        └── README.md
```
