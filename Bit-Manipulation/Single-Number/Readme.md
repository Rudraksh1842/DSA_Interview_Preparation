# 136. Single Number

### 🔗 Problem Link
LeetCode - 136. Single Number

---

## 🧠 Problem Statement

Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with:
- Linear runtime complexity
- Constant extra space

---

## 📌 Example

Input:
nums = [2,2,1]

Output:
1

---

## 💡 Approach 1: Using Hash Map (Brute Force)

We can store frequency of each number using an unordered_map.

Steps:
1. Count frequency of each number.
2. Return the number whose frequency is 1.

### ⏱ Complexity
- Time: O(n)
- Space: O(n)

This works but does not satisfy constant space requirement.

---

## 💡 Approach 2: Using XOR (Optimal Solution)

### 🔥 Key Observations About XOR

Properties:

- a ^ a = 0
- a ^ 0 = a
- XOR is associative and commutative

Since every element appears twice:

Duplicate numbers cancel each other out when XORed.

Only the single number remains.

---

### 🔍 Example

nums = [4,1,2,1,2]

XOR all elements:

4 ^ 1 ^ 2 ^ 1 ^ 2

= (1 ^ 1) ^ (2 ^ 2) ^ 4  
= 0 ^ 0 ^ 4  
= 4

---

## 🧾 Optimal Implementation (C++)

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(int num : nums) {
            res ^= num;
        }

        return res;
    }
};
