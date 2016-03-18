//
//  sorts.h
//  assignment8
//
//  Created by Mike Rizza on 4/22/15.
//  Copyright (c) 2015 ___MikeRizza___. All rights reserved.
//

#ifndef assignment8_sorts_h
#define assignment8_sorts_h

#include<iomanip>
#include <fstream>
using namespace std;

/****************************************************************
 
 FUNCTION:  void buildList(vector<T>& set, const char* fileName)
 
 ARGUMENTS: vector<T>& set, const char* fileName
 
 RETURNS:   void
 
 NOTES:     read items from an input file and put them into a vector.
 ****************************************************************/

template <class T>
void buildList(vector<T>& set, const char* fileName)
{
    T item;
    ifstream inFile;
    
    inFile.open((fileName));  // Open the file stream
    
    
     if (inFile.is_open()) // if inFile is open
     {
        
         inFile >> item;  // read inFile into set
    
         while (!inFile.eof( ))  //while not end of file
    
    
         {
            
            set.push_back(item); //push back each item in set
            inFile >> item;
    
    
         }
     }
    inFile.close(); //close file stream
}

/****************************************************************
 
 FUNCTION:  printList(const vector<T>& set, int itemWidth, int numPerLine)
 
 ARGUMENTS: const vector<T>& set, int itemWidth, int numPerLine
 
 RETURNS:   void
 
 NOTES:     print a list of items stored in a vector.
 ****************************************************************/

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    
    for(int i=0; i<set.size();i++)
    {
        cout<<setw(itemWidth)<<set[i];
        if ((i+1) % numPerLine == 0)
            cout << endl;
        
    }
    cout<<endl;
}

/****************************************************************
 
 FUNCTION: lessThan(const T& item1, const T& item2)
 
 ARGUMENTS: const T& item1, const T& item2
 
 RETURNS:   bool value
 
 NOTES:    return true if item1 is less than item2 and false if not.
 ****************************************************************/

template <class T>
bool lessThan(const T& item1, const T& item2)
{
if (item1 < item2)
    return true;
else
    return false;
    }

/****************************************************************
 
 FUNCTION: greaterThan(const T& item1, const T& item2)
 
 ARGUMENTS: const T& item1, const T& item2
 
 RETURNS:   bool value
 
 NOTES:    return true if item1 is greater than item2 and false if not.
 ****************************************************************/

template <class T>
bool greaterThan(const T& item1, const T& item2)
{
    if (item1 > item2)
    return true;
else
    return false;
}

#endif
