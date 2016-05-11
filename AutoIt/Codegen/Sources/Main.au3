#include "UI_Settings.au3"






Main_Init()


Main_Main()













Func Main_Init()

UI_Init()
UI_UseEventMode(TRUE)
UI_SetCallbacks()

GUISetState(@SW_SHOW,$UI)

EndFunc



Func Main_Main()
While 1
	$nMsg = GUIGetMsg()
	Switch $nMsg
		Case $GUI_EVENT_CLOSE
			Exit

	EndSwitch
WEnd

EndFunc



Func Main_Shutdown()

EndFunc