// BTMView.h : interface of the BTMView class


#pragma once
#include "CScrView.h"
#include "ReportNtPd.h"


class BTMDoc;


class BTMView : public CScrView {
protected:

  BTMView() noexcept;

  DECLARE_DYNCREATE(BTMView)

public:

  virtual           ~BTMView() { }

  virtual void       initNoteOrietn() { }
  virtual void       saveNoteOrietn() { }
  virtual void       initRptOrietn()  { }
  virtual void       saveRptOrietn()  { }
  virtual PrtrOrient getOrientation() {return prtNote.prtrOrietn;}

  virtual BOOL       PreCreateWindow(CREATESTRUCT& cs);

  virtual void       onDisplayOutput();

  virtual void       onBeginPrinting();
  virtual void       printFooter(DevStream& dev, int pageNo);
  virtual void       OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

  BTMDoc*            GetDocument() const;

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

