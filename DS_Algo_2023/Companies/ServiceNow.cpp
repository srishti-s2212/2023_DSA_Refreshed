// Given m arrays each of length m1, m2, ... Generate all combinations
// e.g. -> 
// arr1 = a1,a2,a3
// arr2 = b1,b2
// arr3 = c1,c2

// generate = (a1,b1,c1), (a1,b1,c2), (a1, b2, c1), ...

#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
    vector<vector<int>> output;
    void allCombinations(vector<vector<int>> v, int m){
        int index = 0;
        vector<int> eachCombo;
        allCombinationsUtil(index, v, m, eachCombo);
            
    }
// arr1 = a1,a2,a3
// arr2 = b1,b2
// arr3 = c1,c2

// generate = (a1,b1,c1), (a1,b1,c2), (a1, b2, c1), ...
    
    
    
    vector<int> allCombinationsUtil(int index, vector<vector<int>> v, int m, vector<int> &eachCombo){

        if(index == m){
           // output.push_back(eachCombo);
            return eachCombo; //{ {{a1, b1, c1}, {a1, b1, c2}, }
        }

        vector<int> temp = v[index]; //{a1, a2, a3}
        for(auto it: temp){ //{c1, c2}, //{a1, b1}
        //Enhancement -> Store state of the indices used in the eachCombo vector so that later if we want to get comination
        //after the lets say xth combo, we can directly use the const positions we had stored in state vector

            eachCombo.push_back(it); // {a1, b1, c1} -> {a1, b1, c2}
            allCombinationsUtil(index+1, v, m, eachCombo); 
            eachCombo.pop_back();// {a1, b1}
        }   
    }

    
 
};

