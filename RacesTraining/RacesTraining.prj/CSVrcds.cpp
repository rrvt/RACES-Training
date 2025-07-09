// CSV Records -- Used to load file, then the records are transferred to the Training Records data
// structure.


#include "pch.h"
#include "CSVrcds.h"
#include "NotePad.h"


void CSVrcds::display() {
CSVIter iter(csvRcds);
CSVrcd* rcd;

  for (rcd = iter(); rcd; rcd = iter++) {
    rcd->display(notePad);
    }
  }

