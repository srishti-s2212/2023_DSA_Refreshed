#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    //2pointer approach does not work when we have -ve elements in the array
    int longestSubArrayWithGivenSum(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        int curr_sum=0;
        int start=0, i=0;
        int longestSubarrLength=0;
        while(i<n)
        {
            curr_sum=curr_sum+arr[i];
            if(curr_sum == givenSum)
            {
                longestSubarrLength=max(longestSubarrLength, i-start+1);
                i++;
            }
            else if(curr_sum<givenSum)
                i++;
            else
            {
                curr_sum=0;
                start++;
                i=start;
            }
        }
        return longestSubarrLength;
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
    vector<int> arr = {1, 2, 3, 5, 6, 1};
    int sum=6;
    Arrays obj;
    cout<<"Length is: "<<obj.longestSubArrayWithGivenSum(arr, sum)<<endl;

    //Does not work for -ve elements
    //Ans for below array should be 4 but we get ans as 2
    vector<int> arr2 = {1, -2, 3, 5, 6, 1, -1};
    int sum2=11;
    cout<<"Length is: "<<obj.longestSubArrayWithGivenSum(arr2, sum2);
}