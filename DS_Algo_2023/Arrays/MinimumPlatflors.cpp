#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Arrays
{
    public: 
    int minPlatflorms(vector<int> arr, vector<int> dep)
    {
        int n=arr.size();
        int i=1, j=0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int count=1;
        int platforms=1;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j])
            {
                count++;i++;
            }
            else if(arr[i]>dep[j])
            {
                count--; j++;
            }
            platforms=max(platforms, count);
        }  
        return platforms;   
    }
};

int main()
{
    vector<int> arr = {900, 1100, 1235};
    vector<int> dep = {1000, 1200, 1240};
    int sum=6;
    Arrays obj;
    cout<<obj.minPlatflorms(arr, dep)<<endl;
}