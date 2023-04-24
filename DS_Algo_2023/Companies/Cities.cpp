#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
// class Solution
// {
// //     [["B","C"],["D","B"],["C","A"]]
// // Output: "A"
//     public:
//     char findCity(vector<pair<char, char>> cities){
//         char ans;
//         unordered_map<char, int> indegree;
//         unordered_map<char, int> outdegree;
//         for(auto it: cities){
//             char src = it.first;
//             char dest = it.second;
//             indegree[dest]++; //C->1, B->1, A->1
//             outdegree[src]++; //B->1, D->1, C-> 1
//         }
//         for(auto it: indegree){
//             if(outdegree.find(it.first) == outdegree.end())
//                 ans = it.first;
//         }
//         return ans;

//     }
// };

// int main(){
//     vector<pair<char, char>> cities = {{'B','C'}, {'D','B'},{'C','A'}};
//     Solution obj;
//     cout<<"City without any outgoing path: "<<obj.findCity(cities);

// }

// Consider a long alley with a N number of doors on one side. All the doors are closed initially. You move to and from in the alley changing the states of the doors as follows: you open a door that is already closed, and you close a door that is already opened. You start at one end go on altering the state of the doors till you reach the other end and then you come back and start altering the states of the doors again.
// In the first go, you alter the states of doors numbered 1, 2, 3,4...n. //1, 4, 7, 10
// In the second go, you alter the states of doors numbered 2, 4, 6, 8, 10....n
// In the third go, you alter the states of doors numbered 3, 6, 9...n
// You continue this till the Nth go in which you alter the state of the door numbered N.
// You must find the number of open doors at the end of the procedure.
// Example 1:
// Input:
// N = 2
// Output:
// 1
// Explanation:
// Initially all doors are closed.
// After 1st go, all doors will be opened.
// After 2nd go second door will be closed.
// So, only 1st door will remain Open.
// Example 2:
// Input:
// N = 4
// Output:
// 2
// Explanation:
// Following the sequence 4 times, we can
// see that only 1st and 4th doors will
// remain open.

class Solution{
    public:
    int findOpenDoors(int n){
    vector<bool> doors(n, false);
    //int n = doors.size();

    int ithGo;
    bool flag = true;;
    for(ithGo=1; ithGo <= n; ithGo+=3){
        if(flag == true);
        cout<<endl<<"First Go: ";
        for(auto it: doors){
            it = !it; 
            cout<<it<<" ";       
        }
        flag = !flag;
        cout<<endl<<"2nd Go - Multiple of 2: ";
        for(int i=n-1; i>0; i--){
            if(i%2 == 0)
                doors[i] = !doors[i];  
            cout<<doors[i]<<" ";                      
        }

        cout<<endl<<"3rd Go - Multiple of 3: -";
        for(int i=1; i<n; i++){
            if(i%3 == 0)
                doors[i] = !doors[i];
            cout<<doors[i]<<" ";                           
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(doors[i] == true)
            count++;
    }
    cout<<endl<<"No of open doors: "<<count;
    return count;
}      
};

int main(){
    Solution obj;
    obj.findOpenDoors(2);
}

