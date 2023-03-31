// BTM Records


#include "pch.h"
#include "BTMrcds.h"
#include "NotePad.h"


BTMrcds btmRcds;


void BTMrcds::display() {
CSVIter iter(*this);
BTMrcd* rcd;
int     i;
String  s;

  notePad << nSetRTab(3) << nSetTab(4);

  for (i = 0, rcd = iter(); rcd; i++, rcd = iter++)
                                                {notePad << nTab << i << nTab;    rcd->display(notePad);}
  }

