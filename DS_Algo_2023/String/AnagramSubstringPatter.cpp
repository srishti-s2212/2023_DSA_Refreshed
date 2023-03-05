#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Strings
{
    public:
    vector<int> AnagramSubstringPattern(string str, string pattern)
    {
        int n1 = str.size();
        int n2 = pattern.size();
        vector<int> ans;
        if(n2 > n1)
            return ans;

        vector<int> mp_str(26, 0);
        vector<int> mp_pat(26, 0);
        
        int right=0, left=0;
        for(right=0; right<n2; right++)
        {
            mp_str[str[right]-'a']++;
            mp_pat[pattern[right]-'a']++;
        }
        right--;
        while(right<n1)
        {
            if(mp_str == mp_pat)
            {
                cout<<"Anagram patter present at index: "<<left<<endl;
                ans.push_back(left);
            }
            
            right++;
            if(right<n1)
                mp_str[str[right]-'a']++;
            
            mp_str[str[left]-'a']--;
            left++;
        }
        return ans;       
    }
};
int main()
{
    // string str1="geeksforgeeks";
    // string str2="forg";
    string str1="abcdebacb";
    string str2="acb";
    Strings s;
    s.AnagramSubstringPattern(str1, str2);    
}