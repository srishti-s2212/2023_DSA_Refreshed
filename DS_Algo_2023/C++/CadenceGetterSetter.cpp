#include <iostream>

using namespace std;

//Create Entity Class
//with paramaters like name, emailid, address, pan, age, phno
//User should be able to initialize/create obj with any number of parameters

//Approach 1: Create Parameterized Constructor for each permutation
//But with this we will have many many constructor
//or else if we call different methods, we repeat methods
//eg Entity obj1; obj1.method1(); obj1.method2(); obj1.method3()
//Approach 2: Object Chaining, getting and setting value
//Maintain order
class Entity
{
public:
    string emailid;
    string name;
    int phno;
    string address;
    int age;
    int panid;

    Entity() //Default Constructor
    {
    emailid = "";
    } 
    Entity(string id) //Parameterized constructor
    {
    emailid = id;
    }

    int initialize(const Entity &object);

    //Setting Email ID
    Entity& setEmailId(string emailid)
    {
    this->emailid=emailid;
    return *this;
    }
    //Setting Ph No
    Entity& setPhNo(int phno)
    {
    this->phno=phno;
    return *this;
    }


};

int main()
{
    Entity entity;
    //This is called Method Chaining
    entity.setEmailId("srishti@gmail.com").setPhNo(98300);
    return 0;
}