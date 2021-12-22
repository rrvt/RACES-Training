// CSV records, one record per line


#pragma once
#include "BTMrcd.h"


class BTMrcds;
typedef DatumPtrT< BTMrcd> BTMrcdP;
typedef CSVRcdsT<BTMrcd, BTMrcdP> BTMrcdsB;
typedef CSVIterT<BTMrcd, BTMrcdP> CSVIter;


class BTMrcds : public BTMrcdsB {

public:

  BTMrcds() { }

  void display();
  };


extern BTMrcds btmRcds;



