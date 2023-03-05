#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Strings
{
    public:
    bool AnagramStrings(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        if(n1 != n2)
            return false;

        map<char, int> mp;
        for(int i=0; i<n1; i++)
        {
            mp[str1[i]]++;
            mp[str2[i]]--;
        }
        for(auto it: mp)
        {
            if(it.second != 0)
                return false;
        }
        return true; 
    }
};
int main()
{
    string str1="ate";
    string str2="eat";
    Strings s;
    cout<<s.AnagramStrings(str1, str2);
    cout<<endl<<s.AnagramStrings("abc", "xyz");   
    
}