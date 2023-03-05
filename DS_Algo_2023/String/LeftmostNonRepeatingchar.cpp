#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Strings
{
    public:
    char leftmostNonRepeating(string str)
    {
        int n = str.size();
        
        unordered_map<char, int> mp;

        char ans;
//Time and space complexity same but requires one traversal
       for(int i=n-1; i>=0;i--){
        mp[str[i]]++;
        if(mp[str[i]]==1)
           ans=str[i]; 
       } 
       return ans; 

//Another approach - needs 2 traversals
    //    for(int i=0; i<n;i++)
    //         mp[str[i]]++;

    //     for(auto it: mp)
    //     {
    //         if(it.second == 1)
    //             return it.first;
    //     }
       
    //    return ans; 

    }
};
int main()
{
    string str1="abccdea";
    Strings s;
    cout<<s.leftmostNonRepeating(str1);    
}