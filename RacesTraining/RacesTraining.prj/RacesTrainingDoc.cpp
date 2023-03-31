// RacesTrainingDoc.cpp : implementation of the RacesTrainingDoc class


#include "pch.h"
#include "RacesTrainingDoc.h"
#include "CSVrcds.h"
#include "Database.h"
#include "filename.h"
#include "GetPathDlg.h"
#include "IniFile.h"
#include "TrainingRcds.h"
#include "MessageBox.h"
#include "NotePad.h"
#include "Resource.h"
#include "RacesTraining.h"
#include "RacesTrainingView.h"
#include "TrnNeeded.h"


static TCchar* FileSection = _T("FileSection");
static TCchar* DBFileKey   = _T("DBfile");


// RacesTrainingDoc

IMPLEMENT_DYNCREATE(RacesTrainingDoc, CDoc)

BEGIN_MESSAGE_MAP(RacesTrainingDoc, CDoc)
  ON_COMMAND(ID_LoadDatabase, &OnLoadDatabase)
  ON_COMMAND(ID_LoadCSVFile,  &onLoadTrainingCSVfile)
  ON_COMMAND(ID_CompareSets,  &onComparison)
  ON_COMMAND(ID_NonResponder, &onNonRspdrNeeded)
  ON_COMMAND(ID_LegacyNeeded, &onLegacyNeeded)
END_MESSAGE_MAP()


// RacesTrainingDoc construction/destruction

RacesTrainingDoc::RacesTrainingDoc() noexcept : dataSource(NotePadSrc) {

  pathDsc(_T("RACES Training "), _T(""), _T("csv"), _T("*.csv"));
  }

RacesTrainingDoc::~RacesTrainingDoc() { }


void RacesTrainingDoc::initialLoad() {if (iniFile.read(FileSection, DBFileKey, path)) load();}


void RacesTrainingDoc::OnLoadDatabase() {
PathDlgDsc dsc(_T("Database"), 0, _T("accdb"), _T("*.accdb"));

  notePad.clear();

  if (setOpenPath(dsc)) load();
  }


void RacesTrainingDoc::load() {

  if (!database.load(path)) return;

  iniFile.write(FileSection, DBFileKey, path);   dbPath = path;   display(NotePadSrc);
  }


void RacesTrainingDoc::onLoadTrainingCSVfile() {

  notePad.clear(); dataSource = CSVSrc;

  pathDsc(_T("RACES Training "), pathDsc.name, _T("csv"), _T("*.csv"));

  if (!setOpenPath(pathDsc)) return;

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


