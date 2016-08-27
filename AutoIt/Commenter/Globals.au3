#include <FileConstants.au3>



Global Const $NUMBER_OF_REG_EXP     	 = 2
Global Const $NUMBER_OF_PROJECT_TYPES	 = 2
Global Const $NUMBER_OF_TEMPLATES		 = 2


;------------------------------------------------------
;	Type to define which regular expressions are available
;------------------------------------------------------
Global Enum $HEADER_FUNCTIONS      = 0 , _
			$HEADER_PARAMETER      = 1

;------------------------------------------------------
;	Type to define who a file will be returned
;------------------------------------------------------
Global Enum $RETURN_AS_ARRAY	   = 0 , _
			$RETURN_AS_STRING	   = 1

;------------------------------------------------------
;	Type to define which Files can be commented
;------------------------------------------------------
Global Enum $C_PROJECT		   			= 0 , _			; Config Parameter for C - Projects
			$CPP_PROJECT			    = 1 			; Config Parameter for CPP - Projects

;
;
;
Global Enum $HEADER_TEMPLATE			= 0 , _
			$SOURCE_TEMPLATE			= 1


;-------------------------------------------------------
;	Av with all available regular expression
;-------------------------------------------------------
Global $regExp[$NUMBER_OF_PROJECT_TYPES][$NUMBER_OF_REG_EXP] =	_
		[  													    _
			[												    _
				'(\w+\s*\**)\s+(\w+)\(([\w+|\,|\s+]+)\)\;' ,    _
				'(\w+\s*\**)\s+(\w+)'				 		    _
			],                        						    _
			[												    _
				'Test',										    _
				'Test'											_
			]												    _
		]

Global $templates[$NUMBER_OF_PROJECT_TYPES][$NUMBER_OF_TEMPLATES] =    _
		[															   _
			[                                                          _
				"HeaderComment.temp",                                  _
				"SourceComment.temp"                                   _
			],									                       _
			[                                                          _
				"",                                                    _
				""                                                     _
			]														   _
		]

;=== CONFIGURATION PARAMETER ================================================================
Global $filterMask = "*.h"
Global $fileReturnType = $RETURN_AS_STRING
Global $projectType = $C_PROJECT
Global $filePath = @ScriptDir & "\TestFile"
Global $templatePath = @ScriptDir & "\Template"