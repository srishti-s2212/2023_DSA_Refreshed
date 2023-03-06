#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    int rotatedSortedArray(vector<int> arr, int x)
    {
        int n=arr.size();
        int pivot = findPivot(arr,n);
        //sorted arr
        if(pivot == -1)
            BinarySearch(arr, 0, n-1, x);
        
        if(arr[pivot]==x)
            return pivot;
        
        if(x<arr[0])
            return BinarySearch(arr, pivot+1, n-1, x);

        else
            return BinarySearch(arr, 0, pivot-1, x);
        
    }

    int findPivot(vector<int> arr, int n)
    {
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid+1])
                return mid;
            if(arr[low]>=arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;

    }
    int BinarySearch(vector<int> arr, int low, int high, int x)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(x==arr[mid])
                return mid;
            if(x>arr[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {5, 6, 7, 1, 2, 3, 4};
    int x=3;
    Arrays obj;
    cout<<obj.rotatedSortedArray(arr, x);
}