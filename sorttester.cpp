// driver.cpp - driver for testing heapsort, quicksort and rquicksort

#include "binheap.h"
#include "quicksort.h"
#include <iostream>
#include <string>
#include <chrono>  

using namespace std ;


bool test_quicksort(const KeyType A[], int n,bool print)
{
  int i;
  bool test=true;
  KeyType* Acopy = new KeyType[n];

  for (i=0; i<n; i++) Acopy[i] = A[i];
  auto start = chrono::high_resolution_clock::now();    
  quicksort(Acopy,0,n-1);
  auto end = chrono::high_resolution_clock::now();
    
  cout << "quicksort time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()*1e-9 << " seconds" << endl;
  
  if (print) cout << "--- SORTED ARRAY ---" << endl;
  for (i=0; i<n; i++) {
    if (i < n-1 && Acopy[i+1] < Acopy[i]) test = false;
    if (print) cout << Acopy[i] << " ";
  }
  if (print) cout << endl;
  delete[] Acopy;
  return test;
}

bool test_rquicksort(const KeyType A[], int n,bool print)
{
  int i;
  bool test = true;
  KeyType* Acopy = new KeyType[n];

  for (i=0; i<n; i++) Acopy[i] = A[i];
  auto start = chrono::high_resolution_clock::now();    
  rquicksort(Acopy,0,n-1);
  auto end = chrono::high_resolution_clock::now();
    
  cout << "rquicksort time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()*1e-9 << " seconds" << endl;
  
  if (print) cout << "--- SORTED ARRAY ---" << endl;
  for (i=0; i<n; i++) {
    if (i < n-1 && Acopy[i+1] < Acopy[i]) test = false;
    if (print) cout << Acopy[i] << " ";
  }
  if (print) cout << endl;
  delete[] Acopy;
  return test;
}

bool test_heapsort(const KeyType A[], int n, bool print)
{
  BinHeap H(n);
  bool test=true;
  int i;
  for (i=0; i<n; i++) H.A[i+1] = A[i];
  auto start = chrono::high_resolution_clock::now();    
  H.minHeapSort(n);
  auto end = chrono::high_resolution_clock::now();    
  cout << "heapsort time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()*1e-9 << " seconds" << endl;
  if (print) cout << "--- SORTED ARRAY ---" << endl;
  for (i=0; i<n; i++) {
    // minHeapSort sorts decreasing
    if (i < n-1 && H.A[i+2] > H.A[i+1]) test=false;
    if (print) cout << H.A[i+1] << " ";
  }
  if (print) cout << endl;
  return test;
}

int main()
{
  string comment ;
  char choice ;
  //BinHeap H ;         
  KeyType *A;
  int i, n ;

  //bool interact = false ;
  bool interact = true;
  bool printArrays = false;
  //bool printArrays = true;

   while ( !cin.eof() ) {
  if ( interact ){
    cout << "Commands:" << endl;
    cout << " (r)andom, (s)orted, (b)ackwards," << endl;
    cout << " > ";
  }
  cin >> choice ;
  if ( interact ) cout << "Enter size of array to sort: ";
  cin >> n;

  A = new KeyType[n];
  
  switch ( choice ) {
  case 'r':
    for (i=0; i<n; i++) {
      A[i] = rand() % n;
    }
    break ;
  case 's': 
    for (i=0; i<n; i++) {
      A[i] = i;
    }
    break ;
  case 'b': 
    for (i=0; i<n; i++) {
      A[i] = n-i-1;
    }
    break ;
  case '#': 
    cout << '#' ; getline(cin, comment) ;
    cout << comment << "\n\n" ;
    break ;
  default: 
    cout << "Illegal choice: " << choice << endl ;
  }

  if (printArrays){
    cout << "--- ORIGINAL ARRAY ---" << endl;
    for (i=0; i<n; i++){
      cout << A[i] << " ";
    }
    cout << endl ;
  }

  cout <<endl;

  if (test_quicksort(A,n,printArrays)){
    cout << "quicksort: SUCCESS" << endl;
  }
  else {
    cout << "quicksort: FAILURE" << endl;
  }

  if (test_rquicksort(A,n,printArrays)){
    cout << "rquicksort: SUCCESS" << endl;
  }
  else {
    cout << "rquicksort: FAILURE" << endl;
  }

  if (test_heapsort(A,n,printArrays)){
    cout << "heapsort: SUCCESS" << endl;
  }
  else {
    cout << "heapsort: FAILURE" << endl;
  }

  delete[] A;
  
  }


  return 0;
}

