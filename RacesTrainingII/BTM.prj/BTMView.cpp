// BTMView.cpp : implementation of the BTMView class


#include "stdafx.h"
#include "BTMView.h"
#include "BTM.h"
#include "BTMDoc.h"
#include "Options.h"
#include "Resources.h"


// BTMView

IMPLEMENT_DYNCREATE(BTMView, CScrView)

BEGIN_MESSAGE_MAP(BTMView, CScrView)
END_MESSAGE_MAP()


BTMView::BTMView() noexcept : dspNote( dMgr.getNotePad()), prtNote( pMgr.getNotePad()) {
ResourceData res;
String       pn;
  if (res.getProductName(pn)) prtNote.setTitle(pn);
  }


BOOL BTMView::PreCreateWindow(CREATESTRUCT& cs) {

  return CScrView::PreCreateWindow(cs);
  }


void BTMView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) {
uint   x;
double topMgn   = options.topMargin.stod(x);
double leftMgn  = options.leftMargin.stod(x);
double rightMgn = options.rightMargin.stod(x);
double botMgn   = options.botMargin.stod(x);

  setMgns(leftMgn,  topMgn,  rightMgn, botMgn, pDC);   CScrView::OnPrepareDC(pDC, pInfo);
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void BTMView::onPrepareOutput(bool printing) {
DataSource ds = doc()->dataSrc();

  if (printing)
    switch(ds) {
      case CSVSrc     :
      case CodeSrc    :
      case NotePadSrc : prtNote.print(*this);  break;
      }

  else
    switch(ds) {
      case CSVSrc     :
      case CodeSrc    :
      case NotePadSrc : dspNote.display(*this);  break;
      }

  CScrView::onPrepareOutput(printing);
  }


void BTMView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) {

  switch(doc()->dataSrc()) {
    case NotePadSrc : setOrientation(options.orient); break;    // Setup separate Orientation?
    case CodeSrc    :
    case CSVSrc     : setOrientation(options.orient); break;
    }
  setPrntrOrient(theApp.getDevMode(), pDC);   CScrView::OnBeginPrinting(pDC, pInfo);
  }


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should not
// be a great hardship to construct a footer.

void BTMView::printFooter(Device& dev, int pageNo) {
  switch(doc()->dataSrc()) {
    case NotePadSrc : prtNote.footer(dev, pageNo);  break;
    }
  }



void BTMView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) {

  CScrView::OnEndPrinting(pDC, pInfo);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    case CSVSrc     : break;
    }
  }


void BTMView::OnSetFocus(CWnd* pOldWnd) {

  CScrView::OnSetFocus(pOldWnd);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    case CSVSrc   : break;
    }
  }


// BTMView diagnostics

#ifdef _DEBUG

void BTMView::AssertValid() const {CScrollView::AssertValid();}

void BTMView::Dump(CDumpContext& dc) const {CScrollView::Dump(dc);}
                                             // non-debug version is inline
BTMDoc* BTMView::GetDocument() const
  {ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(BTMDoc))); return (BTMDoc*)m_pDocument;}

#endif //_DEBUG
