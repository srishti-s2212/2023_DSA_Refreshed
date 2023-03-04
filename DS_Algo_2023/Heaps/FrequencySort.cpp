#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Heaps
{
    public:
    vector<int> frequencySort(vector<int> arr)
    {
        int size = arr.size();
        vector<int> v;
        if(size <= 0)
            return v;

        //Map to store elem -> freq
        unordered_map<int, int> mp;

        priority_queue<pair<int, int>> maxh;

        //Inserting elements to Map to store elem -> freq
        for(int i=0; i<size; i++)
            mp[arr[i]]++;
        
        //Inserting elements to maxHeap to store freq -> elem
        for(auto it: mp)
            maxh.push({it.second, it.first});

        while(maxh.size() > 0)
        {
            pair<int, int> top = maxh.top();
            int freq = top.first;
            int elem = top.second;
            maxh.pop();
            for(int i=0; i<freq; i++)
                v.push_back(elem);
        }
        return v;
    }

    void printElements(vector<int> v)
    {
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";
    }

};

int main()
{
    Heaps heaps;
    vector<int> inputArr = {4, 4, 5, 10, 10, 10, 3, 3, 3, 3};
    vector<int> sortedArr = heaps.frequencySort(inputArr);
    heaps.printElements(sortedArr);
    return 0;
}