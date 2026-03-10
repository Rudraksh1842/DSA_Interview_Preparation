# 739. Daily Temperatures

## 🧩 Problem
Given an array `temperatures` representing the daily temperatures, return an array `answer` such that:

- `answer[i]` is the **number of days you have to wait after the i-th day to get a warmer temperature**.
- If there is **no future day** for which this is possible, keep `answer[i] = 0`.

---

## 📌 Example

### Input
```
temperatures = [73,74,75,71,69,72,76,73]
```

### Output
```
[1,1,4,2,1,1,0,0]
```

### Explanation

| Day | Temperature | Days to Wait |
|----|----|----|
| 73 | 74 | 1 |
| 74 | 75 | 1 |
| 75 | 76 | 4 |
| 71 | 72 | 2 |
| 69 | 72 | 1 |
| 72 | 76 | 1 |
| 76 | — | 0 |
| 73 | — | 0 |

---

# 💡 Approach (Jump / Dynamic Programming)

Instead of checking every future temperature (which leads to **O(n²)**), we:

1. Traverse the array **from right to left**.
2. Use previously computed results to **jump forward**.
3. Skip unnecessary comparisons.

If the next temperature is not warmer, we jump using:

```
j += ans[j]
```

This allows us to skip multiple elements at once.

---

# 🧠 Algorithm

1. Initialize an array `ans` of size `n` with `0`.
2. Traverse from the **second last element** to the beginning.
3. For each index:
   - Start checking the next index.
   - If the next temperature is not warmer, jump using stored results.
4. If a warmer day is found, store the difference of indices.

---

# 💻 C++ Implementation

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n,0);

        for(int i=n-2;i>=0;i--){
            int j=i+1;

            while(j<n && t[j] <= t[i]){
                if(ans[j] == 0){
                    j = n;
                } else {
                    j += ans[j];
                }
            }

            if(j<n){
                ans[i] = j-i;
            }
        }

        return ans;
    }
};
```

---

# ⏱ Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | **O(n)** (amortized) |
| Space Complexity | **O(n)** |

---

# 📂 GitHub Repository Path

```
LeetCode-Solutions/
└── Stack/
    └── 739-Daily-Temperatures/
        ├── Solution.cpp
        └── README.md
```

---

# 🔑 Pattern

This problem belongs to the **Next Greater Element pattern**.

Similar problems:

- Next Greater Element I
- Next Greater Element II
- Daily Temperatures

These problems are commonly solved using **Monotonic Stack** or **Jump Optimization**.
