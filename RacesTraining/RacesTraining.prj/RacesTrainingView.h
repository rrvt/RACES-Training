// RacesTrainingView.h : interface of the RacesTrainingView class


#pragma once
#include "CScrView.h"
#include "ReportNtPd.h"


class RacesTrainingDoc;


class RacesTrainingView : public CScrView {
protected:

  RacesTrainingView() noexcept { }
  DECLARE_DYNCREATE(RacesTrainingView)

public:

  virtual ~RacesTrainingView() { }

  virtual void       initNoteOrietn() { }
  virtual void       saveNoteOrietn() { }
  virtual void       initRptOrietn()  { }
  virtual void       saveRptOrietn()  { }
  virtual PrtrOrient getOrientation() {return prtNote.prtrOrietn;}

  virtual void onDisplayOutput();

  virtual void onPreparePrinting(CPrintInfo* info) {prtNote.onPreparePrinting(info);}
  virtual void onBeginPrinting();
  virtual void printFooter(DevStream& dev, int pageNo);

  RacesTrainingDoc* GetDocument() const;

public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

protected:

//  DECLARE_MESSAGE_MAP()
public:

  DECLARE_MESSAGE_MAP()

  afx_msg void onOptions();
  afx_msg void onRptOrietn();
  };


#ifndef _DEBUG  // debug version in RacesTrainingView.cpp
inline RacesTrainingDoc* RacesTrainingView::GetDocument() const
                                       { return reinterpret_cast<RacesTrainingDoc*>(m_pDocument); }
#endif

