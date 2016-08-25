#include <FileConstants.au3>



Global Const $NUMBER_OF_REG_EXP     	 = 2
Global Const $NUMBER_OF_PROJECT_TYPES	 = 2


;------------------------------------------------------
;	Type to define which regular expressions are available
;------------------------------------------------------
Global Enum $C_HEADER_FUNCTIONS      = 10 , _
			$C_HEADER_PARAMETER      = 11


;------------------------------------------------------
;	Type to define who a file will be returned
;------------------------------------------------------
Global Enum $RETURN_AS_ARRAY	   = 0 , _
			$RETURN_AS_STRING	   = 1


;------------------------------------------------------
;	Type to define which Files can be commented
;------------------------------------------------------
Global Enum $C_PROJECT		   			= 1 , _			; Config Parameter for C - Projects
			$CPP_PROJECT			    = 2 			; Config Parameter for CPP - Projects


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

;=== CONFIGURATION PARAMETER ================================================================
Global $filterMask = "*.h"
Global $fileReturnType = $RETURN_AS_ARRAY
Global $projectType = $C_PROJECT
Global $filePath = @ScriptDir & "\TestFile"
