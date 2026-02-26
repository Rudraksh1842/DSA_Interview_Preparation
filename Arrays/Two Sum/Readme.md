# 1. Two Sum

### 🔗 Problem Link
LeetCode - 1. Two Sum

---

## 🧠 Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

- Each input has exactly one solution.
- You may not use the same element twice.
- Return the answer in any order.

---

## 📌 Example

Input:
nums = [2,7,11,15], target = 9

Output:
[0,1]

Explanation:
nums[0] + nums[1] = 2 + 7 = 9

---

## 💡 Approach (Hash Map - Optimal)

### 🔥 Key Idea

For every element `nums[i]`, we calculate:
