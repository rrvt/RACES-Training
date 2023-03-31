// RacesTrainingDoc.h : interface of the RacesTrainingDoc class


#pragma once
#include "CDoc.h"
#include "TrainingRcds.h"


enum DataSource {NotePadSrc, CSVSrc, MbrSrc};


class RacesTrainingDoc : public CDoc {

PathDlgDsc  pathDsc;
String      dbPath;

DataSource  dataSource;

protected: // create from serialization only

  RacesTrainingDoc() noexcept;
  DECLARE_DYNCREATE(RacesTrainingDoc)

public:

  DataSource dataSrc() {return dataSource;}

  void       displayCSV();
  void       display(DataSource ds);

  void       initialLoad();

  virtual void serialize(Archive& ar);

  virtual ~RacesTrainingDoc();

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

private:

  void load();

protected:
  DECLARE_MESSAGE_MAP()

public:
  afx_msg void OnLoadDatabase();
  afx_msg void onLoadTrainingCSVfile();
  afx_msg void OnInfoByName();
  afx_msg void OnInfoByFCC();
  afx_msg void onComparison();
  afx_msg void onLegacyNeeded();
  afx_msg void onNonRspdrNeeded();
  };
