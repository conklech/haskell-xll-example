{-# LANGUAGE ForeignFunctionInterface #-}
module Adder where

import Foreign.C

adder :: CInt -> CInt -> CInt  
adder x y = x+y

foreign export stdcall adder :: CInt -> CInt -> CInt
