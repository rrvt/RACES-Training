// Member Records


#include "stdafx.h"
#include "TrainingRcds.h"
#include "CSVrcds.h"
#include "Database.h"
#include "TrnNeeded.h"


TrainingRcds trainingRcds;


void TrainingRcds::load(CSVrcds& csvRcds) {
CSVIter iter(csvRcds);
CSVrcd* csvRcd;

  for (csvRcd = iter(); csvRcd; csvRcd = iter++)
                                            {TrainingRcd& tngRcd = data.nextData();   tngRcd = *csvRcd;}
  }


void TrainingRcds::display() {
TRcdsIter    iter(*this);
TrainingRcd* rcd;
int          i;
int          maxCall         = 0;
int          maxFirst        = 0;
int          maxLast         = 0;
int          maxIS100b       = 0;
int          maxIS200b       = 0;
int          maxIS700a       = 0;
int          maxIS800b       = 0;
int          maxSEMS         = 0;
int          maxOrientation  = 0;
int          maxA911Tour     = 0;
int          maxMeetings_1   = 0;
int          maxMeetings_2   = 0;
int          maxMeetings_3   = 0;
int          maxNetControl_1 = 0;
int          maxNetControl_2 = 0;
int          maxNetControl_3 = 0;
int          maxHospitalNet  = 0;
int          maxEvent        = 0;
int          maxCERT         = 0;
int          tab0;
int          tab1;
int          tab2;
int          tab3;
int          tab4;
int          tab5;
int          tab6;
int          tab7;
int          tab8;
int          tab9;
int          tab10;
int          tab11;
int          tab12;
int          tab13;
int          tab14;
int          tab15;
int          tab16;
int          tab17;
int          tab18;
int          tab19;
int          tab20;
int          tab21;

  for (i = 0, rcd = iter(); rcd; i++, rcd = iter++) {
    if (i < 5) continue;

    maxLng(rcd->lastName,     maxLast);
    maxLng(rcd->firstName,    maxFirst);
    maxLng(rcd->callSign,     maxCall);
    maxLng(rcd->IS100b,       maxIS100b);
    maxLng(rcd->IS200b,       maxIS200b);
    maxLng(rcd->IS700a,       maxIS700a);
    maxLng(rcd->IS800b,       maxIS800b);
    maxLng(rcd->SEMS,         maxSEMS);
    maxLng(rcd->orientation,  maxOrientation);
    maxLng(rcd->a911Tour,     maxA911Tour);
    maxLng(rcd->meetings_1,   maxMeetings_1);
    maxLng(rcd->meetings_2,   maxMeetings_2);
    maxLng(rcd->meetings_3,   maxMeetings_3);
    maxLng(rcd->netControl_1, maxNetControl_1);
    maxLng(rcd->netControl_2, maxNetControl_2);
    maxLng(rcd->netControl_3, maxNetControl_3);
    maxLng(rcd->hospitalNet,  maxHospitalNet);
    maxLng(rcd->event,        maxEvent);
    maxLng(rcd->date,         maxCERT);
    }

  tab0  =         maxCall         + 1;
  tab1  = tab0  + maxFirst        + 2;
  tab2  = tab1  + maxLast         + 1;
  tab3  = tab2  + maxIS100b       + 1;
  tab4  = tab3  + maxIS200b       + 1;
  tab5  = tab4  + maxIS700a       + 1;
  tab6  = tab5  + 8;
  tab7  = tab6  + maxIS800b       + 1;
  tab8  = tab7  + maxSEMS         + 1;
  tab9  = tab8  + maxOrientation  + 2;
  tab10 = tab9  + maxA911Tour     + 1;
  tab11 = tab10 + maxMeetings_1   + 1;
  tab12 = tab11 + maxMeetings_2   + 1;
  tab13 = tab12 + maxMeetings_3   + 1;
  tab14 = tab13 + maxNetControl_1 + 2;
  tab15 = tab14 + maxNetControl_2 + 2;
  tab16 = tab15 + maxNetControl_3 + 2;
  tab17 = tab16 + maxHospitalNet  + 2;
  tab18 = tab17 + maxEvent        + 2;
  tab19 = tab18 + maxCERT         + 2;
  tab20 = tab19 + 12;
  tab21 = tab20 + 7;

  notePad << nClrTabs       << nSetTab(tab0)  << nSetTab(tab1)  << nSetTab(tab2)  << nSetTab(tab3);
  notePad << nSetTab(tab4)  << nSetTab(tab5)  << nSetTab(tab6)  << nSetTab(tab7)  << nSetTab(tab8);
  notePad << nSetTab(tab9)  << nSetTab(tab10) << nSetTab(tab11) << nSetTab(tab12) << nSetTab(tab13);
  notePad << nSetTab(tab14) << nSetTab(tab15) << nSetTab(tab16) << nSetTab(tab17) << nSetTab(tab18);
  notePad << nSetTab(tab19) << nSetTab(tab20) << nSetTab(tab21);

  notePad << _T("Call") << nTab;
  notePad << _T("First") << nTab;
  notePad << _T("Last") << nTab;
  notePad << _T("FEMA") << nTab;
  notePad << _T("FEMA") << nTab;
  notePad << _T("FEMA") << nTab;
  notePad << _T("Badge") << nTab;
  notePad << _T("FEMA") << nTab;
  notePad << _T("Calif") << nTab;
  notePad << _T("Orient") << nTab;
  notePad << _T("911") << nTab;
  notePad << _T("Mtg") << nTab;
  notePad << _T("Mtg") << nTab;
  notePad << _T("Mtg") << nTab;
  notePad << _T("Net") << nTab;
  notePad << _T("Net") << nTab;
  notePad << _T("Net") << nTab;
  notePad << _T("Hsptl") << nTab;
  notePad << nCrlf;

  notePad << _T("Sign") << nTab;
  notePad << _T("Name") << nTab;
  notePad << _T("Name") << nTab;
  notePad << _T("IS 100b") << nTab;
  notePad << _T("IS 200b") << nTab;
  notePad << _T("IS 700a") << nTab;
  notePad << _T("Badge") << nTab;
  notePad << _T("IS 800b") << nTab;
  notePad << _T("SEMS") << nTab;
  notePad << _T("Orient") << nTab;
  notePad << _T("tour") << nTab;
  notePad << _T("#1") << nTab;
  notePad << _T("#2") << nTab;
  notePad << _T("#3") << nTab;
  notePad << _T("Ctrl 1") << nTab;
  notePad << _T("Ctrl 2") << nTab;
  notePad << _T("Ctrl 3") << nTab;
  notePad << _T("Net") << nTab;
  notePad << _T("Event") << nTab;
  notePad << _T("CERT") << nTab;
  notePad << _T("Responder") << nTab;
  notePad << _T("Status") << nTab;
  notePad << nCrlf;

  for (i = 0, rcd = iter(); rcd; i++, rcd = iter++) {

    if (i < 6) continue;
    bool badgeOK = !(rcd->IS100b.isEmpty() || rcd->IS200b.isEmpty() ||rcd->IS700a.isEmpty());
    String badgeStg = badgeOK ? _T("Yes") : _T("No");
    bool   rspndrOK = !(rcd->IS800b.isEmpty()       ||
                        rcd->SEMS.isEmpty()         ||
                        rcd->orientation.isEmpty()  ||
                        rcd->a911Tour.isEmpty()     ||
                        rcd->meetings_1.isEmpty()   ||
                        rcd->meetings_2.isEmpty()   ||
                        rcd->meetings_3.isEmpty()   ||
                        rcd->netControl_1.isEmpty() ||
                        rcd->netControl_2.isEmpty() ||
                        rcd->netControl_3.isEmpty() ||
                        rcd->hospitalNet.isEmpty()  ||
                        rcd->event.isEmpty()        ||
                        rcd->date.isEmpty()
                        );
    String responder = rspndrOK && badgeOK ? _T("Yes") : _T("No");

    notePad << rcd->callSign      << nTab;
    notePad << rcd->firstName     << nTab;
    notePad << rcd->lastName      << nTab;
    notePad << rcd->IS100b        << nTab;
    notePad << rcd->IS200b        << nTab;
    notePad << rcd->IS700a        << nTab;

    notePad << badgeStg           << nTab;

    notePad << rcd->IS800b        << nTab;
    notePad << rcd->SEMS          << nTab;
    notePad << rcd->orientation   << nTab;
    notePad << rcd->a911Tour      << nTab;
    notePad << rcd->meetings_1    << nTab;
    notePad << rcd->meetings_2    << nTab;
    notePad << rcd->meetings_3    << nTab;
    notePad << rcd->netControl_1  << nTab;
    notePad << rcd->netControl_2  << nTab;
    notePad << rcd->netControl_3  << nTab;
    notePad << rcd->hospitalNet   << nTab;
    notePad << rcd->event         << nTab;
    notePad << rcd->date          << nTab;
    notePad << responder          << nTab;
    notePad << rcd->status << _T(" ") << _T(' ') << rcd->responder;
    notePad << nCrlf;
    }
  }


void TrainingRcds::maxLng(String& s, int& max) {int lng = s.length();  if (lng > max) max = lng;}



void TrainingRcds::compare() {
TRcdsIter    iter(*this);
int          i;
TrainingRcd* trn;
String       fcc;

  legacy.clear();
  nonRspdrs.clear();

  notePad.clear();   notePad << nClrTabs << nSetTab(10) << nSetTab(37) << nSetTab(47);
  notePad << nTab << nTab << nTab << _T("Responder") << nCrlf;
  notePad << _T("FCC") << nTab << _T("Name") << nTab << _T("Status") << nTab << _T("% Complete") << nCrlf;

  for (i = 0, trn = iter(); trn; i++, trn = iter++) {
    if (i < 6) continue;

    int  count = 0;

    count += isDone(trn->IS100b);
    count += isDone(trn->IS200b);
    count += isDone(trn->IS700a);
    count += isDone(trn->IS800b);
    count += isDone(trn->SEMS);
    count += isDone(trn->orientation);
    count += isDone(trn->a911Tour);
    count += isDone(trn->meetings_1);
    count += isDone(trn->meetings_2);
    count += isDone(trn->meetings_3);
    count += isDone(trn->netControl_1);
    count += isDone(trn->netControl_2);
    count += isDone(trn->netControl_3);
    count += isDone(trn->hospitalNet);
    count += isDone(trn->event);
    count += isDone(trn->date);

    bool trnBdgOK = !(trn->IS100b.isEmpty() || trn->IS200b.isEmpty() ||trn->IS700a.isEmpty());
    bool trnOK    = !(trn->IS800b.isEmpty()       ||
                      trn->SEMS.isEmpty()         ||
                      trn->orientation.isEmpty()  ||
                      trn->a911Tour.isEmpty()     ||
                      trn->meetings_1.isEmpty()   ||
                      trn->meetings_2.isEmpty()   ||
                      trn->meetings_3.isEmpty()   ||
                      trn->netControl_1.isEmpty() ||
                      trn->netControl_2.isEmpty() ||
                      trn->netControl_3.isEmpty() ||
                      trn->hospitalNet.isEmpty()  ||
                      trn->event.isEmpty()        ||
                      trn->date.isEmpty()
                      );
    bool   rspdrOK   = trnOK && trnBdgOK;
    String rspdrDate = trn->responder.trim();


    fcc = trn->callSign;

    MbrRcd* mbr       = mbrTbl.find(fcc);   if (!mbr) continue;
    bool    badgeOK   = mbr->badgeOK;
    String  rspdr     = mbr->responder.trim();
    bool    dbRspdr   = !rspdr.isEmpty();
    long    statusID  = mbr->statusID;
    StsRcd* statusRcd = stsTbl.find(statusID);
    String  status    = statusRcd ? statusRcd->abbreviation : String(_T(""));

    if (status == _T("Fmr")) continue;

    if (!dbRspdr) nonRspdrs.addNeeded(trn);

    if (trnBdgOK && !badgeOK) {
      dsplyData(trn, status, count);
      notePad << nTab << _T("Badge is OK according to Training Records") << nCrlf;
      }
    else if ((!trnBdgOK) && badgeOK) {
      dsplyData(trn, status, count);
      notePad << nTab << _T("Training Records show badge not OK") << nCrlf;
      }

    if (rspdrDate.isEmpty()) {
      if (!rspdrOK && dbRspdr) {
        dsplyData(trn, status, count);
        notePad << nTab << _T("Marked as responder in database but not eligible and not legacy") << nCrlf;
        }
      }
    else {
      if (!rspdrOK) {
        dsplyData(trn, status, count);
        notePad << nTab << _T("Legacy Responder, training records incomplete") << nCrlf;
        legacy.addNeeded(trn);
        }
      if (!dbRspdr) {
        dsplyData(trn, status, count);
        notePad << nTab << _T("Marked as Responder in training records but not marked in the database");
        notePad << nCrlf;
        }
      }

    if (rspdrOK && !dbRspdr) {
      dsplyData(trn, status, count);
      notePad << nTab << _T("Responder is OK according to Training Records") << nCrlf;
      }
    }
  }


void TrainingRcds::dsplyData(TrainingRcd* rcd, String& status, double count) {
String fcc = rcd->callSign;
double t = count * 100.0 / 16.0;
String percent;

  percent.format(_T("%.1f"), t);

  if (fcc != lastFcc) {
    notePad << fcc << nTab << rcd->firstName << _T(" ") << rcd->lastName << nTab << status;
    notePad << nTab << percent << _T("%") << nCrlf;
    lastFcc = fcc;
    }
  }

