#include <FileConstants.au3>


;------------------------------------------------------
;	Type to define which regular expressions are available
;------------------------------------------------------
Global Enum $HEADER_FUNCTIONS      = 0 , _
			$HEADER_PARAMETER      = 1 , _
			$NUMBER_OF_REG_EXP     = 2


;------------------------------------------------------
;	Type to define who a file will be returned
;------------------------------------------------------
Global Enum $RETURN_AS_ARRAY	   = 0 , _
			$RETURN_AS_STRING	   = 1


;------------------------------------------------------
;	Type to define which Files can be commented
;------------------------------------------------------
Global Enum $C_PROJECT		   			= 0 , _			; Config Parameter for C - Projects
			$CPP_PROJECT			    = 1 , _			; Config Parameter for C - Projects
			$NUMBER_OF_PROJECT_TYPES	= 2

Global $regExp[$NUMBER_OF_PROJECT_TYPES][$NUMBER_OF_REG_EXP] =	_
		[  													 _
															 _
			[												 _
				'(\w+\s*\**)\s+(\w+)\(([\w+|\,|\s+]+)\)\;' , _
				'(\w+\s*\**)\s+(\w+)'				 		 _
			],                        						 _
															 _
			[												 _
				'',											 _
				''											 _
			]												 _
		]





Global $path = @ScriptDir & "\TestFile"
Global $recurSearch = $FLTAR_RECUR
Global $retPath = $FLTAR_FULLPATH
Global $filter = "*.h"
Global $projectType = $C_PROJECT