// CSV Records -- Used to load file, then the records are transferred to the Training Records data
// structure.


#pragma once
#include "CSVrcdC.h"


class CSVrcd : public CSVrcdC {
public:

  CSVrcd() { }
 ~CSVrcd() { }

  };


typedef DatumPtrT<CSVrcd, int>          CSVrcdP;
typedef CSVRcdsT< CSVrcd, int, CSVrcdP> CSVRcdsB;
typedef CSVIterT< CSVrcd, int, CSVrcdP> CSVIter;


class CSVrcds : public CSVRcdsB {
public:

  CSVrcds() { }
 ~CSVrcds() { }

  void display();
  };


extern CSVrcds csvRcds;


