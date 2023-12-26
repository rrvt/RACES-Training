// Labels in the Excel Spreadsheet Data, multiple rows of it


#pragma once
#include "ExpandableP.h"
#include "IterT.h"




class Label {
public:

int    col;
String name[6];

  Label() { }
  Label(Label& lbl) {copy(lbl);}
 ~Label() { }

  Label& operator= (Label& lbl) {copy(lbl); return *this;}

  void   display();

  virtual bool     operator== (Label& lbl) {return col == lbl.col;}
  virtual bool     operator!= (Label& lbl) {return col != lbl.col;}
  virtual bool     operator>  (Label& lbl) {return col >  lbl.col;}
  virtual bool     operator<  (Label& lbl) {return col <  lbl.col;}
  virtual bool     operator>= (Label& lbl) {return col >  lbl.col;}
  virtual bool     operator<= (Label& lbl) {return col <  lbl.col;}

private:

  void copy(Label& lbl);
  };



class Labels;
typedef DatumPtrT<Label, int> LabelP;
typedef IterT<Labels, Label>  LblIter;


class Labels {

String                         three;
String                         four;

ExpandableP<Label, int, LabelP, 16> data;

public:

  Labels() { }
 ~Labels() { }

  void acquire();

  void   setFour(int col);
  String fourFive(int col);

  String find(int row, int col);
  Label* find(int col);

  void display();

private:
  void   maxLng(String& s, int& max);
  String lastWord(String& t);

  Label* allocate() {return data.allocate();}

  // returns either a pointer to data (or datum) at index i in array or zero

  Label* datum(int i) {return 0 <= i && i < nData() ? data[i].p : 0;}

  int    nData()      {return data.end();}

  void   removeDatum(int i) {if (0 <= i && i < nData()) data.del(i);}

  friend typename LblIter;
  };


extern Labels labels;



