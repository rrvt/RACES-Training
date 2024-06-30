// Code Builder


#include "pch.h"

#include "BTMbldr.h"
#include "Archive.h"
#include "Labels.h"
#include "NotePad.h"
#include "BTMrcds.h"


BTMbldr btmBldr;


void BTMbldr::prepareFieldNames(BTMrcd& rcd) {
BTMfld*  fld;
int      i;
String   s;

  btmRcd = rcd;   BRcdIter iter(btmRcd);

  for (i = 0, fld = iter(); fld; i++, fld = iter++) fld->cleanUpName(i);
  }


void BTMbldr::display() {
BRcdIter iter(btmRcd);
BTMfld*  fld;
int      i;
String   four;
String   t;

  notePad << nClrTabs << nSetRTab(3) << nSetTab(4) << nSetTab(24);

  for (i = 0, fld = iter(); fld; i++, fld = iter++) {

    t = labels.find(4, i);
    if (t != four && !t.isEmpty())
      {notePad << nTab << i << _T(":") << nTab << _T("Header: ") << t << nCrlf;    four = t;}


    if (fld->name.isEmpty()) continue;

    notePad << nTab << i << _T(":") << nTab << labels.find(5, i);
    notePad << nTab << _T(" => ") << fld->name << nCrlf;
    }

  notePad << _T("\nNumber of Fields: ") << i << nCrlf;
  }


void BTMbldr::OnPrepTrng_h() {
  prepTrngCls();  notePad << nCrlf << nCrlf;
  prepTrngIter();
  }


void BTMbldr::prepTrngCls() {
BRcdIter iter(btmRcd);
BTMfld*  d;

  notePad.clear();

  notePad << _T("// Training Record") << nCrlf;
  notePad << nCrlf;
  notePad << nCrlf;

  notePad << _T("#pragma once") << nCrlf;
  notePad << _T("#include \"Archive.h\"") << nCrlf;
  notePad << _T("#include \"CSVrcdC.h\"") << nCrlf;
  notePad << nCrlf;
  notePad << nCrlf;
  notePad << _T("class TrainingRcd {") << nCrlf << nCrlf;

  notePad << _T("public:") << nCrlf << nCrlf;

  for (d = iter(); d; d = iter++)
                               if (d->legal) notePad << _T("String ") + d->name + _T(";") << nCrlf;

  notePad << nCrlf;
  notePad << _T("  TrainingRcd& operator= (CSVrcdC& csvRcd);") << nCrlf;
  notePad << nCrlf;

  notePad << _T("  void     dspAsCSV();") << nCrlf;
  notePad << _T("  void     dataOut(Archive& ar);") << nCrlf;
  notePad << nCrlf;

  prepComparison(_T("=="));
  prepComparison(_T("!="));
  prepComparison(_T("> "));
  prepComparison(_T("< "));
  prepComparison(_T(">="));
  prepComparison(_T("<="));  notePad << nCrlf;

  notePad << _T("// returns either a pointer to data (or datum) at index i in array or zero");
  notePad << nCrlf << nCrlf;

  notePad << _T("  String* datum(int i) {return 0 <= i && i < nData() ? getFld(i) : 0;}");
  notePad << nCrlf << nCrlf;

  notePad << _T("private:") << nCrlf << nCrlf;

  notePad << _T("  void     setFld(int i, String& s);") << nCrlf;
  notePad << _T("  String*  getFld(int i);") << nCrlf << nCrlf;

  notePad << _T("  int     nData();") << nCrlf << nCrlf;

  notePad << _T("  friend class TrngIter;") << nCrlf;

  notePad << _T("  };") << nCrlf;
  }


void BTMbldr::prepComparison(TCchar* op) {

  notePad << _T("  bool     operator") << op << _T(" (TrainingRcd& x) {return _tcsicmp(");
  notePad << _T("callSign") << _T(", x.") << _T("callSign") << _T(") ") << op << _T(" 0;}");
  notePad << nCrlf;
  }



void BTMbldr::prepTrngIter() {

  notePad << _T("class TrngIter {") << nCrlf << nCrlf;

  notePad << _T("int      iterX;") << nCrlf;
  notePad << _T("TrainingRcd& rcd;") << nCrlf << nCrlf;

  notePad << _T("public:") << nCrlf << nCrlf;

  notePad << _T("  enum Dir {Fwd, Rev};") << nCrlf << nCrlf;

  notePad << _T("  TrngIter(TrainingRcd& addrRcd) : rcd(addrRcd) { }") << nCrlf;
  notePad << _T("  TrngIter(TrngIter& iter)     : iterX(iter.iterX), rcd(iter.rcd) { }") << nCrlf;
  notePad << nCrlf;

  notePad << _T("  String* operator() (Dir rev = Fwd) {iterX = rev ? rcd.nData() : 0;");
  notePad << _T(" return rev ? decr() : current();}") << nCrlf;
  notePad << _T("  String* operator++ (int)           {return iterX < rcd.nData() ? incr() : 0;}");
  notePad << nCrlf;
  notePad << _T("  String* operator-- (int)           {return iterX > 0           ? decr() : 0;}");
  notePad << nCrlf << nCrlf;

  notePad << _T("  String* current()                  {return rcd.getFld(iterX);}");
  notePad << nCrlf << nCrlf;

  notePad << _T("  TrngIter& operator= (TrngIter& iter)   {iterX = iter.iterX; rcd = iter.rcd;}");
  notePad << nCrlf << nCrlf;

  notePad << _T("  bool  isLast()                     {return iterX + 1 == rcd.nData();}");
  notePad << nCrlf;
  notePad << _T("  bool  isFirst()                    {return iterX <= 0;}") << nCrlf << nCrlf;

  notePad << _T("private:") << nCrlf << nCrlf;

  notePad << _T("  String* incr() {return iterX < rcd.nData() ? rcd.datum(++iterX) : 0;}");
  notePad << nCrlf;
  notePad << _T("  String* decr() {return iterX > 0           ? rcd.datum(--iterX) : 0;}");
  notePad << nCrlf << nCrlf;

  notePad << _T("  TrngIter() : rcd(*(TrainingRcd*)0) { }") << nCrlf;
  notePad << _T("  };") << nCrlf;
  }


void BTMbldr::OnPrepTrng_cpp() {
String   s;

  notePad.clear();

  notePad << _T("// Training Record") << nCrlf;
  notePad << nCrlf;
  notePad << nCrlf;

  notePad << _T("#include \"stdafx.h\"") << nCrlf;
  notePad << _T("#include \"TrainingRcd.h\"") << nCrlf;
  notePad << _T("#include \"Utilities.h\"") << nCrlf;

  notePad << nCrlf << nCrlf;

  s.format(_T("static const int noAddrRcdFlds = %i;"), btmRcd.nFields());    notePad << s << nCrlf;
  notePad << nCrlf << nCrlf;

  prepOpAssn();   notePad << nCrlf << nCrlf;

  prepSetFld();   notePad << nCrlf << nCrlf;

  prepGetFld();   notePad << nCrlf << nCrlf;

  prepDspAsCSV(); notePad << nCrlf << nCrlf;

  prepDataOut();  notePad << nCrlf << nCrlf;

  prepNData();
  }




void BTMbldr::prepOpAssn() {

  notePad << _T("TrainingRcd& TrainingRcd::operator= (CSVrcdC& csvRcd) {") << nCrlf;
  notePad << _T("CSVrcdIter iter(csvRcd);") << nCrlf;
  notePad << _T("CSVfld*    fld;") << nCrlf;
  notePad << _T("int        i;") << nCrlf << nCrlf;

  notePad << _T("  for (fld = iter(), i = 0; fld; fld = iter++, i++) ") << nCrlf;
  notePad << _T("                                       {String& p = removeQuotes(fld->name);");
  notePad << _T("   p.trim();   setFld(i, p);}") << nCrlf;

  notePad << _T("  return *this;") << nCrlf;
  notePad << _T("  }") << nCrlf;
  }



void BTMbldr::prepSetFld() {
BRcdIter iter(btmRcd);
BTMfld*  d;
int      i;
String   s;

  notePad << _T("void TrainingRcd::setFld(int i, String& s) {") << nCrlf;
  notePad << _T("  switch(i) {") << nCrlf;

  for (d = iter(), i = 0; d; d = iter++, i++) if (d->legal) {
    s.format(_T("    case %2i: %-24s = s; return;"), i, d->name.str());   notePad << s << nCrlf;
    }
  notePad << _T("    default: return;") << nCrlf;
  notePad << _T("    };") << nCrlf;
  notePad << _T("  }") << nCrlf;
  }


void BTMbldr::prepGetFld() {
BRcdIter iter(btmRcd);
BTMfld*  d;
int      i;
String   s;

  notePad << _T("String* TrainingRcd::getFld(int i) {") << nCrlf;
  notePad << _T("static String nS = _T(\"\");") << nCrlf;
  notePad << nCrlf;
  notePad << _T("  switch(i) {") << nCrlf;

  for (d = iter(), i = 0; d; d = iter++, i++) if (d->legal) {
    s.format(_T("    case %2i: return &%s;"), i, d->name.str());   notePad << s << nCrlf;
    }
  notePad << _T("    default: return &nS;") << nCrlf;
  notePad << _T("    };") << nCrlf;
  notePad << _T("  }") << nCrlf;
  }



void BTMbldr::prepDspAsCSV() {
String s;
String t;

  notePad << _T("void TrainingRcd::dspAsCSV() {") << nCrlf;
  notePad << _T("TrngIter  iter(*this);") << nCrlf;
  notePad << _T("String* p;") << nCrlf;
  notePad << _T("int     i;") << nCrlf;
  notePad << _T("String  s;") << nCrlf << nCrlf;


  notePad << _T("  notePad << nClrTabs << nSetTab(40);") << nCrlf << nCrlf;

  t = _T("%-35s:");
  s.format(_T("  s.format(_T(\"%s \"), callSign.str());"), t.str());
  s += _T("   notePad << s << nTab;");

  notePad << s << nCrlf << nCrlf;

  notePad << _T("  for (i = 0, p = iter(); p; i++, p = iter++) {") << nCrlf;
  notePad << _T("    if (i) notePad << _T(',');") << nCrlf << nCrlf;

  notePad << _T("    notePad << *p;") << nCrlf;
  notePad << _T("    }") << nCrlf << nCrlf;
  notePad << _T("  notePad << nCrlf;") << nCrlf;
  notePad << _T("  }") << nCrlf;
  }


void BTMbldr::prepDataOut() {

  notePad << _T("void TrainingRcd::dataOut(Archive& ar) {") << nCrlf;
  notePad << _T("TrngIter  iter(*this);") << nCrlf;
  notePad << _T("String* p;") << nCrlf;
  notePad << _T("int     i;") << nCrlf;
  notePad << _T("int     pos;") << nCrlf << nCrlf;

  notePad << _T("  for (i = 0, p = iter(); p; i++, p = iter++)  {") << nCrlf;
  notePad << _T("    if (i) ar << _T(',');") << nCrlf << nCrlf;

  notePad << _T("    pos = p->find(_T(','));") << nCrlf << nCrlf;

  notePad << _T("    if (pos < 0) ar << *p;") << nCrlf;
  notePad << _T("    else         ar << _T('\"') << *p << _T('\"');") << nCrlf;
  notePad << _T("    }") << nCrlf << nCrlf;

  notePad << _T("  ar << aCrlf;") << nCrlf;
  notePad << _T("  }") << nCrlf;
  }


void BTMbldr::prepNData() {
  notePad << _T("int TrainingRcd::nData() {return noAddrRcdFlds;}") << nCrlf;
  }




