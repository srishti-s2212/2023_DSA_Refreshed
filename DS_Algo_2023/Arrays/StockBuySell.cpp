#include <vector>
#include <iostream>

using namespace std;

class Arrays
{
    public: 
    int maxProfitStockBuySell(vector<int> arr)
    {
        int n=arr.size();
        int minElem=arr[0];
        int maxProfit = arr[1]-arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i]<minElem)
                minElem=arr[i];
            else if(arr[i]-minElem > maxProfit)
                maxProfit=arr[i]-minElem;
            
        }
        return maxProfit;
    }
};

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    Arrays obj;
    cout<<obj.maxProfitStockBuySell(arr);
}