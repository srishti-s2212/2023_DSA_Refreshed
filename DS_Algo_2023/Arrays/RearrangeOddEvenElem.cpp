#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    // Given an array arr[] of size N containing equal number of odd and even numbers. Arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index.
    // Note: There are multiple possible solutions, Print any one of them. 
    int rearrangeOddEvem(vector<int> &arr)
    {
        int n=arr.size();
        int evenptr=0;
        int oddptr=1;
        while(evenptr<n && oddptr<n)
        {
            if(arr[evenptr]%2!=0 && arr[oddptr]%2==0)
            {
                swap(arr[evenptr],arr[oddptr]);
                evenptr+=2;
                oddptr+=2;
            }
            else if(arr[evenptr]%2 != 0)
                oddptr+=2;
            else if(arr[oddptr]%2==0)
                evenptr+=2;
            else{
                evenptr+=2;
                oddptr+=2;
            }
        }
        print(arr, n);
    }
    void print(vector<int> &arr, int n)
    {
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
    }
};

int main()
{
    vector<int> arr = {3, 6, 12, 1, 5, 8};
    Arrays obj;
    obj.rearrangeOddEvem(arr);
}