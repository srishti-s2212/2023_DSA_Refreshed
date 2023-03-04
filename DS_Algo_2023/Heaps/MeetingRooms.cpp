#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct cmp1{
    bool operator()(vector<int>& v1, vector<int>& v2) {
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
};

struct cmp2{
    bool operator()(vector<int>& v1, vector<int>& v2) {
        return (v1[1] > v2[1]) || (v1[1] == v2[1] && v1[0] > v2[0]);
    }
};

class Heaps {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

         int n = intervals.size();
        if(n <= 1) return n;
        sort(intervals.begin(), intervals.end(), cmp1());
        int minRooms = 0;
        priority_queue<vector<int>, vector<vector<int>>, cmp2> pq; // min_heap
        pq.push(intervals[0]);
        for(int i = 1; i < n; i++){
            if(pq.top()[1] <= intervals[i][0]){
                pq.pop();
            }
            pq.push(intervals[i]);
            minRooms = max(minRooms, (int)pq.size());
        }
        return minRooms;
        
    }
};

int main()
{
    vector<vector<int>> arr = {{0,30}, {5,10}, {15,20}};
    Heaps obj;
    cout<<"Min rooms required is: "<<obj.minMeetingRooms(arr);

}