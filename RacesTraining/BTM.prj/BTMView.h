// BTMView.h : interface of the BTMView class


#pragma once
#include "CScrView.h"
#include "NotePadRpt.h"


class BTMDoc;


class BTMView : public CScrView {
protected:

  BTMView() noexcept;

  DECLARE_DYNCREATE(BTMView)

public:

  virtual ~BTMView() { }

  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

  virtual void onBeginPrinting();
  virtual void onDisplayOutput();

  virtual void printFooter(DevBase& dev, int pageNo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

  BTMDoc* GetDocument() const;

public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:

  DECLARE_MESSAGE_MAP()

  afx_msg void onOptions();
  afx_msg void OnSetFocus(CWnd* pOldWnd);
  };


#ifndef _DEBUG  // debug version in BTMView.cpp
inline BTMDoc* BTMView::GetDocument() const { return reinterpret_cast<BTMDoc*>(m_pDocument); }
#endif

