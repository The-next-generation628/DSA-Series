#include <iostream>
using namespace std;

int main() {
   // declaring an array of 5 integers
    int arr[5];
   
   // taking input from the user
    cout << "Enter 5 elements: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
   // displaying the elements of the array
    cout << "You entered: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout<<"array element at index 2 is: "<<arr[2]<<endl; // accessing an element at index 2

    return 0;
}


    // declaring and initiating an array of 5 integers
    /*
    int main(){
    int arr[5] = {1, 2, 3, 4, 5};
      // displaying the elements of the array
      cout << "Array elements: ";
      for(int i = 0; i < 5; i++) {
         cout << arr[i] << " ";
   }
    }
    */

    // basic errors

      /*
      int main(){
      int arr[5] = {1, 2, 3, 4, 5, 4 }; // Error: too many initializers for array of size 5

      int array[5] ={1,2,3,"x",5}; // Error: incompatible type for array element
      */