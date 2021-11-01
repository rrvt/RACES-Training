// RacesTraining.cpp : Defines the class behaviors for the application.


#include "stdafx.h"
#include "RacesTraining.h"
#include "AboutDlg.h"
#include "DBtables.h"
#include "IniFile.h"
#include "MainFrame.h"
#include "NotePad.h"
#include "Options.h"
#include "RacesTrainingDoc.h"
#include "RacesTrainingView.h"


RacesTraining theApp;                       // The one and only RacesTraining object
IniFile iniFile;


// RacesTraining

BEGIN_MESSAGE_MAP(RacesTraining, CWinAppEx)
  ON_COMMAND(ID_APP_ABOUT,        &OnAppAbout)
  ON_COMMAND(ID_FILE_PRINT_SETUP, &OnFilePrintSetup)
  ON_COMMAND(ID_Help,             &OnHelp)
END_MESSAGE_MAP()


// RacesTraining initialization

BOOL RacesTraining::InitInstance() {

  CWinAppEx::InitInstance();

  iniFile.setAppDataPath(m_pszHelpFilePath, *this);

  notePad.clear();

  SetRegistryKey(appID);

  LoadStdProfileSettings(0);  // Load standard INI file options (including MRU)

  // Register the application's document templates.  Document templates
  // serve as the connection between documents, frame windows and views

  CSingleDocTemplate* pDocTemplate;

  pDocTemplate = new CSingleDocTemplate(
    IDR_MAINFRAME,
    RUNTIME_CLASS(RacesTrainingDoc),
    RUNTIME_CLASS(MainFrame),       // main SDI frame window
    RUNTIME_CLASS(RacesTrainingView));

  if (!pDocTemplate) return FALSE;

  AddDocTemplate(pDocTemplate);

  // Parse command line for standard shell commands, DDE, file open

  CCommandLineInfo cmdInfo;   ParseCommandLine(cmdInfo);

  // Dispatch commands specified on the command line.  Will return FALSE if
  // app was launched with /RegServer, /Register, /Unregserver or /Unregister.

  if (!ProcessShellCommand(cmdInfo)) return FALSE;

  setAppName(_T("RACES Training ")); setTitle(_T("RACES Training"));

  view()->setFont(_T("Courier New"), 12.0);

  iniFile.readString(FileSection, DBFileKey, databasePath);
  dbTables.load(databasePath);

  options.load();    view()->setOrientation(options.orient);

  m_pMainWnd->ShowWindow(SW_SHOW);   m_pMainWnd->UpdateWindow();   return TRUE;
  }



void RacesTraining::OnFilePrintSetup() {
PrtrOrient orient;

  view()->setPrntrOrient(getDevMode());

    CWinApp::OnFilePrintSetup();

  orient = view()->getPrntrOrient(getDevMode());

  options.setOrient(orient);   view()->setOrientation(options.orient);
  }



void RacesTraining::OnHelp() {
String topic = m_pszHelpFilePath; topic += _T(">Introduction");

  ::HtmlHelp(m_pMainWnd->m_hWnd, topic,  HH_DISPLAY_TOC, 0);
  }


void RacesTraining::OnAppAbout() {AboutDlg aboutDlg; aboutDlg.DoModal();}

