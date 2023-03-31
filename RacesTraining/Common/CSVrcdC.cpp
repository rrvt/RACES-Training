// CSV records, one record per line


#include "pch.h"
#include "CSVrcdC.h"


void CSVrcdC::copy(CSVrcdC& r) {
CSVrcdIter iter(r);
CSVfld*    fld;

  for (fld = iter(); fld; fld = iter++) {
    CSVfld& newFld = fields.nextData();   newFld = *fld;
    }
  }

