# 121. Best Time to Buy and Sell Stock

### 🔗 Problem Link
LeetCode - 121. Best Time to Buy and Sell Stock

---

## 🧠 Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i-th` day.

You want to maximize your profit by choosing:
- One day to buy the stock
- A different future day to sell the stock

Return the maximum profit you can achieve.  
If you cannot achieve any profit, return `0`.

---

## 📌 Example 1

Input:
prices = [7,1,5,3,6,4]

Output:
5

Explanation:
Buy on day 2 (price = 1) and sell on day 5 (price = 6).  
Profit = 6 - 1 = 5.

---

## 📌 Example 2

Input:
prices = [7,6,4,3,1]

Output:
0

Explanation:
In this case, no transaction is done and the max profit = 0.

---

## 💡 Approach: Two Pointer / Sliding Window (Optimal)

### 🔥 Key Idea

To maximize profit:
- Always buy at the lowest price seen so far.
- Try selling at every future day.
- Keep updating the maximum profit.

If a lower price is found → update the buying day.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;   // buy day
        int maxProfit = 0;

        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] < prices[left]) {
                left = right;   // found cheaper buy price
            } else {
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
        }

        return maxProfit;
    }
};
```

---

## ⏱️ Complexity Analysis

Time Complexity: O(n)  
Space Complexity: O(1)
