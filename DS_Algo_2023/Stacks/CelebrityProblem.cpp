#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Stacks
{
    public:
     int findCelebrityEfficient(vector<vector<int>> mat)
    {
        int n=mat.size();
        int a =0;
        int b=n-1;
        while(a<b)
        {
            if(mat[a][b]==1)
                a++;
            else
                b--;
        }
        int ans = b;
        for(int i=0; i<n; i++)
        {
            if(mat[b][i]==1)
                return -1;
        }
        return ans;
    }
    int findCelebrity(vector<vector<int>> mat)
    {
        int n=mat.size();
        stack<int> st;
        for(int i=0; i<n; i++)
            st.push(i);
        while(st.size()>1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(knows(a,b, mat))
                st.push(b);
            if(knows(b,a, mat))
                st.push(a);
        }
        int ans = st.top();
        for(int i=0; i<n; i++)
        {
            if(mat[ans][i]==1)
                return -1;
        }
        return ans;
    }
    bool knows(int a, int b, vector<vector<int>> mat)
    {
        return (mat[a][b]==1);
    }
};

int main()
{
    vector<vector<int>> mat = {{0,1,0},{0,0,0},{0,1,0}};
    Stacks obj;
    cout<<obj.findCelebrity(mat)<<endl;
    cout<<"Efficient Approach: "<<obj.findCelebrityEfficient(mat);
}