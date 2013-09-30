ghc -c Adder.hs
set C_INCLUDE_PATH=..\Excel2007XLLSDK\include
ghc -c -optc-D__forceinline=inline StartEnd.c
ghc -shared -o Adder.xll Adder.o StartEnd.o Adder.def