// Member Records


#pragma once
#include "ExpandableP.h"
#include "TrainingRcd.h"


class CSVrcds;
class CSVrcd;

class TrainingRcds;
typedef DatumPtrT< TrainingRcd> TrainingRcdP;
typedef IterT<TrainingRcds, TrainingRcd> TRcdsIter;



class TrainingRcds {

String lastFcc;

ExpandableP<TrainingRcd, TrainingRcdP, 2> data;

public:

  TrainingRcds() { }
 ~TrainingRcds() { }

  void load(CSVrcds& csvRcds);

  void compare();

  void display();

private:

  void maxLng(String& s, int& max);

  void dsplyData(TrainingRcd* rcd, String& status, double count);

  int  isDone(String& item) {return item.isEmpty() ? 0 : 1;}

  // returns either a pointer to data (or datum) at index i in array or zero

  TrainingRcd* datum(int i) {return 0 <= i && i < nData() ? data[i].p : 0;}       // or data[i].p

  int   nData()      {return data.end();}                       // returns number of data items in array

  void  removeDatum(int i) {if (0 <= i && i < nData()) data.del(i);}

  friend typename TRcdsIter;
  };


extern TrainingRcds trainingRcds;
