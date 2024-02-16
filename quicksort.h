#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>

using namespace std;

typedef int KeyType;

void quicksort(KeyType A[], int p, int r);
void rquicksort(KeyType A[], int p, int r);

int partition(KeyType A[], int p, int r);
int rpartition(KeyType A[], int p, int r);

#endif
