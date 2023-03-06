#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    void reverseSubarrays(vector<int> arr, int k)
    {
        int n=arr.size();
        for(int i=0; i<n; i+=k)
        {
            int low=i;
            int high=i+k-1;
            if(high>=n)
                high=n-1;
            reverse(arr, low, high);
        }
        print(arr);
    }
    void reverse(vector<int> &arr, int low, int high)
    {
        while(low<high)
        {
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
    void print(vector<int> arr)
    {
        int n=arr.size();
        for(int i=0; i<n; i++)
            cout<<arr[i];
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    Arrays obj;
    obj.reverseSubarrays(arr, k);
}