#include <FileConstants.au3>
#include "RegExpGlobals.au3"
#include "TemplateGlobals.au3"





Global Const $NUMBER_OF_HEADER_TAGS	 			= 4
Global Const $NUMBER_OF_REG_EXP_HEADER_VALUES   = 3

;------------------------------------------------------
;
;------------------------------------------------------
Global Enum $RETURN_VALUE				= 0, _
			$FUNCTION_NAME				= 1, _
			$PARAMETER_LIST				= 2, _
			$PARAMETER_TYPE				= 0, _
			$PARAMETER_VALUE			= 1

;------------------------------------------------------
;	Type to define who a file will be returned
;------------------------------------------------------
Global Enum $RETURN_AS_ARRAY	   = 0 , _				; Enum for Parameter $retType
			$RETURN_AS_STRING	   = 1					; Enum for Parameter $retType


;------------------------------------------------------
;
;------------------------------------------------------
Global Enum $FUNCTION_TAG				= 0, _
			$PARAMETER_TAG				= 1, _
			$RETURN_TAG					= 2, _
			$DETAILED_TAG				= 3

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
Global $headerTags = $headerTagsAv

