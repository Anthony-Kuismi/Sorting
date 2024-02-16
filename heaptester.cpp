#include "binheap.h"
#include <iostream>
#include <string>
#include <time.h>

int main()
{
  string comment;
  char choice;
  KeyType key;
  BinHeap *H;
  int i, j, n;

  bool interact = true;
  bool printExtract = true;

  do
  {
    if (interact)
    {
      cout << "Commands:" << endl;
      cout << " (i)nsert, (m)inimum, (e)xtract min," << endl;
      cout << " (d)ecrease key, (p)rint heap, print as (t)ree, (s)earch,"
           << endl;
      cout << " (S)orting test" << endl;
      cout << "+/- turns extract print on/off, or # (to comment) " << endl;
      cout << " > ";
    }

    cin >> choice;

    switch (choice)
    {
    case 'i':
      if (interact)
        cout << "Enter key value to insert: ";
      cin >> key;
      H->insert(key);
      break;
    case 'm':
      key = H->minimum();
      cout << "Minimum = " << key << "\n";
      break;
    case 'e':
      if (H->empty())
      {
        cout << "Heap empty, can't extract minimum.\n\n";
      }
      else
      {
        key = H->extractMin();
        if (printExtract)
          cout << "Minimum extracted = " << key << "\n";
      }
      break;
    case 'd':
      if (interact)
        cout << "Enter index & new key to decrease: ";
      cin >> i >> key;
      H->decreaseKey(i, key);
      break;
    case 't':
      cout << "Heap as a logical tree (rotated 90 degrees to left):\n\n";
      H->ShowHeap(1, 0);
      cout << "\n\n";
      break;
    case 'p':
      H->PrintHeap();
      break;
    case '+':
      printExtract = true;
      break;
    case '-':
      printExtract = false;
      break;
    case '#':
      cout << '#';
      getline(cin, comment);
      cout << comment << "\n\n";
      break;
    case 's':
      if (interact)
        cout << "Enter key value to search for: ";
      cin >> key;
      i = H->search(key);
      cout << "key, " << key << ", found at index " << i << "\n";
      break;
    case 'S':
      if (interact)
        cout << "Enter length for sorting test: ";
      cin >> n;

      H = new BinHeap(n);
      cout << "Original array:" << endl;
      for (i = 1; i <= n; i++)
      {
        H->A[i] = rand() % n;
        cout << H->A[i] << " ";
      }
      cout << endl;
      H->minHeapSort(n);
      cout << "Sorted array:" << endl;
      for (i = 1; i <= n; i++)
      {
        cout << H->A[i] << " ";
      }
      cout << endl;
      // destroys heap
      H->heapSize = 0;
      break;
    default:
      cout << "Illegal choice: " << choice << endl;
    }
  } while (!cin.eof());

  cout << endl;

  return 0;
}
