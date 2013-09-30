haskell-xll-example
===================

Example of a simple Excel 2007 XLL using Haskell. I had a heck of a time getting all the pieces to fit together.

Run build.bat; it should make Adder.xll. If you open that file with Excel, you should get a new worksheet function, ADDER(), that takes two numbers and returns their sum.

You'll need the Excel 2007 XLL SDK extracted in ..\Excel2007XLLSDK (relative to StartStop.c).
It should be available at http://www.microsoft.com/downloads/details.aspx?FamilyId=5272E1D1-93AB-4BD4-AF18-CB6BB487E1C4&displaylang=en
(It's just a nested executable zip file; you should be able to open it with an archive tool.)
