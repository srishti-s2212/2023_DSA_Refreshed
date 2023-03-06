#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Arrays
{
    public: 
    //Will work even when we have -ve elements in the array
    int CountSubArraysWithGivenSum(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1; i<n; i++)
            prefix[i]=prefix[i-1]+arr[i];
        
        unordered_map<int, int> mp;
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(prefix[i]==givenSum)
                count++;
            
            if(mp.find(prefix[i]-givenSum)!=mp.end())
                count=count+mp[prefix[i]-givenSum];
            
            mp[prefix[i]]++;
        }
        return count;
    }
    int CountSubArraysWithGivenSum2(vector<int> arr, int givenSum)
    {
        int n=arr.size();
        int curr_sum=0;
       
        unordered_map<int, int> mp;
        int count=0;
        for(int i=0; i<n; i++)
        {
            curr_sum = curr_sum+arr[i];
            if(curr_sum==givenSum)
                count++;
            
            if(mp.find(curr_sum-givenSum)!=mp.end())
                count=count+mp[curr_sum-givenSum];
            
            mp[curr_sum]++;
        }
        return count;
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
    cout<<"Count of subarrays with givenSum: "<<sum<<" is: "<<obj.CountSubArraysWithGivenSum(arr, sum)<<endl;

    //Will work for -ve elements as well
    //Ans for below array should be 4 
    vector<int> arr2 = {1, -2, 3, 5, 6, 1, -1};
    int sum2=11;
    cout<<"Count of subarrays with givenSum: "<<sum2<<" is: "<<obj.CountSubArraysWithGivenSum(arr2, sum2)<<endl;

    vector<int> arr3 = {3, 4, 7, 2, -3, 1, 4, 2};
    int sum3=7;
    cout<<"Count of subarrays with givenSum: "<<sum3<<" is: "<<obj.CountSubArraysWithGivenSum(arr3, sum3)<<endl;

    vector<int> arr4 = {3, 4, 7, 2, -3, 1, 4, 2};
    int sum4=7;
    cout<<"Count of subarrays with givenSum: "<<sum3<<" is: "<<obj.CountSubArraysWithGivenSum2(arr3, sum3)<<endl;
}