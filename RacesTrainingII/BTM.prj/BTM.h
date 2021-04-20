// BTM.h : main header file for the BTM application

#pragma once
#include "CApp.h"


class BTMDoc;
class BTMView;
class MainFrame;


// BTM:
// See BTM.cpp for the implementation of this class

class BTM : public CApp {

public:

               BTM() noexcept : CApp(this) { }

  virtual BOOL InitInstance();
  virtual int  ExitInstance();

          BTMDoc*  doc()  {return (BTMDoc*)  CApp::getDoc();}
          BTMView* view() {return (BTMView*) CApp::getView();}
          MainFrame*       mainFrm() {return (MainFrame*) m_pMainWnd;}

  DECLARE_MESSAGE_MAP()

  afx_msg void OnFilePrintSetup();
  afx_msg void OnAppAbout();
  afx_msg void OnHelp();
  };


extern BTM theApp;

inline void         invalidate() {theApp.invalidate();}
inline BTMDoc*  doc()  {return theApp.doc();}
inline BTMView* view() {return theApp.view();}

