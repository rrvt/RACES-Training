// Training Record


#pragma once
#include "Archive.h"
#include "CSVrcdC.h"


class TrainingRcd {

public:

String lastName;
String firstName;
String callSign;
String status;
String badge;
String responder;
String records;
String IS100b;
String IS200b;
String IS700a;
String IS800b;
String SEMS;
String orientation;
String a911Tour;
String meetings_1;
String meetings_2;
String meetings_3;
String netControl_1;
String netControl_2;
String netControl_3;
String hospitalNet;
String event;
String type;
String date;
String goKit;
String RF;
String MAC;
String typeIV_E;
String typeIV_F;
String typeIV_N;
String typeIV_S;
String typeIV_P;
String fundamentals;
String fieldOpsIIIA;
String fieldOpsIIIB_II;
String fieldOpsIII_II;
String msgPassing;
String xbandRepeat;
String NCIIIA;
String NCIIIB;
String NCII;
String packetIIIA;
String packetIIIB;
String packetII;
String shadowIII;
String eventPlan;
String yrEndSmmry;
String phone;
String email;
String altPhone;
String altEmail;

  TrainingRcd& operator= (CSVrcdC& csvRcd);

  void     dspAsCSV();
  void     dataOut(Archive& ar);

  bool     operator== (TrainingRcd& x) {return _tcsicmp(callSign, x.callSign) == 0;}
  bool     operator!= (TrainingRcd& x) {return _tcsicmp(callSign, x.callSign) != 0;}
  bool     operator>  (TrainingRcd& x) {return _tcsicmp(callSign, x.callSign) >  0;}
  bool     operator<  (TrainingRcd& x) {return _tcsicmp(callSign, x.callSign) <  0;}
  bool     operator>= (TrainingRcd& x) {return _tcsicmp(callSign, x.callSign) >= 0;}
  bool     operator<= (TrainingRcd& x) {return _tcsicmp(callSign, x.callSign) <= 0;}

// returns either a pointer to data (or datum) at index i in array or zero

  String* datum(int i) {return 0 <= i && i < nData() ? getFld(i) : 0;}

private:

  void     setFld(int i, String& s);
  String*  getFld(int i);

  int     nData();

  friend class TrngIter;
  };


class TrngIter {

int      iterX;
TrainingRcd& rcd;

public:

  enum Dir {Fwd, Rev};

  TrngIter(TrainingRcd& addrRcd) : rcd(addrRcd) { }
  TrngIter(TrngIter& iter)     : iterX(iter.iterX), rcd(iter.rcd) { }

  String* operator() (Dir rev = Fwd)
                                  {iterX = rev ? rcd.nData() : 0; return rev ? decr() : current();}
  String* operator++ (int)           {return iterX < rcd.nData() ? incr() : 0;}
  String* operator-- (int)           {return iterX > 0           ? decr() : 0;}

  String* current()                  {return rcd.getFld(iterX);}

  TrngIter& operator= (TrngIter& iter)   {iterX = iter.iterX; rcd = iter.rcd;}

  bool  isLast()                     {return iterX + 1 == rcd.nData();}
  bool  isFirst()                    {return iterX <= 0;}

private:

  String* incr() {return iterX < rcd.nData() ? rcd.datum(++iterX) : 0;}
  String* decr() {return iterX > 0           ? rcd.datum(--iterX) : 0;}

  TrngIter() : rcd(*(TrainingRcd*)0) { }
  };
