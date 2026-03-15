18. 4Sum

Problem

Given an integer array "nums" of size "n" and an integer "target", return all unique quadruplets "[nums[a], nums[b], nums[c], nums[d]]" such that:

nums[a] + nums[b] + nums[c] + nums[d] == target

Where:

0 ≤ a, b, c, d < n
a, b, c, and d are distinct

The solution set must not contain duplicate quadruplets.

---

Example

Example 1

Input:

nums = [1,0,-1,0,-2,2]
target = 0

Output:

[
[-2,-1,1,2],
[-2,0,0,2],
[-1,0,0,1]
]

---

Approach

This problem is an extension of the 3Sum problem.

Steps

1. Sort the array
   Sorting helps in:
   
   - Using the two-pointer technique
   - Avoiding duplicates

2. Fix the first two elements
   
   - Use two loops "i" and "j".

3. Use Two Pointers
   
   - "l = j + 1"
   - "r = n - 1"

4. Check the sum

sum = nums[i] + nums[j] + nums[l] + nums[r]

- If "sum == target" → store the quadruplet.
- If "sum < target" → move "l++".
- If "sum > target" → move "r--".

5. Skip duplicates
   - Skip repeated values for "i"
   - Skip repeated values for "j"
   - Skip repeated values for "l" and "r"

---

C++ Implementation

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> v;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int l = j + 1;
                int r = nums.size() - 1;

                while (l < r) {

                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {

                        v.push_back({nums[i], nums[j], nums[l], nums[r]});

                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;

                        l++;
                        r--;
                    }
                    else if (sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }

        return v;
    }
};

---

Dry Run

Input:

nums = [1,0,-1,0,-2,2]
target = 0

Sorted array:

[-2,-1,0,0,1,2]

Valid quadruplets:

[-2,-1,1,2]
[-2,0,0,2]
[-1,0,0,1]

---

Complexity Analysis

Complexity| Value
Time Complexity| O(n³)
Space Complexity| O(1) (excluding result storage)

Explanation:

- Two nested loops + two-pointer search.

---

Key Concepts

- Sorting
- Two Pointer Technique
- Duplicate Handling
- Extension of 3Sum pattern

---

Repository Path

DSA_Interview_Preparation/
└── Arrays/
    └── 18_Four_Sum/
        └── README.md
