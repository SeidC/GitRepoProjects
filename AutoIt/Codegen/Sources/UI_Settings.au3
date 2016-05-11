#include "UI_Callbacks.au3"



Func UI_UseEventMode($bool)
	If $bool = True Then
		Opt("GUIOnEventMode", TRUE)
	Else
		Opt("GUIOnEventMode", FALSE)
	EndIf
EndFunc



Func UI_SetCallbacks()
	GUISetOnEvent($GUI_EVENT_CLOSE, "UI_Close")


EndFunc



