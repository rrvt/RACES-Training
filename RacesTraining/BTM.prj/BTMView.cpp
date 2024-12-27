// BTMView.cpp : implementation of the BTMView class


#include "pch.h"
#include "BTMView.h"
#include "BTM.h"
#include "BTMDoc.h"
#include "OptionsDlg.h"
#include "Resource.h"
#include "ResourceData.h"


// BTMView

IMPLEMENT_DYNCREATE(BTMView, CScrView)

BEGIN_MESSAGE_MAP(BTMView, CScrView)
  ON_COMMAND(ID_Options, &onOptions)
END_MESSAGE_MAP()


BTMView::BTMView() noexcept {
ResourceData res;
String       pn;
  if (res.getProductName(pn)) prtNote.setTitle(pn);
  }


BOOL BTMView::PreCreateWindow(CREATESTRUCT& cs) {

  return CScrView::PreCreateWindow(cs);
  }


void BTMView::onOptions() {
OptionsDlg dlg;

  if (printer.name.isEmpty()) printer.load(0);

  if (dlg.DoModal() == IDOK) pMgr.setFontScale(printer.scale);
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void BTMView::onBeginPrinting() {prtNote.onBeginPrinting(*this);}


void BTMView::onDisplayOutput() {dspNote.display(*this);}


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should
// not be a great hardship to construct a footer.

void BTMView::printFooter(DevStream& dev, int pageNo) {
  switch(doc()->dataSrc()) {
    case NotePadSrc : prtNote.prtFooter(dev, pageNo);  break;
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
void BTMView::AssertValid() const          {CScrollView::AssertValid();}
void BTMView::Dump(CDumpContext& dc) const {CScrollView::Dump(dc);} // non-debug version is inline
BTMDoc* BTMView::GetDocument() const
               {ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(BTMDoc))); return (BTMDoc*)m_pDocument;}
#endif //_DEBUG
