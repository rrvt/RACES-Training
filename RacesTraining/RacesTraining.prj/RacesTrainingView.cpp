// RacesTrainingView.cpp : implementation of the RacesTrainingView class


#include "pch.h"
#include "RacesTrainingView.h"
#include "OptionsDlg.h"
#include "RacesTraining.h"
#include "RacesTrainingDoc.h"
#include "Resource.h"
#include "RptOrientDlgOne.h"


// RacesTrainingView

IMPLEMENT_DYNCREATE(RacesTrainingView, CScrView)

BEGIN_MESSAGE_MAP(RacesTrainingView, CScrView)
  ON_COMMAND(ID_Options,     &onOptions)
  ON_COMMAND(ID_Orientation, &onRptOrietn)
END_MESSAGE_MAP()




void RacesTrainingView::onOptions() {
OptionsDlg dlg;

  if (printer.name.isEmpty()) printer.load(0);

  if (dlg.DoModal() == IDOK) pMgr.setFontScale(printer.scale);
  }


void RacesTrainingView::onRptOrietn() {
RptOrietnDlg dlg;

  dlg.lbl00 = _T("Training:");

  dlg.ntpd = printer.toStg(prtNote.prtrOrietn);

  if (dlg.DoModal() == IDOK) {prtNote.prtrOrietn = printer.toOrient(dlg.ntpd);   saveNoteOrietn();}
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void RacesTrainingView::onBeginPrinting() {prtNote.onBeginPrinting(*this);}


void RacesTrainingView::onDisplayOutput() {dspNote.display(*this);}


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should not
// be a great hardship to construct a footer.

void RacesTrainingView::printFooter(DevBase& dev, int pageNo) {
//  report.footer(dev, pageNo);
  }




// RacesTrainingView diagnostics

#ifdef _DEBUG

void RacesTrainingView::AssertValid() const {CScrollView::AssertValid();}

void RacesTrainingView::Dump(CDumpContext& dc) const {CScrollView::Dump(dc);}
                                             // non-debug version is inline
RacesTrainingDoc* RacesTrainingView::GetDocument() const
  {ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(RacesTrainingDoc))); return (RacesTrainingDoc*)m_pDocument;}

#endif //_DEBUG
