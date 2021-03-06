

RacesTraining.chm : *.htm RacesTraining.hhp RacesTraining.hhc App.css
  -1 "C:\Program Files (x86)\HTML Help Workshop\hhc" RacesTraining


Clean.cln    :
  @echo "Cleaning"
  cd $(MAKEDIR)
  del /F RacesTraining.chm


Release/RacesTraining.chm : RacesTraining.chm
  copy $(MAKEDIR)\RacesTraining.chm  $(MAKEDIR)\..\Release\RacesTraining.chm


Release/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\Release
  del RacesTraining.chm
  cd $(MAKEDIR)


Debug/RacesTraining.chm : RacesTraining.chm
  copy $(MAKEDIR)\RacesTraining.chm  $(MAKEDIR)\..\Debug\RacesTraining.chm


Debug/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\Debug
  del RacesTraining.chm
  cd $(MAKEDIR)


Release/Rebuild.rbd : Release/Clean.cln Release/RacesTraining.chm


Debug/Rebuild.rbd   : Debug/Clean.cln Debug/RacesTraining.chm


