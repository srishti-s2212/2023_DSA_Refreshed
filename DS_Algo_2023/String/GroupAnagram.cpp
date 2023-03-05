#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Strings
{
    public:
    vector<vector<string>> groupAnagrams(vector<string> arr)
    {
        int n = arr.size();
        map<string, vector<string>> mp;
        for(int i=0; i<n; i++)
        {
            string tempString = arr[i];
            sort(tempString.begin(), tempString.end());
            mp[tempString].push_back(arr[i]);
        }
        vector<vector<string>> groupedAnagrams;
        for(auto it: mp)
        {
            groupedAnagrams.push_back(it.second);
        }
        return groupedAnagrams;
    }
};
int main()
{
    vector<string> arr = {"cat", "rat", "tac", "tar", "ate", "eat"};
    Strings s;
    vector<vector<string>> ans = s.groupAnagrams(arr);
    for(int i=0; i<ans.size(); i++)
    {
        for(auto it: ans[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}