// RacesTrainingDoc.cpp : implementation of the RacesTrainingDoc class


#include "stdafx.h"
#include "RacesTrainingDoc.h"
#include "CSVrcds.h"
#include "filename.h"
#include "GetPathDlg.h"
#include "IniFile.h"
#include "MapData.h"
#include "MbrRcds.h"
#include "MessageBox.h"
#include "NotePad.h"
#include "Options.h"
#include "Resource.h"
#include "RacesTraining.h"
#include "RacesTrainingView.h"
#include "TrnNeeded.h"


// RacesTrainingDoc

IMPLEMENT_DYNCREATE(RacesTrainingDoc, CDoc)

BEGIN_MESSAGE_MAP(RacesTrainingDoc, CDoc)
  ON_COMMAND(ID_LoadDatabase, &OnLoadDatabase)
  ON_COMMAND(ID_LoadCSVFile,  &onLoadTrainingCSVfile)
  ON_COMMAND(ID_CompareSets,  &onComparison)
  ON_COMMAND(ID_NonResponder, &onNonRspdrNeeded)
  ON_COMMAND(ID_LegacyNeeded, &onLegacyNeeded)
  ON_COMMAND(ID_Options,      &OnOptions)
END_MESSAGE_MAP()


// RacesTrainingDoc construction/destruction

RacesTrainingDoc::RacesTrainingDoc() noexcept : dataSource(NotePadSrc) {

  pathDsc = PathDlgDsc(_T("RACES Training "), _T(""), _T("csv"), _T("*.csv"));
  }

RacesTrainingDoc::~RacesTrainingDoc() { }


// RacesTrainingDoc commands


void RacesTrainingDoc::OnLoadDatabase() {
String title;
String ext;

  notePad.clear();

  if (getPathDlg(_T("Database"), 0, _T("accdb"), _T("*.accdb"), theApp.databasePath))
                                       iniFile.writeString(FileSection, DBFileKey, theApp.databasePath);

  maps.initializeMaps(DBFileKey, theApp.databasePath);   display(NotePadSrc);
  }


void RacesTrainingDoc::OnOptions() {options(view());  view()->setOrientation(options.orient);}


void RacesTrainingDoc::onLoadTrainingCSVfile() {

  notePad.clear(); dataSource = CSVSrc;

  pathDsc = PathDlgDsc(_T("RACES Training "), pathDsc.name, _T("csv"), _T("*.csv"));

  if (!setPath(pathDsc)) return;

  pathDsc.name = getMainName(path);

  csvRcds.clear();  //mbrInfo.clear();

  if (!OnOpenDocument(path)) messageBox(_T(" Not Loaded!"));

  mbrRcds.load(csvRcds);   mbrRcds.display();

  display(CSVSrc);
  }


void RacesTrainingDoc::onComparison() {mbrRcds.compare();   display(NotePadSrc);}


void RacesTrainingDoc::onNonRspdrNeeded() {nonRspdrs.display(_T("Non Responders")); display(NotePadSrc);}


void RacesTrainingDoc::onLegacyNeeded()   {legacy.display(_T("Legacy Members"));    display(NotePadSrc);}


void RacesTrainingDoc::display(DataSource ds) {dataSource = ds; invalidate();}



// RacesTrainingDoc serialization

void RacesTrainingDoc::serialize(Archive& ar) {

  if (ar.isStoring())
    switch(dataSource) {
      case MbrSrc     :
      case NotePadSrc : notePad.archive(ar); return;
      case CSVSrc     :
      default         : return;
      }
  else
    switch(dataSource) {
      case NotePadSrc : return;
      case CSVSrc     : csvRcds.load(ar);   return;
      default         : return;
      }
  }


// RacesTrainingDoc diagnostics

#ifdef _DEBUG
void RacesTrainingDoc::AssertValid() const
{
  CDocument::AssertValid();
}

void RacesTrainingDoc::Dump(CDumpContext& dc) const
{
  CDocument::Dump(dc);
}
#endif //_DEBUG




#if 0
void RacesTrainingDoc::OnInfoByName() {loadMbrInfo(NameSort);}
void RacesTrainingDoc::OnInfoByFCC()  {loadMbrInfo(CallSignSort);}



void RacesTrainingDoc::loadMbrInfo(BadgeSort bdgSort)
                             {mbrInfo.load(csvRcds, bdgSort);   dataSource = MbrInfoSrc;   invalidate();}


void RacesTrainingDoc::displayCSV() {
CSVIter iter(csvRcds);
CSVRcd* rcd;

  notePad.clear();   view()->setFont(_T("Courier New"), 120);

  csvRcds.getMaxs();   csvRcds.setTabs();

  for (rcd = iter(); rcd; rcd = iter++) {rcd->display();}
  }


void RacesTrainingDoc::displayMbrInfo() {
  notePad.clear();   view()->setFont(_T("Courier New"), 120);

  mbrInfo.getMaxs();   mbrInfo.setTabs();

  mbrInfo.display();
  }
#endif



#if 0
MbrIter      iter(mbrRcds);
int          i;
TrainingRcd* trn;
String       fcc;

  notePad.clear();

  for (i = 0, trn = iter(); trn; i++, trn = iter++) {
    if (i < 6) continue;

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
    String rspdrDate = trn->responder;


    fcc = trn->callSign;

    MemberRecord* mbr = memberTable.get(fcc);   if (!mbr) continue;
    bool badgeOK = mbr->BadgeOK;
    String rspdr = mbr->Responder;

    if (trnBdgOK && !badgeOK) {
      notePad << fcc << nTab << trn->firstName << nTab << trn->lastName << nTab;
      notePad << _T("Badge is OK according to Training Records") << nCrlf;
      }
    else if ((!trnBdgOK) && badgeOK) {
      notePad << fcc << nTab << trn->firstName << nTab << trn->lastName << nTab;
      notePad << _T("Training Records show badge not OK") << nCrlf;
      }

    if (!rspdrOK && !rspdrDate.isEmpty()) {
      notePad << fcc << nTab << trn->firstName << nTab << trn->lastName << nTab;
      notePad << _T("Legacy Responder, needs traiing records") << nCrlf;
      }

    if (rspdrOK && !rspdr) {
      notePad << fcc << nTab << trn->firstName << nTab << trn->lastName << nTab;
      notePad << _T("Responder is OK according to Training Records") << nCrlf;
      }
    else if (!rspdrOK && rspdr) {
      notePad << fcc << nTab << trn->firstName << nTab << trn->lastName << nTab;
      notePad << _T("Is eligible to be a responder") << nCrlf;
      }
    }
#endif

