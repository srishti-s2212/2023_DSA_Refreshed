#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    bool TripletWithGivenSum(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        
        for(int i=0; i<n-1; i++)
        {
            int low=i+1;
            int high=n-1;
             while(low<high)
            {
                if(arr[i]+arr[low]+arr[high]==givenSum)
                    {
                        cout<<i<<" "<<low<<" "<<high<<endl;
                        return true;
                    }
                else if(arr[i]+arr[low]+arr[high]>givenSum)
                    high--;
                else
                    low++;
            }
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
    vector<int> arr = {1, 2, 3, 4, 5, 9};
    int sum=7;
    Arrays obj;
    cout<<obj.TripletWithGivenSum(arr, sum)<<endl;
    cout<<obj.TripletWithGivenSum(arr, 77);
}