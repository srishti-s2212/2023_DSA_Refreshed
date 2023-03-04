#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        priority_queue<pair<int, int>> maxh;
        for(auto it: mp)
            maxh.push({it.second, it.first});
        
        vector<int> ans;
        if(k>nums.size())
            return ans;

        for(int i=0; i<k; i++)
        {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};