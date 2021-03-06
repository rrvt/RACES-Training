// BTMDoc.cpp : implementation of the BTMDoc class


#include "stdafx.h"
#include "BTMDoc.h"
#include "BTM.h"
#include "BTMbldr.h"
#include "BTMrcds.h"
#include "BTMView.h"
#include "ExtraResource.h"
#include "filename.h"
#include "GetPathDlg.h"
#include "Labels.h"
#include "MessageBox.h"
#include "NotePad.h"
#include "Options.h"
#include "Resource.h"
#include "ToolBar.h"


// BTMDoc

IMPLEMENT_DYNCREATE(BTMDoc, CDoc)

BEGIN_MESSAGE_MAP(BTMDoc, CDoc)
  ON_COMMAND(ID_File_Open,     &onLoadTrainingCSVfile)
  ON_COMMAND(ID_PrepAddr_h,    &OnPrepTrng_h)
  ON_COMMAND(ID_PrepAddr_cpp,  &OnPrepTrng_cpp)
  ON_COMMAND(ID_File_Save,     &OnFileSave)
  ON_COMMAND(ID_Options,       &OnOptions)
END_MESSAGE_MAP()


// BTMDoc construction/destruction

BTMDoc::BTMDoc() noexcept : dataSource(NotePadSrc) {
  pathDlgDsc = PathDlgDsc(_T("Ugly Example"), _T(""), _T("txt"), _T("*.txt"));
  }

BTMDoc::~BTMDoc() { }


BOOL BTMDoc::OnNewDocument() {return CDocument::OnNewDocument();}



void BTMDoc::OnOptions() {options(view());  view()->setOrientation(options.orient);}


void BTMDoc::onLoadTrainingCSVfile() {

  notePad.clear();   dataSource = CSVSrc;

  pathDlgDsc = PathDlgDsc(_T("Training CSV File"), _T(""), _T("csv"), _T("*.csv"));

  if (!setPath(pathDlgDsc)) return;

  pathDlgDsc.name = getMainName(path);

  if (!OnOpenDocument(path)) messageBox(_T(" Not Loaded!"));

  labels.acquire();

  labels.display();   notePad << nCrlf << nCrlf;

  btmBldr.prepareFieldNames(*btmRcds.datum(5));

  btmBldr.display();

  display(CSVSrc);
  }



void BTMDoc::OnPrepTrng_h() {
  pathDlgDsc = PathDlgDsc(_T("Save TrainingRcd.h"), _T("TrainingRcd.h"), _T("h"), _T("*.h"));

  btmBldr.OnPrepTrng_h();  display(CodeSrc);
  }


void BTMDoc::OnPrepTrng_cpp() {
  pathDlgDsc = PathDlgDsc(_T("Save TrainingRcd.cpp"), _T("TrainingRcd.cpp"), _T("cpp"), _T("*.cpp"));

  btmBldr.OnPrepTrng_cpp(); display(CodeSrc);
  }


void BTMDoc::display(DataSource ds) {dataSource = ds; invalidate();}


void BTMDoc::OnFileSave() {if (setSaveAsPath(pathDlgDsc)) OnSaveDocument(path);}


// UglyDoc serialization

void BTMDoc::serialize(Archive& ar) {

  if (ar.isStoring())
    switch(dataSource) {
      case CodeSrc    :
      case NotePadSrc : notePad.archive(ar); return;
      default         : return;
      }

  else
    switch(dataSource) {
      case CSVSrc : btmRcds.load(ar); return;
      default     : return;
      }
  }


// BTMDoc diagnostics

#ifdef _DEBUG
void BTMDoc::AssertValid() const
{
  CDocument::AssertValid();
}

void BTMDoc::Dump(CDumpContext& dc) const
{
  CDocument::Dump(dc);
}
#endif //_DEBUG


