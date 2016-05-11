
#include-once
#include "..\GUI\UI.au3"
#include <GuiComboBox.au3>
#include <GuiTab.au3>


;--- Global Parameter --------------------------------------------------------------------------------



;--- Functions ---------------------------------------------------------------------------------------
Func UI_UseEventMode($bool)
	If $bool = True Then
		Opt("GUIOnEventMode", TRUE)
	Else
		Opt("GUIOnEventMode", FALSE)
	EndIf
EndFunc



Func UI_SetCallbacks()
	GUISetOnEvent($GUI_EVENT_CLOSE, "UI_Close")
	GUICtrlSetOnEvent($AddModuleButton, "UI_AddModule")
	GUICtrlSetOnEvent($DeleteModuleButton, "UI_DeleteModule")

EndFunc



Func UI_DelteRequest($name)
	Local $flags, $retVal

	$flags = $MB_YESNO + $MB_ICONQUESTION
	$retVal = MsgBox($flags,"Löschen?", "Möchten Sie wirklich" & $name & "löschen?" )
	return $retVal
EndFunc


Func UI_GetComboText($iHndl)
	Local $count, $index, $txt
	$count = _GUICtrlComboBox_GetCount($iHndl)
	$index = _GUICtrlComboBox_GetCurSel ( $iHndl )
	_GUICtrlComboBox_GetLBText ($iHndl,$index,$txt)
	Return $txt
EndFunc