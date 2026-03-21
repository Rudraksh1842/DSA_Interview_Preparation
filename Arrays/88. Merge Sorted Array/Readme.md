# 📘 Merge Sorted Array

---

## 🧩 Problem Statement

You are given two sorted arrays `nums1` and `nums2`, and two integers `m` and `n` representing the number of elements in each array respectively.

* `nums1` has a size of `m + n`, where the last `n` elements are empty (0s) and should be filled.
* Merge `nums2` into `nums1` as one sorted array **in-place**.

---

## 📥 Examples

### Example 1

```id="7g4p1h"
Input:
nums1 = [1,2,3,0,0,0], m = 3  
nums2 = [2,5,6], n = 3  

Output:
[1,2,2,3,5,6]
```

---

### Example 2

```id="c8t0z3"
Input:
nums1 = [1], m = 1  
nums2 = [], n = 0  

Output:
[1]
```

---

### Example 3

```id="m2v8g1"
Input:
nums1 = [0], m = 0  
nums2 = [1], n = 1  

Output:
[1]
```

---

## ⚙️ Constraints

```id="j3f9k2"
0 <= m, n <= 200  
1 <= m + n <= 200  
-10^9 <= nums1[i], nums2[i] <= 10^9
```

---

## 🧠 Approach 1 (Your Approach: Copy + Sort)

### 💡 Idea

* Copy all elements of `nums2` into `nums1`
* Then sort the entire array

---

## 🚀 Algorithm

```id="q1x7r9"
Copy nums2 into nums1 starting from index m  
Sort nums1  
```

---

## 💻 Code (C++)

```cpp id="p9k2d4"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < nums1.size() && j < nums2.size(); i++, j++){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};
```

---

## ⚠️ Important Note

Your loop condition:

```id="z4y8n2"
i < nums1.size(), j < nums2.size()
```

👉 Uses **comma operator**, so only `j < nums2.size()` is checked ❌

✅ Correct version:

```id="k8r3p5"
i < nums1.size() && j < nums2.size()
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O((m + n) log(m + n))
* **Space Complexity:** O(1) (in-place)

---

## 🚀 Optimal Approach (Two Pointers from End)

### 💡 Key Idea

* Start filling from the **end of nums1**
* Compare largest elements and place correctly

---

## 💻 Optimal Code

```cpp id="w5s9x1"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};
```

---

## 🧪 Dry Run

```id="d7k2p8"
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

Start from end:
Compare 3 and 6 → place 6  
Compare 3 and 5 → place 5  
Compare 3 and 2 → place 3  
...
```

---

## 🔥 Key Takeaways

* Your approach works but is not optimal
* Best solution uses **two pointers from end**
* Avoid shifting elements → fill from back

---

## 🚀 Related Problems

* Merge Intervals
* Two Sum (Two Pointer Variant)
* Sorted Array Problems

---

⭐ Must-know problem for interviews (Amazon, Microsoft, etc.)
