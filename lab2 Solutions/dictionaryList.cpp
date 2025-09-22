
/*
* File Name: dictionarylist.cpp
// Lab 2 - Exercise A
* Lab Section:  B02
* Completed by: sam shojaei
* Submission Date: sept
*/

#include <assert.h>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "dictionaryList.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

Datum& DictionaryList::cursor_datum() const
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

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


void DictionaryList::find(const Key& keyA)
{
    for (Node *p = headM; p != 0; p=p->nextM)
        if (keyA == p->keyM)
        {
            cout << "'" << keyA <<"' was found with datum value " << p->datumM.c_str() << ".\n";
            cursorM = p;
            return;
        }
    cout << "'" << keyA <<"' was not found.\n";
    cursorM = 0;
}


void DictionaryList::destroy()
{
    
        Node *p = headM;
        Node *prev;
        while (p != 0)
        {
            prev = p;
            p = p->nextM;
            delete prev;
        }
        headM = 0;
        sizeM = 0;
    
}


void DictionaryList::copy(const DictionaryList& source)
{
    if (source.headM == 0) {
        headM = 0;
        return;
    }
    
    headM = new Node (source.headM->keyM, source.headM->datumM, NULL);
    Node *newest_node = headM;
    
    const Node *source_node = source.headM;
    
    if(source_node == source.cursorM)
         cursorM = newest_node;
    
    while (true) {
        source_node = source_node->nextM;
        
        if (source_node == 0)
            break;
        
        newest_node->nextM = new Node(source_node->keyM, source_node->datumM, NULL);
        
       if(source_node == source.cursorM)
            cursorM = newest_node->nextM;

        newest_node = newest_node->nextM;
        
    }
    
    sizeM = source.sizeM;

}



ostream& operator<<(ostream& out, const DictionaryList& dl)
{
  for (Node* p = dl.headM; p != nullptr; p = p->nextM) {
    out << "  " << p->keyM << "  " << p->datumM << '\n';
  }
  return out;
}

Datum& DictionaryList::operator[](int index) const
{
  if (index < 0 || index >= sizeM) {
    throw out_of_range("DictionaryList::operator[] index out of range");
  }
  Node* p = headM;
  for (int i = 0; i < index; ++i) {
    p = p->nextM;
  }
  return p->datumM;
}
