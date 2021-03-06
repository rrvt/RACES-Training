// BTMView.h : interface of the BTMView class


#pragma once
#include "CScrView.h"
#include "NotePadRpt.h"


class BTMDoc;


class BTMView : public CScrView {

NotePadRpt dspNote;
NotePadRpt prtNote;

protected: // create from serialization only

  BTMView() noexcept;

  DECLARE_DYNCREATE(BTMView)

public:

  virtual ~BTMView() { }

  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
  virtual void onPrepareOutput(bool printing);

  virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void printFooter(Device& dev, int pageNo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

  BTMDoc* GetDocument() const;

public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:

  DECLARE_MESSAGE_MAP()

  afx_msg void OnSetFocus(CWnd* pOldWnd);
  };


#ifndef _DEBUG  // debug version in BTMView.cpp
inline BTMDoc* BTMView::GetDocument() const
   { return reinterpret_cast<BTMDoc*>(m_pDocument); }
#endif

