#include <FileConstants.au3>



Global Const $NUMBER_OF_REG_EXP     	 = 2
Global Const $NUMBER_OF_PROJECT_TYPES	 = 2
Global Const $NUMBER_OF_TEMPLATES		 = 2
Global Const $NUMBER_OF_HEADER_TAGS	 	 = 4


;------------------------------------------------------
;
;------------------------------------------------------
Global Enum $RETURN_VALUE				= 0, _
			$FUNCTION_NAME				= 1, _
			$PARAMETER_LIST				= 2


;------------------------------------------------------
;	Type to define which regular expressions are available
;------------------------------------------------------
Global Enum $HEADER_FUNCTIONS      = 0 , _
			$HEADER_PARAMETER      = 1

;------------------------------------------------------
;	Type to define who a file will be returned
;------------------------------------------------------
Global Enum $RETURN_AS_ARRAY	   = 0 , _				; Enum for Parameter $retType
			$RETURN_AS_STRING	   = 1					; Enum for Parameter $retType

;------------------------------------------------------
;	Type to define which Files can be commented
;------------------------------------------------------
Global Enum $C_PROJECT		   			= 0 , _			; Config Parameter for C - Projects for Parameter $projectType
			$CPP_PROJECT			    = 1 			; Config Parameter for CPP - Projects for Parameter $projectType

;------------------------------------------------------
;
;------------------------------------------------------
Global Enum $HEADER_TEMPLATE			= 0 , _			; Enum HEADER_TEMPLATE Value for Parameter $templateType
			$SOURCE_TEMPLATE			= 1				; Enum SOURCE_TEMPLATE Value for Parameter $templateType

;------------------------------------------------------
;
;------------------------------------------------------
Global Enum $FUNCTION_TAG				= 0, _
			$PARAMETER_TAG				= 1, _
			$RETURN_TAG					= 2, _
			$DETAILED_TAG				= 3

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

Global $headerTagsAv[$NUMBER_OF_HEADER_TAGS] = _
	[										 _
		"<!@brief@!>",						 _
		"<!@param@!>",						 _
		"<!@return@!>",						 _
		"<!@detail@!>"						 _
	]


;=== CONFIGURATION PARAMETER ================================================================
Global $filterMask = "*.h"
Global $fileReturnType = $RETURN_AS_STRING
Global $projectType = $C_PROJECT
Global $filePath = @ScriptDir & "\TestFile"
Global $templatePath = @ScriptDir & "\Template"
global $headerTags = $headerTagsAv