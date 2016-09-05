#include-once
#include "CommonGlobals.au3"

Global Const $NUMBER_OF_TEMPLATES				= 2


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