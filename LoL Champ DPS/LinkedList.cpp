//
//  LinkedList.cpp
//  LoL Champ DPS
//
//  Created by Cameron Smith on 5/14/16.
//  Copyright © 2016 Cameron Smith. All rights reserved.
//

#include "LinkedList.hpp"

//*****************************************************************
//  LinkedList.cpp
//  HashTable
//
//  Created by Karlina Beringer on June 16, 2014.
//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************


LLChamp::LLChamp()
{
    head = new Champion;
    head->next = NULL;
    length = 0;
}

void LLChamp::insertChamp(Champion *newChamp)
{
    if (!head -> next)
    {
        head -> next = newChamp;
        length++;
        return;
    }
    Champion * p = head;
    Champion * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newChamp;
    newChamp -> next = NULL;
    length++;
}

Champion * LLChamp::getChamp(string champKey)
{
    Champion * p = head;
    Champion * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> champName == champKey))
            return p;
        q = p -> next;
    }
    return NULL;
}

void LLChamp::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Champion * p = head;
    Champion * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> champName;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

LLChamp::~LLChamp()
{
    Champion * p = head;
    Champion * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LLItem::LLItem()
{
    head = new Item;
    head -> next = NULL;
    length = 0;
}

// Inserts an item at the end of the list.

void LLItem::insertItem( Item * newItem )
{
    if (!head -> next)
    {
        head -> next = newItem;
        length++;
        return;
    }
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newItem;
    newItem -> next = NULL;
    length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
bool LLItem::removeItem( string itemKey )
{
    if (!head -> next) return false;
    Item * p = head;
    Item * q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Item * LLItem::getItem( string itemKey )
{
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    return NULL;
}

// Displays list contents to the console window.
void LLItem::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Item * p = head;
    Item * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LLItem::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
LLItem::~LLItem()
{
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

//*****************************************************************
// End of File