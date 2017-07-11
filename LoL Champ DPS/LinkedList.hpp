//
//  LinkedList.hpp
//  LoL Champ DPS
//
//  Created by Cameron Smith on 5/14/16.
//  Copyright © 2016 Cameron Smith. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>


//*****************************************************************
//  LinkedList.h
//  HashTable
//
//  Created by Karlina Beringer on June 16, 2014.
//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************


#include <iostream>
#include <string>
using namespace std;

//*****************************************************************
// List items are keys with pointers to the next item.
//*****************************************************************

struct Champion
{
    string champName;
    double H;
    double HpL;
    double HReg;
    double HRegpL;
    double Mana;
    double MpL;
    double MReg;
    double MRegpL;
    double AD;
    double ADpL;
    double AP;
    double AS;
    double ASpL;
    double A;
    double ApL;
    double MR;
    double MS;
    double CDR;
    int Range;
    Champion *next;
};

struct Item
{
    string key;
    Item * next;
};

//*****************************************************************
// Linked lists store a variable number of items.
//*****************************************************************

class LLChamp
{
private:
    Champion *head;
    int length;
public:
    LLChamp();
    void insertChamp(Champion *newChamp);
    Champion *getChamp(string champKey);
    void printList();
    ~LLChamp();
};

class LLItem
{
private:
    // Head is a reference to a list of data nodes.
    Item * head;
    
    // Length is the number of data nodes.
    int length;
    
public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LLItem();
    
    // Inserts an item at the end of the list.
    void insertItem( Item * newItem );
    
    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey );
    
    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    Item * getItem( string itemKey );
    
    // Displays list contents to the console window.
    void printList();
    
    // Returns the length of the list.
    int getLength();
    
    // De-allocates list memory when the program terminates.
    ~LLItem();
};


//*****************************************************************
// End of File
//**********************************************

#endif /* LinkedList_hpp */
