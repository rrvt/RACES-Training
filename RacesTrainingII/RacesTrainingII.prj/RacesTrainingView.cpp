// RacesTrainingView.cpp : implementation of the RacesTrainingView class


#include "stdafx.h"
#include "RacesTrainingView.h"
#include "Options.h"
#include "RacesTraining.h"
#include "RacesTrainingDoc.h"


// RacesTrainingView

IMPLEMENT_DYNCREATE(RacesTrainingView, CScrView)

BEGIN_MESSAGE_MAP(RacesTrainingView, CScrView)
END_MESSAGE_MAP()




void RacesTrainingView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) {
uint   x;
double topMgn   = options.topMargin.stod(x);
double leftMgn  = options.leftMargin.stod(x);
double rightMgn = options.rightMargin.stod(x);
double botMgn   = options.botMargin.stod(x);

  setMgns(leftMgn,  topMgn,  rightMgn, botMgn, pDC);   CScrView::OnPrepareDC(pDC, pInfo);
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void RacesTrainingView::onPrepareOutput(bool printing) {
DataSource ds = doc()->dataSrc();

  if (printing)
    switch(ds) {
      case CSVSrc     :
      case MbrSrc     :
      case NotePadSrc : prtNote.print(*this);  break;
      default         : break;
      }

  else
    switch(ds) {
      case CSVSrc     :
      case MbrSrc     :
      case NotePadSrc : dspNote.display(*this);  break;
      default         : break;
      }

  CScrView::onPrepareOutput(printing);
  }




void RacesTrainingView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) {

  setPrntrOrient(theApp.getDevMode(), pDC);

  CScrView::OnBeginPrinting(pDC, pInfo);
  }


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should not
// be a great hardship to construct a footer.

void RacesTrainingView::printFooter(Device& dev, int pageNo) {
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
