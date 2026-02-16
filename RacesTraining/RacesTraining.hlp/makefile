

RacesTraining.chm : *.htm RacesTraining.hhp RacesTraining.hhc App.css
  -1 "C:\Program Files (x86)\HTML Help Workshop\hhc" RacesTraining


Clean.cln    :
  @echo "Cleaning"
  cd $(MAKEDIR)
  if exist RacesTraining.chm del /F RacesTraining.chm


$(TgtFolder)/RacesTraining.chm : RacesTraining.chm
  if not exist "$(MAKEDIR)\..\$(TgtFolder)" mkdir "$(MAKEDIR)\..\$(TgtFolder)"
  copy $(MAKEDIR)\RacesTraining.chm  $(MAKEDIR)\..\$(TgtFolder)\RacesTraining.chm


$(TgtFolder)/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\$(TgtFolder)
  if exist RacesTraining.chm del /F RacesTraining.chm
  cd $(MAKEDIR)


$(TgtFolder)/Rebuild.rbd : $(TgtFolder)/Clean.cln $(TgtFolder)/RacesTraining.chm


