// CSV Records -- Used to load file, then the records are transferred to the Training Records data
// structure.


#pragma once
#include "CSVrcdC.h"


class CSVrcd : public CSVrcdC {
public:

  CSVrcd() { }
 ~CSVrcd() { }

  };


typedef DatumPtrT< CSVrcd> CSVrcdP;
typedef CSVRcdsT<CSVrcd, CSVrcdP> CSVRcdsB;
typedef CSVIterT<CSVrcd, CSVrcdP> CSVIter;


class CSVrcds : public CSVRcdsB {
public:

  CSVrcds() { }
 ~CSVrcds() { }

  void display();
  };


extern CSVrcds csvRcds;


