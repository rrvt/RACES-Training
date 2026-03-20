# RACES Training

 Used to Compare the San Radio Amateur Civil Emergency Service (SJ RACES) Training Spreadsheet and
 Database.

## Getting Started

The application is built with Visual Studio 2022 (VS22).  It was compiled with the following
properties:

  o Windows Latest SDK Version
  o Platform Toolset: visual Studio 2022
  o MFC: Use MFC in a Shared DLL
  o Character Set:  Use Unicode Character Set
  o Built for the 64 bit (x64) platform because ODBC is now only available in the x64 platform
  o Additional Include Directories:
    * $(ProjectDir)
    * $(SolutionDir)..\..\Library\Library.prj\
    * $(SolutionDir)..\..\Library\DocView\
  o  Precompiled Header:  Not Using Precompiled Headers
  o  Linker/Additional Dependencies:  Htmlhelp.lib

The HTML Help Workshop (HHW), Version 4.74.8702.0 was used to prepare the help file (WixApp.chm).  It is
copied into the Release directory.  I used Dreamweaver (DW) to do most of the content production of the
help files that the HTML Help Workshop produces (i.e. HHW is used to produce the pages/files needed
and DW is used to fill in the content).

The Installer requires the Wix, HeatWave and NuGet-Tools Extensions to VS22.  WixApp (one of my
applications, see git) was used to produce the product.wxs file.

### Prerequisites

The WiX, HeatWave, NuGet-Tools Toolsets must be installed in Visual Studio.
The "HTML Help Workshop" (google it) must be installed.  Visual Studio 2022 or later.

### Installing

Execute the msi file to install the application.  BTM is not installed, just use it from the Release
directory.

## Updates

### Update 3/20/26

Normalize MyToolbar.

### Update 2/15/26

Build for the 64 bit platform.  Upgraded Wix to HeatWave version 4.
Prior to this version a Win32 platform was used since the 2010 Access Runtime supported both 32 bit
and 64 bit drivers.  But try as I did, I could not get the 2010 32 bit Access Runtime to install on
my laptop.  The solution was to build for the 64 bit platform and load the 2016 Access Runtime
(64 bit).

### Update 10/21/25

Factored library into three parts, Library, Dialog, DocView.

### Update 9/19/25

Changes to accomodate changes to ExpandableP.

### Update 7/8/25

Update Database objects to suppress memory leak reporting.  Factored IniFile into three classes.

### Update 12/26/24

Split the library into DocLib and Library where DocLib supports the MFC Document/Library App
projects and Library has support classes and supports the Dialog Apps with only one class.

### Update 8/7/24

Library update.

### Update 6/29/24

Add MIT License to installation.

### Update 6/14/24

Fix WinPos.

### Update 2/18/24

Reorganized the Library so that it compiles once into Debug and Release directories under the Library
directory.

### Update 1/8/24

Library and other changes.

### Update 12/25/23

Modify ExpandableP and subsequent ripple.

### Update 3/30/23

Library updates and corresponding application updates.

### Update 10/24/22

Add logic to keep track of the position and size of the window.  Other issues.

### Update 8/4/22

Rewrite of MS Access interface and other library updates.

### Update 01/31/22

Updates to the library, mostly about the toolbar, but also NewAllocator, and a minor addition to
Expandable.

Also scrubbed the project files to remove all references to precompiled header files which I turned off
in VS17.  Unfortnately VS does not remove all references and pch files kept cropping up.  Not only does
that slow down the compiler but the files are large...

### Update 12/18/21

While creating a template for a dialog box only application with a toolbar the Library was added to and
changed to hopefully simplify toolbar creation.  This version of the toolbar includes buttons, edit boxes,
combo boxes and drop down menus as well as the traditional 16x15 icons.

RacesTraining is a tradional App, has a traditional 16x15 pixel icon toolbar.

### Update 11/13/21

But the major changes are in the library:

  - Expandable and ExpandableP -- moved the functions out of the class to make the compilation smaller,
also fixed one bug (or feature) in the ExpandableP insert sorted function that would throw out entries
that were already in in the array.
  - FileIO -- Changed the type of path from "String&" to "TCchar*".  It turns out that automatic
conversion from String to TCchar* is easy, but the reverse is is not easy.  Also added a function to
get the length of a file given a path.
  - FineName -- Added a function to get the directory name of from a path
  - NewAllocator -- Corrected the debug dependency from if to ifdef
  - ToolBar -- Added data for drop down menus

### Update 10/31/21

Changed Resources (i.e. xxx.rc data) access so that it will work with a dll.  Changed the logic in the
About Box code.  Some other library changes.  Some corresponding changes in the application.

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


