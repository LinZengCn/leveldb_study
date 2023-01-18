#include <iostream>

#include "leveldb/db.h"

using namespace std;
using namespace leveldb;

int main() {
  DB* db;
  Options op;
  op.create_if_missing = true;
  Status s = DB::Open(op, "/tmp/testdb", &db);

  if (s.ok()) {
    cout << "create successfully" << endl;
    s = db->Put(WriteOptions(), "abcd", "1234");
    if (s.ok()) {
      cout << "put successfully" << endl;
      string value;
      s = db->Get(ReadOptions(), "abcd", &value);
      if (s.ok()) {
        cout << "get successfully,value:" << value << endl;
      } else {
        cout << "get failed" << endl;
      }
    } else {
      cout << "put failed" << endl;
    }
  } else {
    cout << "create failed" << endl;
  }
  delete db;
  return 0;
}
