#include <iostream>
#include <cstring>

using namespace std;

class myString
{
    private:
    char* res; //initialized an array of char i.e. string
    unsigned int len;
    public:
    myString() //User created Default Constructor
    {
        res=NULL;
        len=0;
    }
    myString(char* a) //Parameterized Constructor
    {
        len=strlen(a);
        res=new char[len++];
        strcpy(res, a);
    }
    myString(const myString &str) //Copy Constructor
    {
        len=str.len;
        res=new char[len++];
        strcpy(res, str.res);
    }

    myString& operator=(const myString &str)
    {
        if(this!=&str)
        {
            char* temp=this->res;
            len=str.len;
            res=new char[len++];
            strcpy(res, str.res);
            delete[] temp;
        }
        return *this;
    }
    friend ostream& operator <<(ostream& out, string &str);    
};
// ostream& operator <<(ostream& out, string &str)
//     {
//         out<<str.res;
//         return out;
//     }

int main()
{
    myString obj1; //User defined default constructor
    //myString obj2('a'); //Just 'a' as char wont work as paramterized construc
    //takes array of char as input i.e. pass string as input
    myString obj2("Srishti"); //Parameterized Constructor
    myString obj3(obj2); //Copy Constructor
    myString obj4 = obj2; //Overloaded = operator i.e. Copy assignement operator
    // Similar to Copy Constructor
}