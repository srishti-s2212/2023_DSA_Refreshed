#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    bool PairWithGivenSum(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<high)
        {
            if(arr[low]+arr[high]==givenSum)
                return true;
            else if(arr[low]+arr[high]>givenSum)
                high--;
            else
                low++;
        }
        return false;
        
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
    vector<int> arr = {1, 1, 3, 4, 5, 9};
    int sum=7;
    Arrays obj;
    cout<<obj.PairWithGivenSum(arr, sum)<<endl;
    cout<<obj.PairWithGivenSum(arr, 11);
}