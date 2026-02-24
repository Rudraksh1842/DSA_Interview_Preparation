# 1752. Check if Array Is Sorted and Rotated

### 🔗 Problem Link
LeetCode - 1752. Check if Array Is Sorted and Rotated

---

## 🧠 Problem Statement

Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order and then rotated some number of times (including zero times). Otherwise, return `false`.

An array rotated `x` times means elements are shifted circularly.

---

## 📌 Example

Input:
nums = [3,4,5,1,2]

Output:
true

Explanation:
Original sorted array: [1,2,3,4,5]  
Rotated 3 times → [3,4,5,1,2]

---

## 💡 Approach

### Key Observation:

In a sorted array:
- Elements are in non-decreasing order.
- There should be **at most one place** where:
