// Labels in the Excel Spreadsheet Data, multiple rows of it


#include "stdafx.h"
#include "Labels.h"
#include "BTMrcd.h"
#include "BTMrcds.h"


Labels labels;


void Labels::acquire() {
CSVIter iter(btmRcds);
BTMrcd* rcd;
int     row;
int     col;

  for (row = 0, rcd = iter(); row < 6 && rcd; row++, rcd = iter++) {
    BRcdIter fldIter(*rcd);
    BTMfld*  fld;

    for (col = 0, fld = fldIter(); fld; col++, fld = fldIter++) {
      if (!fld->name.isEmpty()) {

        Label* lbl = find(col);

        if (lbl) {lbl->name[row] = fld->name; continue;}

        lbl = labels.allocate();   lbl->col = col;   lbl->name[row] = fld->name;   data = lbl;
        }
      }
    }
  }


void Labels::display() {
LblIter iter(*this);
Label*  lbl;
int     max0 = 0;
int     max1 = 0;
int     max2 = 0;
int     max3 = 0;
int     max4 = 0;
int     max5 = 0;
int     tab0;
int     tab1;
int     tab2;
int     tab3;
int     tab4;
int     tab5;
int     tab6;

  for (lbl = iter(); lbl; lbl = iter++) {
    maxLng(lbl->name[0], max0);
    maxLng(lbl->name[1], max1);
    maxLng(lbl->name[2], max2);
    maxLng(lbl->name[3], max3);
    maxLng(lbl->name[4], max4);
    maxLng(lbl->name[5], max5);
    }

  tab0 = 3;
  tab1 = tab0 + 2;
  tab2 = tab1 + max1 + 1;
  tab3 = tab2 + max2 + 1;
  tab4 = tab3 + max3 + 1;
  tab5 = tab4 + max4 + 1;
  tab6 = tab5 + max5 + 1;

  notePad << nClrTabs << nSetRTab(tab0) << nSetTab(tab1) << nSetTab(tab2) << nSetTab(tab3);
  notePad << nSetTab(tab4) << nSetTab(tab5);

  notePad << nTab << _T("Col")  << nTab << _T("Row1") << nTab << _T("Row2");
  notePad << nTab << _T("Row3") << nTab << _T("Row4") << nTab << _T("Row5") << nCrlf;

  for (lbl = iter(); lbl; lbl = iter++) {
    lbl->display();
    }
  }


void Labels::maxLng(String& s, int& max) {int lng = s.length();  if (lng > max) max = lng;}


void Label::display() {
int i;

  notePad << nTab << col;

  for (i = 1; i < noElements(name); i++) notePad << nTab << name[i];

  notePad << nCrlf;
  }


void Labels::setFour(int col) {
Label* lbl = find(col);   if (!lbl) return;
String t;

  t = lbl->name[3];   if (!t.isEmpty()) three = t;
  t = lbl->name[4];   if (!t.isEmpty()) four  = lastWord(t);
  }


String Labels::fourFive(int col) {
Label*  lbl;
String  five;
String  label;

  lbl = find(col);   if (!lbl) return _T("");

  five  = lbl->name[5];

  if (five.isEmpty() && !four.isEmpty()) label = four;

  else {
    if (five[0] == _T('#')) five = five.substr(1);

    label = four + _T('_') + five;
    }

  if (_T('0') <= label[0] && label[0] <= _T('9')) label = _T('a') + label;

  return label;
  }


String Labels::lastWord(String& t) {
String s   = t;
int    pos;

  while (s.length() > 14) {

    pos = s.find(_T(' '));   if (pos < 0) break;

    s = s.substr(pos+1);
    }

  return s;
  }


String Labels::find(int row, int col) {
Label*  lbl;

  lbl = find(col);  if (lbl) return lbl->name[row];

  return _T("");
  }


Label* Labels::find(int col) {
LblIter iter(*this);
Label*  lbl;

  for (lbl = iter(); lbl && lbl->col <= col; lbl = iter++) if (lbl->col == col) return lbl;

  return 0;
  }



void Label::copy(Label& lbl) {
  col = lbl.col;   for (int i = 0; i < noElements(name); i++) name[i] = lbl.name[i];
  }



