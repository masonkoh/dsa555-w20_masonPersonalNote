#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
void bubbleSort(int arr[],int size){
    int tmp;    // 1                          /*used for swapping*/
    int i;      // 1
    int j;      // 1
    for (i=0; i<size-1; i++) {                                          // [i=0; i<size-1; i++]     => 1 + (n-1) + (n-1)
        for (j=0; j<size-1-i; j++){                                     // [j=0; j<size-1-i; j++]   => (n-1)
            if (arr[j+1] < arr[j]) {  /* compare the two neighbors */   // 4(n(n-1)/2)
            tmp = arr[j];             /* swap a[j] and a[j+1]      */   // 2(n(n-1)/2)
            arr[j] = arr[j+1];                                          // 4(n(n-1)/2)
            arr[j+1] = tmp;                                             // 3(n(n-1)/2)
                                                                        // ----------- lets sum up!
                                                                        // T(n) = 1+1+1+1+2(n-1)+(n-1)+(n-1)+17(n(n-1)/2)
                                                                        //      = 4+4(n-1)+17(n^2-n/2)
                                                                        // 4+4n-4+17/2n^2
        }
    }
}
}
/*
 - Let n represent size of array
 - Let T(n) represent the number of operations needed to sort array of size n with bubble sort
*/
/*
 // photo!
 - S = 1 + 2 + 3 + ... + (n-1)
 - 2S = (1 + 2 + 3 + ... (n-1)) + (1 + 2 + 3 + ... (n-1))
 - 2S = (1 + 2 + 3 + ... (n-1))
       +((n-1) + (n-2) + (n-3) + ... 1)) // this line, we wrote in backward. it's identical with the line above
      ----------------------------------
        n + n + n + ... + n    => n - 1  // explaining the line above
 - 2S = (n-1)*(n)
 - S = (n-1)*(n) / 2
 */

// ------------------------------------------- example BEGIN
/*
 
 int f1(int n){
    int rc = 1;             // 1
    for(int i=0;i<5;i++){   // 1+5+5
        rc+=n;              // 5
    }
    return rc;              // 1
 
                            // T(n) = 18
                            // T(n) is O(1)
 */
/*

int f1(int n){
   int rc = 1;             // 1
   for(int i=0;i<n;i+=2){  // 1+n/2+n/2
       rc+=n;              //
   }
   return rc;              // 1

*/
/*

int f1(int n){
   int rc = 1;             // 1
   for(int i=0;i<n;i*=2){  // 2 * 2 + log n (because i doubles each time...)
       rc+=n;              //
   }
   return rc;              // 1

*/
/*

int f1(int n){
   int rc = 1;             // 1
   for(int i=0;i<n*n;i++){  // n*n, which is n^2
       rc+=n;              //
   }
   return rc;              // 1

*/


// ------------------------------------------- example END

int main(int argc, char* argv[]){
    int size=atoi(argv[1]);
    int *myarr=new int[size];
    Timer stopwatch;
    ofstream log("bubblelog.txt");
    for(int i=0;i<size;i++){
        myarr[i]=rand();
    }
    stopwatch.start();
    bubbleSort(myarr,size);
    stopwatch.stop();
    cout << stopwatch.currtime() << endl;
    /*for(int i=0;i<size;i++){
        log <<myarr[i]<< endl;
    }*/
    delete [] myarr;
    return 0;
}

