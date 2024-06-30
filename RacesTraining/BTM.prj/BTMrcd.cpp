// BTM Record Definition


#include "pch.h"
#include "BTMrcd.h"
#include "Labels.h"


void BTMfld::cleanUpName(int col) {
String s;
bool   cap;
bool   cap1;

  s = removeChs(name);

  labels.setFour(col);

  if (s[0] == _T('#') || s.length() <= 1)
    {s = labels.fourFive(col);   s = removeChs(s);}

  if (s.isEmpty()) return;

  Tchar& ch = s[0];

  cap  = _T('A') <= ch  && ch  <= _T('Z');

  Tchar  ch1 = s.length() >= 2 ? s[1] : 0;  cap1 = _T('A') <= ch1 && ch1 <= _T('Z');

  if (cap && !cap1) ch += _T('a') - _T('A');

  if (s == _T("YESummary")) s = _T("yrEndSmmry");

  name = s; legal = true;
  }




String BTMfld::removeChs(String& sym) {
int    lng;
int    i;
String s;

  lng = sym.length();

  for (i = 0; i < lng; i++) {
    Tchar& ch = sym[i];

    if (ch == _T('/')) {s += _T('_'); continue;}

    if (ch != _T(' ') && ch != _T(',') && ch != _T('.') && ch != _T('-')) {s += ch; continue;}
    }

  return s;
  }




