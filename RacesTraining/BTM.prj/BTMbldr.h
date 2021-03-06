// Code Builder


#pragma once
#include "BTMrcds.h"
#include "Expandable.h"


class Archive;



class BTMbldr {

public:

BTMrcd btmRcd;

  BTMbldr() { }
 ~BTMbldr() { }

  void getLabels();

  void prepareFieldNames(BTMrcd& rcd);
  void display();

  void OnPrepTrng_h();
  void OnPrepTrng_cpp();

private:

  void prepTrngCls();
  void prepComparison(TCchar* op);
  void prepTrngIter();

  void prepOpAssn();
  void prepSetFld();
  void prepGetFld();
  void prepDspAsCSV();
  void prepDataOut();
  void prepNData();
  };



extern BTMbldr btmBldr;

