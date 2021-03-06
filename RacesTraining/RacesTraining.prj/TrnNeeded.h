// Training Needed


#pragma once


enum {NoTrnElements = 16};
class TrainingRcd;



class TrnNeeded {

int max;
int count;

int data[NoTrnElements];

public:

  TrnNeeded() {clear();}
 ~TrnNeeded() { }

  void clear() {max = count = 0; for (int i = 0; i < noElements(data); i++) data[i] = 0;}

  void addNeeded(TrainingRcd* rcd);

  void display(TCchar* title);

private:

  void inc(String& s, int& i);

  void setMax() {int i; for (i = 0, max = 0; i < noElements(data); i++) if (data[i] > max) max = data[i];}
  void dspBar(int n);
  };


extern TrnNeeded legacy;
extern TrnNeeded nonRspdrs;
