// RacesTrainingView.h : interface of the RacesTrainingView class


#pragma once
#include "CScrView.h"
#include "NotePadRpt.h"


class RacesTrainingDoc;


class RacesTrainingView : public CScrView {

NotePadRpt dspNote;
NotePadRpt prtNote;

protected: // create from serialization only

  RacesTrainingView() noexcept : dspNote(dMgr.getNotePad()), prtNote(pMgr.getNotePad()) { }
  DECLARE_DYNCREATE(RacesTrainingView)

public:

  virtual ~RacesTrainingView() { }

//  void dsplyReport(bool start = true) {displayReport = start;}

  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
  virtual void onPrepareOutput(bool printing);

  virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void printFooter(Device& dev, int pageNo);

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
  };


#ifndef _DEBUG  // debug version in RacesTrainingView.cpp
inline RacesTrainingDoc* RacesTrainingView::GetDocument() const
   { return reinterpret_cast<RacesTrainingDoc*>(m_pDocument); }
#endif

