// ENSF 480 - Lab 3, Ex C
// M. Moussavi
//sam shojaei
#include <assert.h>
#include <iostream>
#include <cstring>
#include "lookupTable.h"
#include "customer.h"
#include "mystring2.h"
using namespace std;

// Template print for any LookupTable<Key, Datum>
template <class Key, class Datum>
void print(LookupTable<Key, Datum>& lt)
{
  if (lt.size() == 0) {
    cout << "  Table is EMPTY.\n";
    return;
  }
  for (lt.go_to_first(); lt.cursor_ok(); lt.step_fwd()) {
    cout << lt << endl;
  }
}

// Template find helper
template <class Key, class Datum>
void try_to_find(LookupTable<Key, Datum>& lt, const Key& key)
{
  lt.find(key);
  if (lt.cursor_ok())
    cout << "\nFound key: "  << lt << endl;
  else
    cout << "\nSorry, I couldn't find key: " << key << " in the table.\n";
}

// ---- Tests ----
static void test_Customer();
static void test_String();
static void test_integer();

int main()
{
  // create and test a lookup table with an integer key value and Customer datum
  test_Customer();

  // create and test a lookup table of type <int, Mystring>
  test_String();

  // create and test a lookup table of type <int, int>
  test_integer();

  cout << "\n\nProgram terminated successfully.\n\n";
  return 0;
}

void test_Customer()
  //creating a lookup table for customer objects.
{
  cout << "\nCreating and testing Customers Lookup Table <int, Customer>...\n";
  LookupTable<int, Customer> lt;

  // Insert using new keys.
  Customer a("Joe",  "Morrison", "11 St. Calgary.", "(403)-1111-123333");
  Customer b("Jack", "Lewis",    "12 St. Calgary.", "(403)-1111-123334");
  Customer c("Tim",  "Hardy",    "13 St. Calgary.", "(403)-1111-123335");

  lt.insert(Pair<int, Customer>(8002, a));
  lt.insert(Pair<int, Customer>(8004, c));
  lt.insert(Pair<int, Customer>(8001, b));

  assert(lt.size() == 3);
  lt.remove(8004);
  assert(lt.size() == 2);
  cout << "\nPrinting table after inserting 3 new keys and 1 removal...\n";
  print(lt);

  // Pretend that a user is trying to look up customers info.
  cout << "\nLet's look up some names ...\n";
  try_to_find<int, Customer>(lt, 8001);
  try_to_find<int, Customer>(lt, 8000);

  // test Iterator
  cout << "\nTesting and using iterator ...\n";
  typename LookupTable<int, Customer>::Iterator it = lt.begin();
  cout << "\nThe first node contains: " << *it << endl;

  // Print the rest safely using postfix it++
  it.step_fwd();
  while (!it) { // operator! returns 1 while cursor_ok()
    cout << it++ << endl;
  }

  // test copying
  lt.go_to_first();
  lt.step_fwd();
  LookupTable<int, Customer> clt(lt);
  assert(strcmp(clt.cursor_datum().getFname(), "Joe") == 0);

  cout << "\nTest copying: keys should be 8001, and 8002\n";
  print(clt);
  lt.remove(8002);

  // Assignment operator check.
  clt = lt;

  cout << "\nTest assignment operator: key should be 8001\n";
  print(clt);

  // Wipe out the entries in the table.
  lt.make_empty();
  cout << "\nPrinting table for the last time: Table should be empty...\n";
  print(lt);

  cout << "***----Finished tests on <int, Customer>-----***\n";
  cout << "PRESS RETURN TO CONTINUE.";
  cin.get();
}

void test_String()
  // creating lookup table for Mystring objects
{
  cout << "\nCreating and testing LookupTable <int, Mystring> .....\n";
  LookupTable<int, Mystring> lt;

  // Insert using new keys.
  Mystring a("I am an ENEL-409 student.");
  Mystring b("C++ is a powerful language for engineers but it's not easy.");
  Mystring c("Winter 2004");

  lt.insert(Pair<int, Mystring>(8002, a));
  lt.insert(Pair<int, Mystring>(8001, b));
  lt.insert(Pair<int, Mystring>(8004, c));

  cout << "\nPrinting table after inserting 3 new keys...\n";
  print(lt);

  cout << "\nLet's look up some strings ...\n";
  try_to_find<int, Mystring>(lt, 8001);
  try_to_find<int, Mystring>(lt, 8000);

  // test Iterator
  typename LookupTable<int, Mystring>::Iterator it = lt.begin();
  cout << "\nThe first node contains: " << *it << endl;

  it.step_fwd();
  while (!it) {
    cout << it++ << endl;
  }

  // test copying
  lt.go_to_first();
  lt.step_fwd();
  LookupTable<int, Mystring> clt(lt);
  // Verify copied cursor points to the same text
  assert(std::strcmp(clt.cursor_datum().c_str(), "I am an ENEL-409 student.") == 0);

  cout << "\nTest copying: keys should be 8001, and 8002\n";
  print(clt);
  lt.remove(8002);

  // Assignment operator check.
  clt = lt;

  cout << "\nTest assignment operator: key should be 8001\n";
  print(clt);

  // Wipe out
  lt.make_empty();
  cout << "\nPrinting table for the last time: Table should be empty ...\n";
  print(lt);

  cout << "***----Finished tests on <int, Mystring>-----***\n";
  cout << "PRESS RETURN TO CONTINUE.";
  cin.get();
}

void test_integer()
  // creating lookup table of integers
{
  cout << "\nCreating and testing LookupTable <int, int> .....\n";
  LookupTable<int, int> lt;

  // Insert using new keys.
  lt.insert(Pair<int, int>(8002, 9999));
  lt.insert(Pair<int, int>(8001, 8888));
  lt.insert(Pair<int, int>(8004, 8888));
  assert(lt.size() == 3);
  lt.remove(8004);
  assert(lt.size() == 2);

  cout << "\nPrinting table after inserting 3 new keys and 1 removal...\n";
  print(lt);

  cout << "\nLet's look up some ints ...\n";
  try_to_find<int, int>(lt, 8001);
  try_to_find<int, int>(lt, 8000);

  // test Iterator
  typename LookupTable<int, int>::Iterator it = lt.begin();
  while (!it) {
    cout << it++ << endl;
  }

  // test copying
  lt.go_to_first();
  lt.step_fwd();
  LookupTable<int, int> clt(lt);
  assert(clt.cursor_datum() == 9999);

  cout << "\nTest copying: keys should be 8001, and 8002\n";
  print(clt);
  lt.remove(8002);

  // Assignment operator check.
  clt = lt;

  cout << "\nTest assignment operator: key should be 8001\n";
  print(clt);

  // Wipe out
  lt.make_empty();
  cout << "\nPrinting table for the last time: Table should be empty ...\n";
  print(lt);

  cout << "***----Finished tests on <int, int>-----***\n";
}
