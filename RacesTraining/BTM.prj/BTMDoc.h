// BTMDoc.h : interface of the BTMDoc class


#pragma once
#include "CDoc.h"
#include "MainFrame.h"


enum DataSource {NotePadSrc, CSVSrc, CodeSrc};


class BTMDoc : public CDoc {

PathDlgDsc  pathDlgDsc;

DataSource  dataSource;

protected: // create from serialization only

  BTMDoc() noexcept;
  DECLARE_DYNCREATE(BTMDoc)

public:

  virtual BOOL OnNewDocument();
  virtual ~BTMDoc();

  DataSource dataSrc() {return dataSource;}
  void       display(DataSource ds);

  virtual void serialize(Archive& ar);

// Implementation
public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

private:

  void testLine(int n);
  void wholePage();

// Generated message map functions

protected:

  DECLARE_MESSAGE_MAP()

public:

  afx_msg void onLoadTrainingCSVfile();
  afx_msg void OnFileSave();

  afx_msg void OnPrepTrng_h();
  afx_msg void OnPrepTrng_cpp();
  };





