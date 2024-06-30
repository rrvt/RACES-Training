// Training Record


#include "pch.h"
#include "TrainingRcd.h"
#include "Utilities.h"


static const int noAddrRcdFlds = 55;


TrainingRcd& TrainingRcd::operator= (CSVrcdC& csvRcd) {
CSVrcdIter iter(csvRcd);
CSVfld*    fld;
int        i;

  for (fld = iter(), i = 0; fld; fld = iter++, i++)
                                 {String& p = removeQuotes(fld->name);   p.trim();   setFld(i, p);}
  return *this;
  }


void TrainingRcd::setFld(int i, String& s) {
  switch(i) {
    case  1: lastName                 = s; return;
    case  2: firstName                = s; return;
    case  3: callSign                 = s; return;
    case  4: status                   = s; return;
    case  5: badge                    = s; return;
    case  6: responder                = s; return;
    case  7: records                  = s; return;
    case  9: IS100b                   = s; return;
    case 10: IS200b                   = s; return;
    case 11: IS700a                   = s; return;
    case 12: IS800b                   = s; return;
    case 13: SEMS                     = s; return;
    case 14: orientation              = s; return;
    case 15: a911Tour                 = s; return;
    case 16: meetings_1               = s; return;
    case 17: meetings_2               = s; return;
    case 18: meetings_3               = s; return;
    case 19: netControl_1             = s; return;
    case 20: netControl_2             = s; return;
    case 21: netControl_3             = s; return;
    case 22: hospitalNet              = s; return;
    case 23: event                    = s; return;
    case 24: type                     = s; return;
    case 25: date                     = s; return;
    case 27: goKit                    = s; return;
    case 28: RF                       = s; return;
    case 29: MAC                      = s; return;
    case 30: typeIV_E                 = s; return;
    case 31: typeIV_F                 = s; return;
    case 32: typeIV_N                 = s; return;
    case 33: typeIV_S                 = s; return;
    case 34: typeIV_P                 = s; return;
    case 35: fundamentals             = s; return;
    case 36: fieldOpsIIIA             = s; return;
    case 37: fieldOpsIIIB_II          = s; return;
    case 38: fieldOpsIII_II           = s; return;
    case 39: msgPassing               = s; return;
    case 40: xbandRepeat              = s; return;
    case 41: NCIIIA                   = s; return;
    case 42: NCIIIB                   = s; return;
    case 43: NCII                     = s; return;
    case 44: packetIIIA               = s; return;
    case 45: packetIIIB               = s; return;
    case 46: packetII                 = s; return;
    case 47: shadowIII                = s; return;
    case 48: eventPlan                = s; return;
    case 49: yrEndSmmry               = s; return;
    case 51: phone                    = s; return;
    case 52: email                    = s; return;
    case 53: altPhone                 = s; return;
    case 54: altEmail                 = s; return;
    default: return;
    };
  }


String* TrainingRcd::getFld(int i) {
static String nS = _T("");

  switch(i) {
    case  1: return &lastName;
    case  2: return &firstName;
    case  3: return &callSign;
    case  4: return &status;
    case  5: return &badge;
    case  6: return &responder;
    case  7: return &records;
    case  9: return &IS100b;
    case 10: return &IS200b;
    case 11: return &IS700a;
    case 12: return &IS800b;
    case 13: return &SEMS;
    case 14: return &orientation;
    case 15: return &a911Tour;
    case 16: return &meetings_1;
    case 17: return &meetings_2;
    case 18: return &meetings_3;
    case 19: return &netControl_1;
    case 20: return &netControl_2;
    case 21: return &netControl_3;
    case 22: return &hospitalNet;
    case 23: return &event;
    case 24: return &type;
    case 25: return &date;
    case 27: return &goKit;
    case 28: return &RF;
    case 29: return &MAC;
    case 30: return &typeIV_E;
    case 31: return &typeIV_F;
    case 32: return &typeIV_N;
    case 33: return &typeIV_S;
    case 34: return &typeIV_P;
    case 35: return &fundamentals;
    case 36: return &fieldOpsIIIA;
    case 37: return &fieldOpsIIIB_II;
    case 38: return &fieldOpsIII_II;
    case 39: return &msgPassing;
    case 40: return &xbandRepeat;
    case 41: return &NCIIIA;
    case 42: return &NCIIIB;
    case 43: return &NCII;
    case 44: return &packetIIIA;
    case 45: return &packetIIIB;
    case 46: return &packetII;
    case 47: return &shadowIII;
    case 48: return &eventPlan;
    case 49: return &yrEndSmmry;
    case 51: return &phone;
    case 52: return &email;
    case 53: return &altPhone;
    case 54: return &altEmail;
    default: return &nS;
    };
  }


void TrainingRcd::dspAsCSV() {
TrngIter  iter(*this);
String* p;
int     i;
String  s;

  notePad << nClrTabs << nSetTab(40);

  s.format(_T("%-35s: "), callSign.str());   notePad << s << nTab;

  for (i = 0, p = iter(); p; i++, p = iter++) {
    if (i) notePad << _T(',');

    notePad << *p;
    }

  notePad << nCrlf;
  }


void TrainingRcd::dataOut(Archive& ar) {
TrngIter  iter(*this);
String* p;
int     i;
int     pos;

  for (i = 0, p = iter(); p; i++, p = iter++)  {
    if (i) ar << _T(',');

    pos = p->find(_T(','));

    if (pos < 0) ar << *p;
    else         ar << _T('"') << *p << _T('"');
    }

  ar << aCrlf;
  }


int TrainingRcd::nData() {return noAddrRcdFlds;}
