# 31. Next Permutation

## 🔗 Problem Link

LeetCode - 31. Next Permutation

---

## 🧠 Problem Statement

Implement the **next permutation**, which rearranges numbers into the **lexicographically next greater permutation** of numbers.

If such an arrangement is not possible, it must rearrange it as the **lowest possible order (sorted in ascending order)**.

The replacement must be **in-place** and use **only constant extra memory**.

---

## 📌 Example 1

Input:

```
nums = [1,2,3]
```

Output:

```
[1,3,2]
```

---

## 📌 Example 2

Input:

```
nums = [3,2,1]
```

Output:

```
[1,2,3]
```

---

## 📌 Example 3

Input:

```
nums = [1,1,5]
```

Output:

```
[1,5,1]
```

---

## 💡 Approach

To generate the next permutation:

1. Traverse from the end and find the **first index `i` where `nums[i] < nums[i+1]`**.
   This index is called the **pivot**.

2. If such an index exists, find the **smallest element greater than `nums[i]`** to the right of it.

3. **Swap** these two elements.

4. **Reverse the suffix** starting from `i + 1` to the end of the array.

If no pivot exists (the array is in descending order), simply **reverse the entire array**.

---

## 🚀 Algorithm

1. Start from the second last element and move left.
2. Find the first decreasing element.
3. Swap it with the next larger element on the right.
4. Reverse the remaining suffix to get the smallest order.

---

## 🧾 Implementation

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());

        if(index==-1){
            reverse(nums.begin(),nums.end());
        }

        if(index==n-2){
            swap(nums[n-2],nums[n-1]);
        }
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity       | Value    |
| ---------------- | -------- |
| Time Complexity  | **O(n)** |
| Space Complexity | **O(1)** |

---

## 🎯 Key Takeaways

* The next permutation must be **just slightly greater** than the current one.
* The suffix after the pivot is always **in decreasing order**.
* Reversing the suffix ensures we get the **smallest possible permutation** after swapping.

---

## 🏷️ Tags

* Array
* Two Pointers
* Greedy
* Permutation
