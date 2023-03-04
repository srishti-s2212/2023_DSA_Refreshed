#include <iostream>
#include <queue>

using namespace std;

class Heaps
{
    public:
    priority_queue<double, vector<double>, greater<double>> minH;
    priority_queue<double> maxH; 
    void addNum(int num) {
        if(maxH.size()==0 || num<=maxH.top())
            maxH.push(num);
        else
            minH.push(num);
        
        balanceHeap();
            
    }
    void balanceHeap()
    {
        if(maxH.size() > minH.size()+1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(minH.size() > maxH.size()+1)
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size())
            return ((maxH.top() + minH.top())/2);
        
        else if(maxH.size() > minH.size())
            return maxH.top();
        else
            return minH.top();

    }
};