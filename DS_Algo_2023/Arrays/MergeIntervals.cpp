#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Arrays
{
    public: 
    vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
    {
        int n=intervals.size();
        vector<vector<int>> mergedIntervals;
        if(n==0)
            return mergedIntervals;
       
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        for(auto it: intervals)
        {
            if(tempInterval[1]>=it[0])
                tempInterval[1]=max(tempInterval[1], it[1]);
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            } 
        }
        mergedIntervals.push_back(tempInterval);
        print(mergedIntervals);
        return mergedIntervals;        
    }
    void print(vector<vector<int>> mergedIntervals)
    {
        for(int i=0; i<mergedIntervals.size(); i++)
        {
            for(int j=0; j<mergedIntervals[i].size(); j++)
            {
                cout<<mergedIntervals[i][j]<<" ";
            }
            cout<<endl;
        }

    }
};

int main()
{
    vector<vector<int>> arr = {{1,3}, {8,10}, {2,6},{8,9},{9,11}, {15,18}, {2,4}, {16,17}};
    Arrays obj;
    obj.mergeIntervals(arr);
}