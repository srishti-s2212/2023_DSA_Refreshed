 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

// class Solution{
//     public:
//     void display(){
//         cout<<"In Solution Class";
//     }
// };

// class Child: public Solution{
//     public:
//     void display(){
//         cout<<"In Child Class";
//     }
// };

// int main(){
//     Solution obj;
//     obj.display();

//     Child obj2;
//     obj2.display();

//     Solution obj3 = new Child();
//     obj3.display();

//     return 0;
// }

// int main(){
//     int* arr; //Array 1D

//     //4*2 matrix _create

//     int arr[4];
//     int rows = 4;
//     int cols = 2;

//     int[][] matrix = new int(rows, cols); //Allocate and Deallocate matrix in heap
//     //Destructors, Virtual constructor and destructors
//     //Padding in C++
//     //Abstraction
//     //
// }

// class A
// {
// 		int a; //Size of Class: 4
// 		public:
// 		virtual void disp()
// 		{
// 			cout<<"Disp of A\n";
// 		}
// };
//Ptr: 8
//Size: 16

// Time Complexity
// map
// Sorting Algoritm

class product
{
    public:
    int id;
    int weight;
};

void printIds(int arr[], int n, int remainingWeight){
    // i -> 0->n
    //  j -> i+1 ->n
    //     v
// //{2, 4, 1, 6, 5}, remainingW = 11
// //sort: {1, 2, 4, 5, 6}
// 1. low = 0, high = 4, sum = 7, 7<11? => low++ -> low = 1
// 2. low = 1, high = 4, sum = 2+5 = 8, 8<11? Yes => low++-> low = 2


// //int arr1[] = {0, 5, 2, 5, 5};
    if(n < 2)
        cout<<"Invalid Input";
    //Most Efficient: unordered map -> O(n) -> uses hasing in the backend
    sort(arr, arr+n);
    int low = 0; 
    int high = n-1;

    while(low < high){
        int mid = (low + high)/2;
        int sum = arr[low] + arr[high];
        if(remainingWeight == sum){
            cout<<"Item found at indices "<<low<<" and "<<high;
            return;
        }
        if(sum > remainingWeight){
            high--; //high = mid+1
        }
        else
            low++;       
    }
    cout<<"No weight found";
}

int main(){
    int arr1[] = {0, 5, 2, 5, 5};
    int arr2[] ={2, 4, 1, 6, 5};
    int remainingSum = 4;

    //printIds(arr1, 5, remainingSum);
    printIds(arr2, 5, 11);
}