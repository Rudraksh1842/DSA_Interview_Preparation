# 📘 Merge Intervals

---

## 🧩 Problem Statement

Given an array of intervals where `intervals[i] = [start, end]`, merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals.

---

## 📥 Examples

### Example 1

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]  
Output: [[1,6],[8,10],[15,18]]
```

### Example 2

```
Input: intervals = [[1,4],[4,5]]  
Output: [[1,5]]
```

---

## ⚙️ Constraints

```
1 <= intervals.length <= 10^4  
intervals[i].length == 2  
0 <= start <= end <= 10^4
```

---

## 🧠 Approach (Greedy + Sorting)

### 💡 Key Idea

* Overlapping intervals can only be detected if intervals are **sorted by start time**
* Maintain a **current interval**
* Merge if overlapping, otherwise push to result

---

## 🔑 Steps

1. Sort the intervals based on start time
2. Initialize `current` interval as the first interval
3. Traverse remaining intervals:

   * If overlapping:

     ```
     intervals[i][0] <= current[1]
     ```

     → Merge by updating end
   * Else:
     → Push current interval to result
     → Update current
4. Push the last interval

---

## 🚀 Algorithm

```
Sort intervals

curr = intervals[0]

for each interval:
    if overlap:
        curr.end = max(curr.end, interval.end)
    else:
        add curr to result
        curr = interval

add last curr to result
```

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= curr[1]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }

        res.push_back(curr);

        return res;
    }
};
```

---

## 🧪 Dry Run

### Input:

```
[[1,3],[2,6],[8,10],[15,18]]
```

### After Sorting:

```
[[1,3],[2,6],[8,10],[15,18]]
```

### Merging:

```
[1,3] + [2,6] → [1,6]  
[8,10] → separate  
[15,18] → separate
```

### Output:

```
[[1,6],[8,10],[15,18]]
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n log n) (sorting)
* **Space Complexity:** O(n) (result array)

---

## 🔥 Key Takeaways

* Always **sort intervals first**
* Use **greedy merging**
* Maintain a **running interval**

---

## 🚀 Related Problems

* Insert Interval
* Meeting Rooms I & II
* Non-overlapping Intervals

---

⭐ This is a **must-know greedy pattern** for interviews!
