/******************************************************************************
Name: Evan Whitmer
Class: CSC 145A
Date: February 17, 2023
Description: Finding the k-th smallest in an integer array of 30 integers
using a function with a pivot value and then partition the values of the array
in order to sort through and find the k-th smallest value.
*******************************************************************************/
#include <iostream>
using namespace std;

int partition(int anArray[], int first, int last) {
   int pivot = anArray[first]; //pivot is used for greater and less than at each position
   int temp = 0;               //temp used for swapping values in the array
   int s = first;              //the position in the array the pivot will swap with at the end (aka the pivotIndex)
   int i = s + 1;              //used to travel through the array and check value

   while (i < last) {              //while the value of i is less then the area of the array we are searching
      if (anArray[i] < pivot) {    //if the current value at this position is less than the pivot
         s++;                      //increment to leave space for new less than pivot number
         
         //swaps and places new less than pivot number before where the pivot will go
         temp = anArray[s];
         anArray[s] = anArray[i];
         anArray[i] = temp;
      }
      
      i++; //continue searching
   }

   //swaps the chosen pivot number with where it should be
   temp = anArray[first];
   anArray[first] = anArray[s];
   anArray[s] = temp;

   return s;
}

/* Psuedo partition
   Initialize an integer called pivot and set it to the number in the first position of the array
   Initialize an integer called temp and set it equal to 0
   Initialize an integer called s and set it equal to the position the array starts at
   Initialize an integer called i and set it equal to s plus one
   While i is less than the number of the last position of the array
      If the number in the array at position i is less than the pivot
         Increment s
         Set temp equal to the number at position s in the array
         Set the number at position s in the array equal to the number at position i in the array
         Set the number at position i in the array to temp
      increment i
   Set temp equal to the number at the first position of the current array
   Set the number at the first position of the current array equal to the number at position s in the array
   Set the number at position s in the array equal to temp
   Return s
   */

int kSmall(int k, int arr[], int first, int last) {
   int pivotIndex = partition(arr, first, last);   //the position in the array the pivot will swap with at the end (aka the pivotIndex)

   if (k < pivotIndex - first + 1) {
      return kSmall(k, arr, first, pivotIndex - 1);
   }
   else if (k == pivotIndex - first + 1) { 
      return arr[pivotIndex];
   }
   else {
      return kSmall(k - (pivotIndex - first + 1), arr, pivotIndex + 1, last);
   }
}

//sorting the array by the pivot
/* kSmall psuedo
Initialize integers called k, first, last and a array of integers called arr
Initialize an integer called pivotIndex and set it equal to the position of the number that is pivoted
If k is less than the pivotIndex minus first plus 1
   Return the function kSmall with parameters k, arr, first, and pivotIndex minus 1
Else If k is equal to the pivotIndex minus first plus 1
   Return the number is the arr at the pivotIndex
Else
   Return the function kSmall with parameters k minus the difference of the pivotIndex minus first plus 1, arr, pivotIndex plus 1, last

*/

void Print(int arr[]) {
   for (int i = 0; i < 29; i++) {
      cout << arr[i] << ' ';
   }
}

int main() {
   //30 random numbers
   int array30[] = {8, 10, 91, 34, 28, 99, 90, 23, 84, 55, 13, 6, 21, 18, 27,
   4, 64, 70, 47, 35, 98, 83, 95, 78, 86, 62, 75, 16, 68, 42};
   
   //3rd smallest
   int k = 3;  //the k-th smallest number
   int smallest = kSmall(k, array30, 0, 29);
   Print(array30);
   cout << endl;
   cout << "The " << k << "rd smallest number is " << smallest << endl << endl;

   //10th smallest
   k = 10;  //the k-th smallest number
   smallest = kSmall(k, array30, 0, 29);
   Print(array30);
   cout << endl;
   cout << "The " << k << "th smallest number is " << smallest << endl << endl;

   //19th smallest
   k = 19;  //the k-th smallest number
   smallest = kSmall(k, array30, 0, 29);
   Print(array30);
   cout << endl;
   cout << "The " << k << "th smallest number is " << smallest << endl << endl;

   return 0;
}