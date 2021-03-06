# RACES Training

 Used to Compare the San Radio Amateur Civil Emergency Service (SJ RACES) Training Spreadsheet and
 Database.

## Getting Started

The application requires two elements that will be difficult to get, the San Jose Radio Amateur Civil
Emergency Service (SJ RACES) database and the Google Trraing Spreadsheet.  If you have both of those then
the first three toolbar commands in left to right order.  Check the help file for details.

The RACES Training application is composed of four projects and compiled with Visual Studio 2017.
The four projects are:
  - RacesTraining -- Solution File is in the ...\RWracesDB\RWracesDB\ folder.  It references the other two
    projects (Library and Installer)
  - Library -- This project produces a static library of which some object files are loaded into
    the executable and the msi (installer file)
  - BTM -- Build Training Module, an application that constructs the TrainingRcd module by analysing the
    Training CSV file.
  - Installer -- A Wix Toolset Installer.  The installer was constructed with WixApp.

### Prerequisites

Of course this all depends on having the SJ RACES database and a CSV file from the training spreadsheet.

Building the application depends on Visual Studio 2017 or later and the ability to
debug if things don't go right.  The Extension "Wix Toolset visual Studio 2017 Extension" is also
required.  It can be found in "Tools/Extensions and Updates".  The help file is produced with
HTML Help Workshop (HHW), Version 4.74.8702.0.

A version of the Data Access Object dynamic library must be on your system.  The library module,
AceDao.h, contains the following lines (which you may have to change):
```
#import <C:\Program Files (x86)\Microsoft Office\root\Office16\ACEDAO.DLL> rename(_T("EOF"), _T("DaoEof"))
using namespace DAO;
```
Here is an explanation of DAO:
```
  https://en.wikipedia.org/wiki/Data_access_object
```

All the code is contained in the two directories, RacesTraining and Library.

### Installing

Execute the msi file to install the application.  BTM is not installed, just use it from the Release
directory.


## Built With

Slickedit is used for all edits, Visual Studio 2017 with various additions (Wix being one) is used to
build and debug.  The old fashion Help Workshop is used to compile the help file and an old copy of
Dreamweaver is used to construct the html files used in the Help Workshop.

My current operating system is Windows 7 and I have little interest in moving to Windows 10 until it
appears to be stable.  In April 2020 it does not appear stable.

This version was created with Visual Studion 2017.  It was compiled with the following properties:
  o Windows SDK Version: 10.0.18362.0
  o Platfor Toolset: visual Studio 2017 (v141)
  o MFC: Use MFC in a Shared DLL
  o Character Set:  Use Unicode Character Set
  o Additional Include Directories:
    * $(ProjectDir)
    * $(SolutionDir)..\..\Library\Library.prj\
    * $(SolutionDir)..\Common\
    * $(SolutionDir)..\..\Library\Extras\
  o  Precompiled Header:  Not Using Precompiled Headers
  o  Linker/Additional Dependencies:  Htmlhelp.lib

The HTML Help Workshop (HHW), Version 4.74.8702.0 was used to prepare the help file.  It is
copied into the Release directory.  I used Dreamweaver (DW) to do most of the content production of the
help files that the HTML Help Workshop produces (i.e. HHW is used to produce the pages/files needed
and DW is used to fill in the content).

The WiX Toolset must be installed in Visual Studio.

WixApp was used to create the installer Product file.

## Updates

### Update 5/21/21

Added a clear function to all database so that load may be performed multiple time with different
databases.

### 4/19/21

The Library has changed.  Also some logic was added so that the printer orientation may be set both in
the options dialog and the printer setup.

### Update 3/6/21

Added two additional features:
  o Display bar graph depicting the training needed for Legacy Responders
  o Display bar graph depicting the training needed for Non-Responders

## Authors

Robert R. Van Tuyl

Contact:  romeo romeo victor tango alpha tango sam whisky delta echo dot charlie oscar mike

## License

 This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


