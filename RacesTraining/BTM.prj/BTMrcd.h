// BTM Record Definition


#pragma once
#include "CSVrcdC.h"


class BTMfld : public CSVfld {

public:

  BTMfld() { }
 ~BTMfld() { }

  void    cleanUpName(int col);

private:

  String  removeChs(String& sym);

  };


class BTMrcd;
typedef IterT<BTMrcd, BTMfld> BRcdIter;


class BTMrcd : public CSVrcdC {

public:

  BTMrcd() { }
 ~BTMrcd() { }

private:

  // returns either a pointer to data (or datum) at index i in array or zero

  BTMfld* datum(int i) {return (BTMfld*) (0 <= i && i < nData() ? fields[i].p : 0);}

  int     nData()      {return fields.end();}              // returns number of data items in array

  friend typename BRcdIter;
  };

