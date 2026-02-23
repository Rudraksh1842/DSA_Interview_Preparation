# 762. Prime Number of Set Bits in Binary Representation

### 🔗 Problem Link
LeetCode - 762. Prime Number of Set Bits in Binary Representation

---

## 🧠 Problem Statement

Given two integers `left` and `right`, return the count of numbers in the inclusive range `[left, right]` whose number of set bits (1s in binary representation) is a prime number.

---

## 💡 Approach

1. Iterate through all numbers from `left` to `right`.
2. For each number:
   - Count the number of set bits using bit manipulation.
   - Check if the count of set bits is a prime number.
3. If the count is prime, increment the total count.
4. Return the final count.

---

## 🔍 Key Concepts Used

- Bit Manipulation (`n & 1`, right shift `n >> 1`)
- Prime number checking (Optimized √n approach using 6k ± 1 pattern)
- Iteration over range

---

## ⏱ Time Complexity

- Counting set bits for each number: O(log n)
- Prime check: O(√k), where k is number of set bits (at most 32 for int)

Overall Time Complexity:
O((right - left + 1) * log n)

---

## 📦 Space Complexity

O(1)

Only constant extra space is used.

---

## 🧾 Implementation Details

- Set bits counted using right shift operation.
- Prime checking optimized using:
  - Early elimination for numbers divisible by 2 or 3.
  - Checking factors in the form of 6k ± 1.

---

## 🚀 Learning Outcome

This problem strengthens understanding of:
- Bit manipulation techniques
- Efficient prime checking
- Combining mathematical logic with binary operations
