#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Strings
{
    public:
    char leftmostRepeatingChar(string str)
    {
        int n=str.size();
        bool visited[256];
        memset(visited, false, sizeof(visited));

        int leftmostCharIndex;
        for(int i=n-1; i>=0; i--)
        {
            if(visited[str[i]]==false)
                visited[str[i]]=true;
            else    
                leftmostCharIndex = i;
        }
        return str[leftmostCharIndex];

    }
};

int main()
{
    string str="bcaddc";
    Strings string;
    cout<<string.leftmostRepeatingChar(str);
}