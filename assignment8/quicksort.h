//
//  quicksort.h
//  assignment8
//
//  Created by Mike Rizza on 4/22/15.
//  Copyright (c) 2015 ___MikeRizza___. All rights reserved.
//

#ifndef assignment8_quicksort_h
#define assignment8_quicksort_h

#include<iomanip>
#include <fstream>
using namespace std;


/****************************************************************
 
 FUNCTION:  partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)
 
 RETURNS:   void
 
 NOTES:     This function selects a pivot element and then partitions the vector around the pivot.
 ****************************************************************/

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotIndex;
    int mid;
    T pivotValue;
    
    mid = (start + end) / 2;
    
    swap (set[start], set[mid]);
    
    pivotIndex = start;
    pivotValue = set[start];
    
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (compare(set[scan], pivotValue))
        {
            pivotIndex++;
            swap (set[pivotIndex], set[scan]);
        }
    }
    
    swap(set[start], set[pivotIndex]);
    
    return pivotIndex;
}

/****************************************************************
 
 FUNCTION:  quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)
 
 RETURNS:   void
 
 NOTES:     This function performs the recursive calls to implement the quick sort algorithm.
 ****************************************************************/

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
        int pivotPoint;
        
        if (start < end)
        {
            pivotPoint = partition(set, start, end, compare);     // Get the pivot point
            quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
            quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
        }
    }

/****************************************************************
 
 FUNCTION:  quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: vector<T>& set, bool (*compare)(const T&, const T&)
 
 RETURNS:   void
 
 NOTES:     sort the items in the vector set using the quick sort algorithm.
 ****************************************************************/

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    quickSort(set, 0, set.size()-1, compare);
    
}






#endif
