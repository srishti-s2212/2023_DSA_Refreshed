#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heaps
{
    public:
    int KthLargestElement(vector<int> arr, int k)
    {
        int size = arr.size();
        if(size == 0)
            return -1;
        
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i=0; i<size; i++)
        {
            minH.push(arr[i]);
            cout<<"Insert: "<<arr[i]<<endl;
            if(minH.size() > k)
                {
                    cout<<"Popped: "<<minH.top()<<endl;
                    minH.pop();
                }
        }
        return minH.top();
    }
};


int main()
{
    vector<int> arr = {3, 4, 1, 9, 7};
    Heaps obj;
    cout<<"Kth Largest Element is: "<<obj.KthLargestElement(arr, 2);

}
