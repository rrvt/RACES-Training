// CSV Records -- Used to load file, then the records are transferred to the Training Records data
// structure.


#include "stdafx.h"
#include "CSVrcds.h"
#include "NotePad.h"


CSVrcds csvRcds;


void CSVrcds::display() {
CSVIter iter(csvRcds);
CSVrcd* rcd;

  for (rcd = iter(); rcd; rcd = iter++) {
    rcd->display(notePad);
    }
  }

