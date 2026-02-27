📈 121. Best Time to Buy and Sell Stock
🧩 Problem Statement

You are given an array prices where:

prices[i] represents the price of a given stock on the i-th day`.

You want to maximize your profit by choosing one day to buy and one different day in the future to sell.

Return the maximum profit you can achieve.

If no profit is possible, return 0.

💡 Approach (Greedy + Two Pointers)

We use a simple greedy approach:

left → represents the buying day

right → represents the selling day

Keep track of the minimum price so far

Update maximum profit whenever possible

🔎 Algorithm

Initialize:

left = 0

maxProfit = 0

Traverse from index 1 to n-1:

If prices[right] < prices[left]

Update left = right (found cheaper stock)

Else

Calculate profit = prices[right] - prices[left]

Update maxProfit

Return maxProfit

🧠 Intuition

We always try to buy at the lowest price before the current day.

For every day, we check if selling today gives us better profit.

Since we only scan once, it’s efficient.

📌 Example
Input:
prices = [7,1,5,3,6,4]
Walkthrough:
Day	Price	Min Buy Price	Profit	Max Profit
0	7	7	-	0
1	1	1	-	0
2	5	1	4	4
3	3	1	2	4
4	6	1	5	5
5	4	1	3	5
Output:
5
⏱️ Time Complexity
O(n)

We traverse the array once.

📦 Space Complexity
O(1)

Only two variables are used.

🚀 Key Takeaways

Classic Greedy problem

Maintain minimum element so far

Frequently asked in coding interviews

Important pattern for stock / max difference problems
