#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;


// Given a list of events, represented by their start and end times, generate the data points to show the number of live events for following intervals:
// per hour
// 30 minutes
// 10 minutes
// 5 minutes
// minute. 

// Ex: Input: 
// Events: [(1,4), (1,5),(2,3),(2,5)]

// Output:
// Hourly(24 data points): [0,2,4,3,2,0,...

// Explanation: 
// no events from 0 to 1. 
// 2 events start from 1 so for interval 1 to 2 count is 2.
// 2 more events start from 2 so for 2-3 count is 4.
// No new events from 3 but 1 event ends at 3 so for 3-4 co
// No new events from 3 but 1 event ends at 3 so for 3-4 count = 4+0-1 = 3

// O(nEvents*maxIntervals)

// void segmentTree(vector<pair<int, int>> events){
//     vector<int> v;
//     for(auto it: events){
//         // Case 1: counterStartTime
//         // Case 2: Ongoing = i>startTime && i<endtime

//         for(int i=it.first; i<it.second; i++)
//                 v[i] = v[i] + 1;
//     }

// }

//More Efficient: Use Interval Tree

// Ex: Input: 
// Events: [(1,4), (1,5),(2,3),(2,5)]

// Output:
// Hourly(24 data points): [0,2,4,3,2,0,...
class Solution{
    public:
    void intervalTree(vector<pair<int, int>> events){
    vector<int> v(24, 0);

    for(auto it: events){
        v[it.first]++; //1->1, 1->2, 2->1
        v[it.second]--; //4->-1, 5->-1, 3->-1,
    }
    for(int i=1; i<=24; i++){
        v[i] = v[i] + v[i-1];
        cout<<v[i]<<" "; //Interval Tree
    }
} 
};

int main(){
    vector<pair<int, int>> events = {{1,4}, {1,5}, {2,3}, {2,5}};
    Solution obj;
    obj.intervalTree(events);
    return 0;
}




