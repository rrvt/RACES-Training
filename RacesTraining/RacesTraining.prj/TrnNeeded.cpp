// Training Needed


#include "pch.h"
#include "TrnNeeded.h"
#include "TrainingRcd.h"


TrnNeeded legacy;
TrnNeeded nonRspdrs;


static const TCchar* trnNames[NoTrnElements] = {_T("IS-100b"),
                                                _T("IS-200b"),
                                                _T("IS-700a"),
                                                _T("IS-800b"),
                                                _T("CA SEMS"),
                                                _T("Orientation"),
                                                _T("911 Tour"),
                                                _T("Meeting 1"),
                                                _T("Meeting 2"),
                                                _T("Meeting 3"),
                                                _T("Net Control 1"),
                                                _T("Net Control 2"),
                                                _T("Net Control 3"),
                                                _T("Hospital Net"),
                                                _T("Event"),
                                                _T("CERT"),
                                                };


void TrnNeeded::addNeeded(TrainingRcd* rcd) {
int i = 0;

  count++;

  inc(rcd->IS100b,       i);
  inc(rcd->IS200b,       i);
  inc(rcd->IS700a,       i);
  inc(rcd->IS800b,       i);
  inc(rcd->SEMS,         i);
  inc(rcd->orientation,  i);
  inc(rcd->a911Tour,     i);
  inc(rcd->meetings_1,   i);
  inc(rcd->meetings_2,   i);
  inc(rcd->meetings_3,   i);
  inc(rcd->netControl_1, i);
  inc(rcd->netControl_2, i);
  inc(rcd->netControl_3, i);
  inc(rcd->hospitalNet,  i);
  inc(rcd->event,        i);
  inc(rcd->date,         i);
  }


void TrnNeeded::inc(String& s, int& i) {if (s.isEmpty()) data[i]++;    i++;}



void TrnNeeded::display(TCchar* title) {
int i;

  notePad.clear();   setMax();

  notePad << title << _T(" Training Needed -- Number of Members: ") << count << nCrlf << nCrlf;

  notePad << nClrTabs << nSetRTab(20) << nSetTab(22);

  for (i = 0; i < noElements(data); i++) {
    notePad << trnNames[i] << _T(':') << nTab << data[i] << nTab;
    dspBar(data[i]);
    notePad << nCrlf;
    }
  }


void TrnNeeded::dspBar(int n) {
double n1 = 50.0 * n / max;
int    n2 = int(n1 + 0.5);

  for (int i = 0; i < n2; i++) notePad << _T("X");
  }

