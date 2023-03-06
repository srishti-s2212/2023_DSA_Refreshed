#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    int maxSumSubarray(vector<int> arr)
    {
        int n=arr.size();
        int maxEnding = arr[0];
        int res=0;
        for(int i=1; i<n; i++)
        {
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res=max(res, maxEnding);
        }
        return res;
    }
};

int main()
{
    vector<int> arr = {2, 3, -8, -7, -1, 2, 3};
    Arrays obj;
    cout<<obj.maxSumSubarray(arr);
}