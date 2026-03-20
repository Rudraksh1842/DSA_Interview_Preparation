class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // Step 1: build prefix XOR
        vector<int> prefix(n);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        // Step 2: answer queries
        vector<int> res;

        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];

            if(left == 0){
                res.push_back(prefix[right]);
            } else {
                res.push_back(prefix[right] ^ prefix[left - 1]);
            }
        }

        return res;
    }
};
