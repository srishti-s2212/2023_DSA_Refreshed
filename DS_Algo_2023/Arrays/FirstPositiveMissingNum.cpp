#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Arrays
{
    public: 
    int firstPositiveMissingNum(vector<int> arr)
    {
        int n=arr.size();
        
        //Handle -ve by replacing -ve and 0 value with n+1
        for(int i=0; i<n; i++)
            if(arr[i]<=0)
                arr[i]=n+1;
        
        for(int i=0; i<n; i++)
        {
            int value = abs(arr[i]);
            // cout<<"arr[i]: "<<arr[i]<<endl;
            // cout<<"value: "<<value<<endl;

            //To ensure we dont check the -ve values that were replaced
            //with n+1
            if(value>0 && value<=n)
                arr[value-1]=-1*abs(arr[value-1]);
        }
        for(int i=0; i<n; i++)
            if(arr[i]>0)
                return i+1;
        return n+1;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4};
    vector<int> arr2 = {-1, 3, 2, 1};
    Arrays obj;
    cout<<obj.firstPositiveMissingNum(arr)<<endl;
    cout<<obj.firstPositiveMissingNum(arr2)<<endl;
}