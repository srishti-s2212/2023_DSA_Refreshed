#include<iostream>
#include<vector>

using namespace std;

//Round 2: Raghavendra
//I/P: 
// arr1 = {1, 2, 3}
// arr2 = {4, 5}
// arr3 = {3, 7, 10, 11}

// {{1, 4, 3}, }{1, 4, 7}...

// {1, 2, 3, 4}
//Sum=6

// {1, 2, 3, 4, 5}
// maxSum: 9

// class Solution{
//     public:
//     int maxSumAlternateElements(vector<int> arr){
//         int n = arr.size();
//         vector<int> dp(n, 0);
//         dp[n-1] = arr[n-1]; // 3
//         dp[n-2] = arr[n-2]; //5
        
//         int maxTillNow = arr[n-1];

//         //{1, 2, 3, 4, 5, 1, 2, 4, 5, 3};
// //         dp{16, 14, 15,12, 12, 8, 7, 7, 5, 3}
// //  maxTilNow{15  15, 12,12, 8, 7, 7  5    3}
//         //dp[9] = 3, dp[8]=5, dp[7]=7, dp[6]

//         for(int i=n-3; i>=0; i--){
//             dp[i] = arr[i] + maxTillNow; //4+3=7, 2+5=7, 1+7=8, 5+7=12, 4+8=12, 3+12=15, 2+12=14, 1+15=16
//             //cout<<dp[i]-maxTillNow<<" ";
//             maxTillNow = max(maxTillNow, dp[i+1]); //max(3, 5)=5, max(5,7)=7, max(7, 7)=7, max(7, 8)=8, max(8, 12)=12
//             //max(12, 12)=12, max(12,15)=15, max(15, 14)=15
//         }

//         int maxSum = 0;
//         cout<<endl<<"DP Array: ";
//         for(int i=0; i<n; i++){
//             cout<<dp[i]<<" ";
//             maxSum = max(maxSum, dp[i]);
//         }


//         cout<<"Max sum is: "<<maxSum;
//         return maxSum;

//     }
// };

// int main(){
//         //vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
//         vector<int> arr = {100,200,3,4,500,5,60,500,2};

//         Solution obj;
//         obj.maxSumAlternateElements(arr);
// }


// str="abacttcytxmpop"
// ababa ctt
// aba

// map<string, int>
// mp[substr] = i
// nextItr = i+1;

// map<string, int> --> substr, i -> 0, 
// stack<string>

// countPop++ --> 3
// j(2) - countPop(2) + 1


// st->ab ->string str
// pop->ba -> string rev
// str == rev




