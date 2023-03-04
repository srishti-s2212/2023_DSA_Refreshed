#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heaps
{
    public:
    vector<int> NearlySortedArray(vector<int> arr, int k)
    {
        int size = arr.size();
        vector<int> ans;
        if(size == 0)
            return ans;
        
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i=0; i<size; i++)
        {
            minH.push(arr[i]);
            if(minH.size() > k)
                {
                    ans.push_back(minH.top());
                    cout<<minH.top()<<endl;
                    minH.pop();
                }
        }
        while(minH.size()>0)
        {
            ans.push_back(minH.top());
            cout<<minH.top()<<endl;
            minH.pop();
        }
        return ans;
    }
};


int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    Heaps obj;
    vector<int> sortedArray = obj.NearlySortedArray(arr, 3);

}
