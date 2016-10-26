Global $NUMBER_OF_REG_EXP     	 = 2
Global $NUMBER_OF_PROJECT_TYPES	 = 2




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