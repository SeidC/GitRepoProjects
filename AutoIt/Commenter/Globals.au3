#include-once


Global $exitStatus = False


Global $fileTypeSectionName = "FILE_TYPES"

Global $fileTypes [2][2] = 	[["CPP", "*.cpp"] ,["HPP", "*.h"]]


Global $regExpSectionName = "REG_EXP"

Global $regExp[2][2] = [["REG_1","abc"],["REG_2","xyz"]]





Global $path = "Z:\Projekte\Projects\AVR\Test\"
Global $recurSearch = $FLTAR_RECUR
Global $retPath = $FLTAR_RELPATH
Global $filter = "*.cpp"