// Status Update CSV Data


#pragma once
#include "IterT.h"
#include "CSVRcdB.h"
#include "CSVRcdsT.h"
#include "ExpandableP.h"


class CSVfld {
public:
String name;
bool   legal;

  CSVfld() : legal(false) {}
  CSVfld(CSVfld& fd) {copy(fd);}

  virtual ~CSVfld() {}

  void    clear() {name.clear();}

  CSVfld& operator=(CSVfld& fd)  {copy(fd); return *this;}

  void    put(TCchar* s) {name = s;}
  String* get() {return &name;}

private:

  void    copy(CSVfld& src) {name = src.name;}
  };


class CSVrcdC;
typedef DatumPtrT<CSVfld, int> CSVFldP;
typedef IterT<CSVrcdC, CSVfld> CSVrcdIter;


class CSVrcdC : public CSVRcdB {

protected:

ExpandableP<CSVfld, int, CSVFldP, 128> fields;

public:

  CSVrcdC() {}
  CSVrcdC(CSVrcdC& rcd) {copy(rcd);}
 ~CSVrcdC() {clear();}

  virtual void clear() {fields.clear();}

  int       nFields() {return nData();}

  String*   get(int i) {CSVfld* f = datum(i);  return f ? f->get() : 0;}

  CSVrcdC&   operator= (CSVrcdC& rcd) {copy(rcd); return *this;}

protected:

  virtual void    put(TCchar* s) {fields.nextData().put(s);}

  virtual String* get() {CSVfld* f = fields[getI]; return f ? f->get() : 0;}

  virtual void    copy(CSVrcdC& r);

  // returns either a pointer to data (or datum) at index i in array or zero

  CSVfld* datum(int i) {return 0 <= i && i < nData() ? fields[i] : (CSVfld*) 0;}       // or data[i].p

  int     nData()      {return fields.end();}             // returns number of data items in array

  friend typename CSVrcdIter;
  };

