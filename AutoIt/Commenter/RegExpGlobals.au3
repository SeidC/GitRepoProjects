


Global Const $NUMBER_OF_PROJECT_TYPES			= 2
Global Const $NUMBER_OF_REG_EXP     			= 4


;------------------------------------------------------
;	Type to define which regular expressions are available
;------------------------------------------------------
Global Enum $HEADER_FUNCTIONS      = 0 , _
			$HEADER_PARAMETER      = 1 , _
			$ENUM_TYPES			   = 2 , _
			$ENUMS				   = 3

;-------------------------------------------------------
;	Av with all available regular expression
;-------------------------------------------------------
Global $regExp[$NUMBER_OF_PROJECT_TYPES][$NUMBER_OF_REG_EXP] =					_
		[  													    				_
			[												    				_
				'(\w+\s*\**)\s+(\w+)\(([\w+|\,|\s+]+)\)\;' ,    				_
				'(\w+\s*\**)\s+(\w+)',				 		    				_
				'typedef*\s+enum\s+\{+(?:\w|\s|\=|\,|\*|\;|\/|\-|\>)*\}\w*\;', 	_
			    'enum\s+(\w+)\s*\{+(?:\w|\s|\=|\,|\*|\;|\/|\-|\>)*\}\;'         _
			],																	_
			[												    				_
				'Test',										    				_
				'Test'															_
			]												    				_
		]


