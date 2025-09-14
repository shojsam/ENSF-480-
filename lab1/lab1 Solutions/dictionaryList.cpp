/*
* File Name: dictionaryList.cpp
* Assignment: Lab 1 Exercise B
* Lab section: B02
* Completed by: Sam Shojaei
* Development Date: Sept 12, 2025
*/
#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
using namespace std;

Node::Node(const int& keyA, const Datum& datumA, Node *nextA)
: keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
: sizeM(0), headM(0), cursorM(0)
{
}

int DictionaryList::size() const
{
    return sizeM;
}

int DictionaryList::cursor_ok() const
{
    return cursorM != 0;
}

const int& DictionaryList::cursor_key() const
{
    assert(cursor_ok());
    return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
    assert(cursor_ok());
    return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const string& datumA)
{
    // Add new node at head?
    if (headM == 0 || keyA < headM->keyM) {
        headM = new Node(keyA, datumA, headM);
        sizeM++;
    }
    
    // Overwrite datum at head?
    else if (keyA == headM->keyM)
        headM->datumM = datumA;
    
    // Have to search ...
    else {
        
        //POINT ONE
        
        // if key is found in list, just overwrite data;
        for (Node *p = headM; p !=0; p = p->nextM)
        {
            if(keyA == p->keyM)
            {
                p->datumM = datumA;
                return;
            }
        }
        
        //OK, find place to insert new node ...
        Node *p = headM ->nextM;
        Node *prev = headM;
        
        while(p !=0 && keyA >p->keyM)
        {
            prev = p;
            p = p->nextM;
        }
        
        prev->nextM = new Node(keyA, datumA, p);
        sizeM++;
    }
    cursorM = NULL;
    
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    }
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}



// The following functions are supposed to be completed by the stuents, as part
// of the exercise B. the given code for this fucntion are just place-holders
// in order to allow successful linking when you're esting insert and remove.
// Replace them with the definitions that work.

DictionaryList::DictionaryList(const DictionaryList& source)
{
    sizeM = 0;
    headM = nullptr;
    cursorM = nullptr;

    Node* p = source.headM;
    int cursorKey = 0;
    bool haveCursor = false;

    while (p != nullptr) {
        insert(p->keyM, p->datumM);
        if (p == source.cursorM) {
            cursorKey = p->keyM;
            haveCursor = true;
        }
        p = p->nextM;
    }
    if (haveCursor) find(cursorKey);
}

DictionaryList& DictionaryList::operator=(const DictionaryList& rhs)
{
    if (this == &rhs) return *this;

    make_empty();

    Node* p = rhs.headM;
    int cursorKey = 0;
    bool haveCursor = false;

    while (p != nullptr) {
        insert(p->keyM, p->datumM);
        if (p == rhs.cursorM) {
            cursorKey = p->keyM;
            haveCursor = true;
        }
        p = p->nextM;
    }
    if (haveCursor) find(cursorKey);

    return *this;
}

DictionaryList::~DictionaryList()
{
    make_empty();
}

void DictionaryList::find(const int& keyA)
{
    // Students should replace these messages with proper code.
    Node *p = headM;
    while (p != nullptr) {
        if (p->keyM == keyA) {
            cursorM = p;
            return;
        }
        p = p->nextM;
    }
    cursorM = nullptr;
}

void DictionaryList::make_empty()
{
    // Students should replace these messages with proper code.
    Node *p = headM;
    while (p != 0) {
        Node *next = p->nextM;
        delete p;
        p = next;
    }
    headM = 0;
    cursorM = 0;
    sizeM = 0;
    
}
