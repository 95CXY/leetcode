/*
    给定 nums = [2, 7, 11, 15], target = 9
    由于题目需要返回的是数组的下标，所以用一个unordered_map 来进行反向索引，unordered_map 就是hashtable
    遍历到2的时候，我需要找到 7，此时哈希表里没有7，
    把2哈希到表里，indexNum[ 2 ] = 0, 0为2在数组中的下标，

    继续遍历，7，需要在哈希表里找到2，正好2在哈希表里。 返回2的下标 (indexNum[target - num[i]]), 和 7的下标( 也就是此次的i)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};