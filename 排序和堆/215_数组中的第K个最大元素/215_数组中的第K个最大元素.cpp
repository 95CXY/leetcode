class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> deap;
        for (int n: nums) {
            deap.push(n);
        }
        
        for (int i = 0; i < k-1; ++i) deap.pop();
        return deap.top();
    }
};