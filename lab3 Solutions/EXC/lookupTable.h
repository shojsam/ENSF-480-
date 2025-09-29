// LookupTable.h
// ENSF 480 - Lab 3, Ex C

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <iostream>
#include <cassert>
using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse through the list and  have access to each
//    node.

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.

template <class Key, class Datum>
struct Pair {
  Pair(const Key& keyA, const Datum& datumA) : key(keyA), datum(datumA) {}
  Key   key;
  Datum datum;
};

// Forward declare the table for friend use in the node.
template <class Key, class Datum>
class LookupTable;

template <class Key, class Datum>
class LT_Node {
  template <class, class> friend class LookupTable;

private:
  Pair<Key, Datum>     pairM;
  LT_Node<Key, Datum>* nextM;

  LT_Node(const Pair<Key, Datum>& pairA, LT_Node* nextA)
    : pairM(pairA), nextM(nextA) {}
};

template <class Key, class Datum>
class LookupTable {
public:
  // Nested class
  class Iterator {
    template <class, class> friend class LookupTable;
    LookupTable* LT;

  public:
    Iterator() : LT(nullptr) {}
    Iterator(LookupTable& x) : LT(&x) {}

    const Datum& operator*() {
      assert(LT && LT->cursor_ok());
      return LT->cursor_datum();
    }

    // prefix ++
    const Datum& operator++() {
      assert(LT && LT->cursor_ok());
      LT->step_fwd();
      assert(LT->cursor_ok());
      return LT->cursor_datum();
    }

    // postfix ++  (returns current, then advances)
    const Datum& operator++(int) {
      assert(LT && LT->cursor_ok());
      const Datum& x = LT->cursor_datum();
      LT->step_fwd();
      return x;
    }

    // In this scaffold, operator!() returns 1 when cursor_ok() is true
    int operator!() {
      return (LT && LT->cursor_ok());
    }

    void step_fwd() {
      assert(LT && LT->cursor_ok());
      LT->step_fwd();
    }
  };

  LookupTable();
  LookupTable(const LookupTable& source);
  LookupTable& operator=(const LookupTable& rhs);
  ~LookupTable();

  LookupTable& begin();  // handy helper to attach cursor to head

  int size() const;
  int cursor_ok() const;

  const Key&   cursor_key()   const;
  const Datum& cursor_datum() const;

  void insert(const Pair<Key, Datum>& pairA);
  // PROMISES:
  //   If a pair with key equal to pairA.key already exists, replace
  //   its datum with pairA.datum (table size unchanged).
  //   Otherwise, insert a new node so that pairs remain ordered by key.
  //   In either case, the cursor goes to the off-list state.

  void remove(const Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursor is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursor is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursor refers to the lowest-key pair;
  // otherwise, cursor is off-list.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES: cursor advances to the next node; becomes off-list if
  // at end.

  void make_empty();
  // PROMISES: removes all nodes; size() becomes 0; cursor off-list.

  template <class K, class D>
  friend ostream& operator<<(ostream& os, const LookupTable<K, D>& lt);

private:
  int                    sizeM;
  LT_Node<Key, Datum>*   headM;
  LT_Node<Key, Datum>*   cursorM;

  void destroy();
  void copy(const LookupTable& source);
};

// -------- Implementation --------

template <class Key, class Datum>
LookupTable<Key, Datum>::LookupTable()
  : sizeM(0), headM(nullptr), cursorM(nullptr) {}

template <class Key, class Datum>
LookupTable<Key, Datum>::LookupTable(const LookupTable& source)
  : sizeM(0), headM(nullptr), cursorM(nullptr) {
  copy(source);
}

template <class Key, class Datum>
LookupTable<Key, Datum>&
LookupTable<Key, Datum>::operator=(const LookupTable& rhs) {
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <class Key, class Datum>
LookupTable<Key, Datum>::~LookupTable() {
  destroy();
}

template <class Key, class Datum>
LookupTable<Key, Datum>& LookupTable<Key, Datum>::begin() {
  cursorM = headM;
  return *this;
}

template <class Key, class Datum>
int LookupTable<Key, Datum>::size() const {
  return sizeM;
}

template <class Key, class Datum>
int LookupTable<Key, Datum>::cursor_ok() const {
  return cursorM != nullptr;
}

template <class Key, class Datum>
const Key& LookupTable<Key, Datum>::cursor_key() const {
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <class Key, class Datum>
const Datum& LookupTable<Key, Datum>::cursor_datum() const {
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::insert(const Pair<Key, Datum>& pairA) {
  cursorM = nullptr;

  if (headM == nullptr || pairA.key < headM->pairM.key) {
    headM = new LT_Node<Key, Datum>(pairA, headM);
    ++sizeM;
    return;
  }

  if (pairA.key == headM->pairM.key) {
    headM->pairM.datum = pairA.datum;
    return;
  }

  LT_Node<Key, Datum>* before = headM;
  LT_Node<Key, Datum>* after  = headM->nextM;

  while (after != nullptr && pairA.key > after->pairM.key) {
    before = after;
    after  = after->nextM;
  }

  if (after != nullptr && pairA.key == after->pairM.key) {
    after->pairM.datum = pairA.datum;
  } else {
    before->nextM = new LT_Node<Key, Datum>(pairA, after);
    ++sizeM;
  }
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::remove(const Key& keyA) {
  cursorM = nullptr;

  if (headM == nullptr || keyA < headM->pairM.key)
    return;

  LT_Node<Key, Datum>* doomed = nullptr;

  if (keyA == headM->pairM.key) {
    doomed = headM;
    headM  = headM->nextM;
    --sizeM;
  } else {
    LT_Node<Key, Datum>* before       = headM;
    LT_Node<Key, Datum>* maybe_doomed = headM->nextM;

    while (maybe_doomed != nullptr && keyA > maybe_doomed->pairM.key) {
      before       = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != nullptr && keyA == maybe_doomed->pairM.key) {
      doomed          = maybe_doomed;
      before->nextM   = maybe_doomed->nextM;
      --sizeM;
    }
  }

  delete doomed;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::find(const Key& keyA) {
  LT_Node<Key, Datum>* p = headM;
  while (p != nullptr && p->pairM.key != keyA) {
    p = p->nextM;
  }
  cursorM = p;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::go_to_first() {
  cursorM = headM;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::step_fwd() {
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::make_empty() {
  destroy();
  sizeM   = 0;
  cursorM = nullptr;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::destroy() {
  LT_Node<Key, Datum>* p = headM;
  while (p != nullptr) {
    LT_Node<Key, Datum>* nxt = p->nextM;
    delete p;
    p = nxt;
  }
  headM   = nullptr;
  cursorM = nullptr;
  sizeM   = 0;
}

template <class Key, class Datum>
void LookupTable<Key, Datum>::copy(const LookupTable& source) {
  if (source.headM == nullptr) {
    headM   = nullptr;
    cursorM = nullptr;
    sizeM   = 0;
    return;
  }

  headM = new LT_Node<Key, Datum>(source.headM->pairM, nullptr);
  sizeM = 1;

  const LT_Node<Key, Datum>* sp = source.headM->nextM;
  LT_Node<Key, Datum>* dp = headM;

  while (sp != nullptr) {
    dp->nextM = new LT_Node<Key, Datum>(sp->pairM, nullptr);
    dp = dp->nextM;
    sp = sp->nextM;
    ++sizeM;
  }

  if (source.cursorM) {
    find(source.cursorM->pairM.key);
  } else {
    cursorM = nullptr;
  }
}

template <class K, class D>
ostream& operator<<(ostream& os, const LookupTable<K, D>& lt) {
  if (lt.cursor_ok())
    os << lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os << "Not Found.";
  return os;
}

#endif // LOOKUPTABLE_H
