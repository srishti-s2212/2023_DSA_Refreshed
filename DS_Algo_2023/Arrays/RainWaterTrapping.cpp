#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    int trappingRainWater(vector<int> arr)
    {
        int n=arr.size();
        int trappedWater = 0;
        vector<int> lmax(n,0), rmax(n,0);
        lmax[0]=arr[0];
        rmax[n-1]=arr[n-1];
        for(int i=1; i<n; i++)
            lmax[i]=max(lmax[i-1], arr[i]);
        
        for(int i=n-2; i>=0; i--)
            rmax[i]=max(rmax[i+1], arr[i]);
        
        for(int i=0; i<n; i++)
            trappedWater = trappedWater + min(lmax[i], rmax[i])-arr[i];
        
        return trappedWater;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 4, 0, 1, 3, 2};
    Arrays obj;
    cout<<obj.trappingRainWater(arr);
}