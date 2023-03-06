#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    bool subArrayWithGivenSum(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        int curr_sum=0;
        int start=0, i=0;
        while(i<n)
        {
            curr_sum=curr_sum+arr[i];
            if(curr_sum == givenSum)
                return true;
            else if(curr_sum<givenSum)
                i++;
            else
            {
                curr_sum=0;
                start++;
                i=start;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum=9;
    Arrays obj;
    cout<<obj.subArrayWithGivenSum(arr, sum);
}