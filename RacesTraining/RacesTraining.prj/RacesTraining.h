// RacesTraining.h : main header file for the RacesTraining application

#pragma once
#include "CApp.h"


class RacesTrainingDoc;
class RacesTrainingView;


// RacesTraining:
// See RacesTraining.cpp for the implementation of this class

class RacesTraining : public CApp {
public:

               RacesTraining() noexcept : CApp(this) { }

  virtual BOOL InitInstance();

          RacesTrainingDoc*  doc()  {return (RacesTrainingDoc*)  CApp::getDoc();}
          RacesTrainingView* view() {return (RacesTrainingView*) CApp::getView();}

  DECLARE_MESSAGE_MAP()

  afx_msg void OnAppAbout();
  afx_msg void OnHelp();
  };


extern RacesTraining theApp;

inline void         invalidate() {theApp.invalidate();}
inline RacesTrainingDoc*  doc()  {return theApp.doc();}
inline RacesTrainingView* view() {return theApp.view();}

