#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Arrays
{
    public: 
    //Will work even when we have -ve elements in the array
    int LengthSubArraysWithGivenSum(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        int curr_sum=0;
       
        unordered_map<int, int> mp;
        //int count=0;
        int len=0;
        for(int i=0; i<n; i++)
        {
            curr_sum = curr_sum+arr[i];
            // when subarray starts from index '0'
            if(curr_sum==givenSum)
            {
                //count++;
                len=i+1;
            }

            if (mp.find(curr_sum) == mp.end())
                mp[curr_sum] = i;
            if(mp.find(curr_sum-givenSum)!=mp.end())
            {
                //count=count+mp[curr_sum-givenSum];
                len=max(len, i-mp[curr_sum-givenSum]);
            }
            
            //mp[curr_sum]++;
        }
        return len;
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
    cout<<"Length of subarrays with givenSum: "<<sum<<" is: "<<obj.LengthSubArraysWithGivenSum(arr, sum)<<endl;

    //Will work for -ve elements as well
    //Ans for below array should be 4 
    vector<int> arr2 = {1, -2, 3, 5, 6, 1, -1};
    int sum2=11;
    cout<<"Length of subarrays with givenSum: "<<sum2<<" is: "<<obj.LengthSubArraysWithGivenSum(arr2, sum2)<<endl;

    vector<int> arr3 = {3, 4, 7, 2, -3, 1, 4, 2};
    int sum3=7;
    cout<<"Length of subarrays with givenSum: "<<sum3<<" is: "<<obj.LengthSubArraysWithGivenSum(arr3, sum3)<<endl;

    vector<int> arr4 = {3, 4, 7, 2, -3, 1, 4, 2};
    int sum4=7;
    cout<<"Length of subarrays with givenSum: "<<sum3<<" is: "<<obj.LengthSubArraysWithGivenSum(arr3, sum3)<<endl;
}