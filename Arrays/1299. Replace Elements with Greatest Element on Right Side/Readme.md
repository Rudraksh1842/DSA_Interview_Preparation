# 1299. Replace Elements with Greatest Element on Right Side

## 🔗 Problem Link

LeetCode - 1299. Replace Elements with Greatest Element on Right Side

---

## 🧠 Problem Statement

Given an array `arr`, replace every element with the **greatest element among the elements to its right**, and replace the **last element with -1**.

Return the resulting array.

---

## 📌 Example

### Example 1

Input

```
arr = [17,18,5,4,6,1]
```

Output

```
[18,6,6,6,1,-1]
```

Explanation

| Index | Original | Greatest on Right | Result |
| ----- | -------- | ----------------- | ------ |
| 0     | 17       | 18                | 18     |
| 1     | 18       | 6                 | 6      |
| 2     | 5        | 6                 | 6      |
| 3     | 4        | 6                 | 6      |
| 4     | 6        | 1                 | 1      |
| 5     | 1        | —                 | -1     |

---

## 💡 Approach

The naive approach would be checking all elements to the right for each index, which results in **O(n²)** time complexity.

Instead, we can use an **optimal right-to-left traversal**.

### Key Idea

While traversing from the right:

* Keep track of the **maximum element seen so far** (`max_Right`)
* Replace the current element with this maximum
* Update the maximum if the current element is larger

---

## 🚀 Algorithm

1. Initialize `max_Right = -1`.
2. Traverse the array **from right to left**.
3. For each element:

   * Store the current `max_Right` as the answer.
   * Update `max_Right` if the current element is larger.
4. Reverse the result array to maintain original order.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        int max_Right = -1;
        ans.push_back(-1);

        if (arr.size() > 1) {
            for (int i = arr.size() - 1; i > 0; i--) {
                if(arr[i] > max_Right){
                    ans.push_back(arr[i]);
                    max_Right = arr[i];
                }
                else{
                    ans.push_back(max_Right);
                }
            }
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity       | Value    |
| ---------------- | -------- |
| Time Complexity  | **O(n)** |
| Space Complexity | **O(n)** |

---

## 🎯 Key Takeaways

* Instead of checking every element to the right, we **track the maximum while moving backwards**.
* This reduces complexity from **O(n²) → O(n)**.
* This pattern is similar to **Leaders in Array** problems.

---

## 🏷️ Tags

* Array
* Greedy
* Traversal
* Prefix/Suffix Maximum
