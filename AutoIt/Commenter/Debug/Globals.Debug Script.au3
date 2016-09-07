AutoIt_Debugger_LoadFile("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3")
AutoIt_Debugger_DebugFile(@ScriptFullPath)

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 1, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\FileConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 1, False, @error, @extended))




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 5, False))
Global Const $NUMBER_OF_REG_EXP     			= 2
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 5, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_REG_EXP")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_REG_EXP", $NUMBER_OF_REG_EXP))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 6, False))
Global Const $NUMBER_OF_PROJECT_TYPES			= 2
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 6, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_PROJECT_TYPES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_PROJECT_TYPES", $NUMBER_OF_PROJECT_TYPES))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 7, False))
Global Const $NUMBER_OF_TEMPLATES				= 2
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 7, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_TEMPLATES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_TEMPLATES", $NUMBER_OF_TEMPLATES))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 8, False))
Global Const $NUMBER_OF_HEADER_TAGS	 			= 4
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 8, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_HEADER_TAGS")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_HEADER_TAGS", $NUMBER_OF_HEADER_TAGS))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 9, False))
Global Const $NUMBER_OF_REG_EXP_HEADER_VALUES   = 3
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 9, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_REG_EXP_HEADER_VALUES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_REG_EXP_HEADER_VALUES", $NUMBER_OF_REG_EXP_HEADER_VALUES))

;------------------------------------------------------
;
;------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 14, False))
 Global Enum $RETURN_VALUE				= 0, 			$FUNCTION_NAME				= 1, 			$PARAMETER_LIST				= 2, 			$PARAMETER_TYPE				= 0, 			$PARAMETER_VALUE			= 1
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 14, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("RETURN_VALUE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_VALUE", $RETURN_VALUE))
If SetError(@error, @extended, IsDeclared("FUNCTION_NAME")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FUNCTION_NAME", $FUNCTION_NAME))
If SetError(@error, @extended, IsDeclared("PARAMETER_LIST")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_LIST", $PARAMETER_LIST))
If SetError(@error, @extended, IsDeclared("PARAMETER_TYPE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_TYPE", $PARAMETER_TYPE))
If SetError(@error, @extended, IsDeclared("PARAMETER_VALUE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_VALUE", $PARAMETER_VALUE))


;------------------------------------------------------
;	Type to define which regular expressions are available
;------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 24, False))
 Global Enum $HEADER_FUNCTIONS      = 0 , 			$HEADER_PARAMETER      = 1
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 24, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("HEADER_FUNCTIONS")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_FUNCTIONS", $HEADER_FUNCTIONS))
If SetError(@error, @extended, IsDeclared("HEADER_PARAMETER")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_PARAMETER", $HEADER_PARAMETER))

;------------------------------------------------------
;	Type to define who a file will be returned
;------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 30, False))
 Global Enum $RETURN_AS_ARRAY	   = 0 , 			$RETURN_AS_STRING	   = 1					; Enum for Parameter $retType
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 30, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("RETURN_AS_ARRAY")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_AS_ARRAY", $RETURN_AS_ARRAY))
If SetError(@error, @extended, IsDeclared("RETURN_AS_STRING")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_AS_STRING", $RETURN_AS_STRING))

;------------------------------------------------------
;	Type to define which Files can be commented
;------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 36, False))
 Global Enum $C_PROJECT		   			= 0 , 			$CPP_PROJECT			    = 1 			; Config Parameter for CPP - Projects for Parameter $projectType
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 36, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("C_PROJECT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$C_PROJECT", $C_PROJECT))
If SetError(@error, @extended, IsDeclared("CPP_PROJECT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CPP_PROJECT", $CPP_PROJECT))

;------------------------------------------------------
;
;------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 42, False))
 Global Enum $HEADER_TEMPLATE			= 0 , 			$SOURCE_TEMPLATE			= 1				; Enum SOURCE_TEMPLATE Value for Parameter $templateType
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 42, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("HEADER_TEMPLATE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_TEMPLATE", $HEADER_TEMPLATE))
If SetError(@error, @extended, IsDeclared("SOURCE_TEMPLATE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SOURCE_TEMPLATE", $SOURCE_TEMPLATE))

;------------------------------------------------------
;
;------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 48, False))
 Global Enum $FUNCTION_TAG				= 0, 			$PARAMETER_TAG				= 1, 			$RETURN_TAG					= 2, 			$DETAILED_TAG				= 3
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 48, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("FUNCTION_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FUNCTION_TAG", $FUNCTION_TAG))
If SetError(@error, @extended, IsDeclared("PARAMETER_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_TAG", $PARAMETER_TAG))
If SetError(@error, @extended, IsDeclared("RETURN_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_TAG", $RETURN_TAG))
If SetError(@error, @extended, IsDeclared("DETAILED_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$DETAILED_TAG", $DETAILED_TAG))

;-------------------------------------------------------
;	Av with all available regular expression
;-------------------------------------------------------

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 56, False))
 Global $regExp[$NUMBER_OF_PROJECT_TYPES][$NUMBER_OF_REG_EXP] = 		[  													    			[												    				'(\w+\s*\**)\s+(\w+)\(([\w+|\,|\s+]+)\)\;' ,    				'(\w+\s*\**)\s+(\w+)'				 		    			],                        						    			[												    				'Test',										    				'Test'										 			]												    		]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 56, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("regExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExp", $regExp))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_PROJECT_TYPES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_PROJECT_TYPES", $NUMBER_OF_PROJECT_TYPES))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_REG_EXP")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_REG_EXP", $NUMBER_OF_REG_EXP))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 68, False))
 Global $templates[$NUMBER_OF_PROJECT_TYPES][$NUMBER_OF_TEMPLATES] =    		[															   			[                                                          				"HeaderComment.temp",                                  				"SourceComment.temp"                                   			],									                       			[                                                          				"",                                                    				""                                                     			]														   		]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 68, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("templates")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templates", $templates))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_PROJECT_TYPES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_PROJECT_TYPES", $NUMBER_OF_PROJECT_TYPES))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_TEMPLATES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_TEMPLATES", $NUMBER_OF_TEMPLATES))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 80, False))
 Global $headerTagsAv[$NUMBER_OF_HEADER_TAGS] = 	[										 		"<!@brief@!>",						 		"<!@param@!>",						 		"<!@return@!>",						 		"<!@detail@!>"						 	]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 80, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("headerTagsAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTagsAv", $headerTagsAv))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_HEADER_TAGS")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_HEADER_TAGS", $NUMBER_OF_HEADER_TAGS))


;=== CONFIGURATION PARAMETER ================================================================

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 90, False))
Global $filterMask = "*.h"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 90, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filterMask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filterMask", $filterMask))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 91, False))
Global $fileReturnType = $RETURN_AS_STRING
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 91, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("fileReturnType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$fileReturnType", $fileReturnType))
If SetError(@error, @extended, IsDeclared("RETURN_AS_STRING")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_AS_STRING", $RETURN_AS_STRING))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 92, False))
Global $projectType = $C_PROJECT
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 92, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("C_PROJECT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$C_PROJECT", $C_PROJECT))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 93, False))
Global $filePath = $TempOriginalFileBeingDebuggedFileFolder & "\TestFile"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 93, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))
If SetError(@error, @extended, IsDeclared("TempOriginalFileBeingDebuggedFileFolder")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$TempOriginalFileBeingDebuggedFileFolder", $TempOriginalFileBeingDebuggedFileFolder))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 94, False))
Global $templatePath = $TempOriginalFileBeingDebuggedFileFolder & "\Template"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 94, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("templatePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templatePath", $templatePath))
If SetError(@error, @extended, IsDeclared("TempOriginalFileBeingDebuggedFileFolder")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$TempOriginalFileBeingDebuggedFileFolder", $TempOriginalFileBeingDebuggedFileFolder))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 95, False))
Global $headerTags = $headerTagsAv
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Globals.au3", "Globals.au3", 95, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("headerTags")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTags", $headerTags))
If SetError(@error, @extended, IsDeclared("headerTagsAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTagsAv", $headerTagsAv))

