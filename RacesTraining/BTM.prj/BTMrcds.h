// CSV records, one record per line


#pragma once
#include "BTMrcd.h"


class BTMrcds;
typedef DatumPtrT<BTMrcd, int>          BTMrcdP;
typedef CSVRcdsT< BTMrcd, int, BTMrcdP> BTMrcdsB;
typedef CSVIterT< BTMrcd, int, BTMrcdP> CSVIter;


class BTMrcds : public BTMrcdsB {

public:

  BTMrcds() { }

  void display();
  };


extern BTMrcds btmRcds;



