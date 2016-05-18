
#include-once
#include "..\GUI\UI.au3"
#include <GuiComboBox.au3>
#include <GuiTab.au3>


;--- Global Parameter --------------------------------------------------------------------------------



;--- Functions ---------------------------------------------------------------------------------------

; #FUNCTION# ====================================================================================================================
; Name ..........: UI_UseEventMode
; Description ...:
; Syntax ........: UI_UseEventMode($bool)
; Parameters ....: $bool                - a boolean value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_UseEventMode($bool)
	If $bool = True Then
		Opt("GUIOnEventMode", TRUE)
	Else
		Opt("GUIOnEventMode", FALSE)
	EndIf
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: UI_SetCallbacks
; Description ...:
; Syntax ........: UI_SetCallbacks()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_SetCallbacks()
	GUISetOnEvent($GUI_EVENT_CLOSE, "UI_Close")
	GUICtrlSetOnEvent($AddModuleButton, "UI_AddModule")
	GUICtrlSetOnEvent($DeleteModuleButton, "UI_DeleteModule")

EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: UI_DelteRequest
; Description ...:
; Syntax ........: UI_DelteRequest($name)
; Parameters ....: $name                - a general number value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_DelteRequest($name)
	Local $flags, $retVal

	$flags = $MB_YESNO + $MB_ICONQUESTION
	$retVal = MsgBox($flags,"Löschen?", "Möchten Sie wirklich" & $name & "löschen?" )
	return $retVal
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: UI_GetComboText
; Description ...:
; Syntax ........: UI_GetComboText($iHndl)
; Parameters ....: $iHndl               - an integer value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_GetComboText($iHndl)
	Local $count, $index, $txt
	$count = _GUICtrlComboBox_GetCount($iHndl)
	$index = _GUICtrlComboBox_GetCurSel ( $iHndl )
	_GUICtrlComboBox_GetLBText ($iHndl,$index,$txt)
	Return $txt
EndFunc