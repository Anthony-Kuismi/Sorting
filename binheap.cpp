#include "binheap.h"

#include <iomanip>
#include <iostream>

int getParent(int i)
{
   return i / 2;
}
int getLeftChild(int i)
{
   return 2 * i;
}
int getRightChild(int i)
{
   return 2 * i + 1;
}

void BinHeap::minHeapify(int i)
{
   int leftChild, rightChild, smallestIndex;
   leftChild = getLeftChild(i);
   rightChild = getRightChild(i);

   if (leftChild <= heapSize && A[leftChild] < A[i])
   {
      smallestIndex = leftChild;
   }
   else
   {
      smallestIndex = i;
   }

   if (rightChild <= heapSize && A[rightChild] < A[smallestIndex])
   {
      smallestIndex = rightChild;
   }

   if (i != smallestIndex)
   {
      KeyType temp;
      temp = A[smallestIndex];
      A[smallestIndex] = A[i];
      A[i] = temp;
      minHeapify(smallestIndex);
   }
}

void BinHeap::buildMinHeap(int n)
{
   heapSize = length;
   for (int i = (length / 2); i >= 1; i--)
   {
      minHeapify(i);
   }
}

void BinHeap::minHeapSort(int n)
{
   buildMinHeap(0);
   KeyType temp;
   for (int i = n; i >= 2; i--)
   {
      temp = A[1];
      A[1] = A[i];
      A[i] = temp;

      heapSize--;
      minHeapify(1);
   }
}

// Constructors, Destructor
BinHeap::BinHeap()
{
   heapSize = 0;
   length = 1000;
   A = new KeyType[1001];
}

BinHeap::BinHeap(int arrayLength)
{
   heapSize = 0;
   length = arrayLength;
   A = new KeyType[arrayLength + 1];
}
BinHeap ::~BinHeap()
{
   delete[] A;
}

// Min-heap, min priority queue operations

void BinHeap::insert(KeyType key)
{
   heapSize++;
   A[heapSize] = key;
   decreaseKey(heapSize, key);
}

void BinHeap::decreaseKey(int i, KeyType key)
{
   if (key > A[i])
   {
      cout << "\nKey larger than A[i] in decreaseKey()\n\n";
      return;
   }
   
   A[i] = key;
   while(i > 1){
      int parent = getParent(i);
      if(A[i] < A[parent]){
         swap(A[i],A[parent]);
         i=parent;
      }else{
         break;
      }
   }
}

KeyType BinHeap::minimum()
{
   return A[1]; // Assumes heap is not empty!
}

KeyType BinHeap::extractMin()
{
   KeyType min;

   if (heapSize < 1)
   {
      cout << "\nHeap underflow in extractMin()\n\n";
      return 0;
   }

   min = A[1];
   A[1] = A[heapSize];
   heapSize--;
   int i = 1;

   while(2*i <= heapSize){
      int rightChild = getRightChild(i);
      int leftChild = getLeftChild(i);
      if(rightChild > heapSize || A[leftChild] < A[rightChild]){
         if(A[i]>A[leftChild]){
            swap(A[i],A[leftChild]);
            i = leftChild;
         }else{
            break;
         }
      }else{
         if(A[i]>A[rightChild]){
            swap(A[i],A[rightChild]);
            i = rightChild;
         }else{
            break;
         }
      }
   }
   return min;
}


// Auxiliary operations

// Shows the structure of the binary heap
void BinHeap::ShowHeap(int i, int depth)
{
   if (i <= heapSize)
   {
      ShowHeap(getRightChild(i), depth + 1);
      cout << setw(depth * 6 + 4) << A[i] << endl;
      ShowHeap(getLeftChild(i), depth + 1);
   }
}

// Just prints A[] as a horizontal array
void BinHeap::PrintHeap()
{
   cout << "Heap elements in the array:\n";
   for (int i = 1; i <= heapSize; i++)
      cout << A[i] << " ";
   cout << endl;
}

// A routine that is useful for testing decreaseKey()
int BinHeap::search(KeyType key)
{
   for (int i = 1; i <= heapSize; i++)
      if (A[i] == key)
         return i;
   return 0;
}
