# 485. Max Consecutive Ones

### 🔗 Problem Link
LeetCode - 485. Max Consecutive Ones

---

## 🧠 Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

---

## 📌 Example

Input:
nums = [1,1,0,1,1,1]

Output:
3

Explanation:
The longest consecutive sequence of 1s is [1,1,1].

---

## 💡 Approach

We iterate through the array and:

- If the current element is `1`, increase the current streak count.
- If it is `0`, reset the count.
- Keep track of the maximum streak seen so far.

This is simply counting a continuous streak.

---

## 🔍 Algorithm

1. Initialize:
   - `count = 0`
   - `maxCount = 0`
2. Traverse the array:
   - If element is `1`, increment `count`
   - Update `maxCount`
   - If element is `0`, reset `count = 0`
3. Return `maxCount`

---

## 🧾 Implementation (C++)

See `solution.cpp` for full implementation.

---

## ⏱ Time Complexity

O(n)

We traverse the array once.

---

## 📦 Space Complexity

O(1)

No extra space is used.

---

## 🚀 Key Learning

- Counting streak pattern
- Resetting state when condition breaks
- Efficient single-pass traversal
