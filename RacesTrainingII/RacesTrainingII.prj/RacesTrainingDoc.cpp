// RacesTrainingDoc.cpp : implementation of the RacesTrainingDoc class


#include "stdafx.h"
#include "RacesTrainingDoc.h"
#include "CSVrcds.h"
#include "DBtables.h"
#include "filename.h"
#include "GetPathDlg.h"
#include "IniFile.h"
#include "TrainingRcds.h"
#include "MessageBox.h"
#include "NotePad.h"
#include "Options.h"
#include "Resource.h"
#include "RacesTraining.h"
#include "RacesTrainingView.h"
#include "TrnNeeded.h"


TCchar* FileSection = _T("FileSection");
TCchar* DBFileKey   = _T("DBfile");


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

  dbTables.load(theApp.databasePath);

  display(NotePadSrc);
  }


void RacesTrainingDoc::OnOptions() {options(view());  view()->setOrientation(options.orient);}


void RacesTrainingDoc::onLoadTrainingCSVfile() {

  notePad.clear(); dataSource = CSVSrc;

  pathDsc = PathDlgDsc(_T("RACES Training "), pathDsc.name, _T("csv"), _T("*.csv"));

  if (!setPath(pathDsc)) return;

  pathDsc.name = getMainName(path);

  csvRcds.clear();  //mbrInfo.clear();

  if (!OnOpenDocument(path)) messageBox(_T(" Not Loaded!"));

  trainingRcds.load(csvRcds);   trainingRcds.display();

  display(CSVSrc);
  }


void RacesTrainingDoc::onComparison() {trainingRcds.compare();   display(NotePadSrc);}


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


