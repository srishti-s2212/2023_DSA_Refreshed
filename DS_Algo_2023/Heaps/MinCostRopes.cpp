#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heaps
{
    public:
    int minCostRopes(vector<int> arr)
    {
        int size = arr.size();
        int ans;
        if(size == 0)
            return ans;
        
        priority_queue<int, vector<int>, greater<int>> minH;
        
        for(int i=0; i<size; i++)
            minH.push(arr[i]);
        int cost=0, sum=0;
        while(minH.size()>1)
        {
            int a = minH.top(); minH.pop();
            int b = minH.top(); minH.pop();
            sum = a + b;
            cost = cost + sum;
            minH.push(sum);
        }
        return cost;
    }
};


int main()
{
    vector<int> arr = {1,2,3,4,5};
    Heaps obj;
    cout<<"Min cost is: "<<obj.minCostRopes(arr);

}
