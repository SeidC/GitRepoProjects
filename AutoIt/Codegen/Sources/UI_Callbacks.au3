#include "UI_Settings.au3"






;--- Functions ---------------------------------------------------------------------------------------
; #FUNCTION# ====================================================================================================================
; Name ..........: UI_Close
; Description ...:
; Syntax ........: UI_Close()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_Close()
	Exit
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: UI_AddModule
; Description ...:
; Syntax ........: UI_AddModule()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_AddModule()
	Local $count, $cancle, $module

	$count = _GUICtrlTab_GetItemCount ($Tab1)
	$cancle = False
	$module = UI_GetComboText($ModuleCombo)
	For $i = 0 To $count - 1
		If (_GUICtrlTab_GetItemText($Tab1,$i) = $module) Then
		 $cancle = True
		 ExitLoop
		EndIf
	Next

	If($cancle = False) Then
		_GUICtrlTab_InsertItem($Tab1,$count,$module)
	EndIf
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: UI_DeleteModule
; Description ...:
; Syntax ........: UI_DeleteModule()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func UI_DeleteModule()
	Local $module, $del,$count

	$module = UI_GetComboText($ModuleCombo)
	$del = UI_DelteRequest($module)

	If($del = $IDYES ) Then
		$count = _GUICtrlTab_GetItemCount ($Tab1)
		For $i = 0 To $count - 1
			If (_GUICtrlTab_GetItemText($Tab1,$i) = $module) Then
				_GUICtrlTab_DeleteItem ( $Tab1, $i )
			EndIf
		Next
	EndIf
EndFunc
