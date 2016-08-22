#include <FileConstants.au3>


Global $exitStatus = False


;Global $fileTypeSectionName = "FILE_TYPES"

;Global $fileTypes [2][2] = 	[["CPP", "*.cpp"] ,["HPP", "*.h"]]


;Global $regExpSectionName = "REG_EXP"

Global Enum $HEADER_FUNCTIONS      = 0 , _
			$HEADER_PARAMETER      = 1 , _
			$NUMBER_OF_REG_EXP     = 2


Global $regExp[$NUMBER_OF_REG_EXP] = [										 	      _
										'(\w+\s*\**)\s+(\w+)\(([\w+|\,|\s+]+)\)\;'  , _
										'(\w+\s*\**)\s+(\w+)'                         _
									 ]





Global $path = @ScriptDir & "\TestFile"
Global $recurSearch = $FLTAR_RECUR
Global $retPath = $FLTAR_FULLPATH
Global $filter = "*.h"