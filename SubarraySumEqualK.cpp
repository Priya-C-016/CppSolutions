class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // to count subarrays that start from index 0

        int count = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            prefixSumCount[sum]++;
        }

        return count;
    }
};
