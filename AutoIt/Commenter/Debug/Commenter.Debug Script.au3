Global $AutoItDebugger_Paused = 0
Global $AutoItDebugger_Quit = 0
Global $AutoItDebugger_Error
Global $AutoItDebugger_Extended
Global $AutoItDebuggerCommandWindowName = ""
Global $AutoItDebuggerCommandWindow
Global $AutoItDebuggerCommandWindowListbox
OnAutoItExitRegister("AutoIt_Debugger_OnAutoItExit")
AutoIt_Debugger_CreateMessageWindow()
$TempOriginalFileBeingDebuggedFileName = "Commenter.au3"
$TempOriginalFileBeingDebuggedFileFolder = "Z:\Projekte\Projects\AutoIt\Commenter"
$TempOriginalFileBeingDebuggedFilePath = "Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3"
AutoIt_Debugger_LoadFile("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3")
AutoIt_Debugger_DebugFile(@ScriptFullPath)

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 1, False))
#include-once
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 1, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 3, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\Array.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 3, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 4, False))
#Include "Z:\Projekte\Projects\AutoIt\Commenter\Debug\Functions.Debug Script.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 4, False, @error, @extended))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 7, False))
Init()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 7, False, @error, @extended))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 10, False))
Main()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 10, False, @error, @extended))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 13, False))
DeInit()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 13, False, @error, @extended))




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 17, False))
Func Init()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 17, False, @error, @extended))


EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 23, False))
Func Main()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 23, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 25, False))
	MainTask()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 25, False, @error, @extended))

EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 30, False))
Func DeInit()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Commenter.au3", "Commenter.au3", 30, False, @error, @extended))


EndFunc


Func AutoIt_Debugger_OnAutoItExit()
   AutoIt_Debugger_WaitForExit()
EndFunc

Func CheckForVariableChange($VariableName, $AutoItDebugger_ArrayIndexString,  $VariableValue)
EndFunc
#cs ----------------------------------------------------------------------------

	AutoIt Version: 3.2.1.11 (beta)
	Author:         myName

	Script Function:
	The command code for the AutoIt Debugger (this was the Include file)

#ce ----------------------------------------------------------------------------

;Uncomment the following to check that all variables are defined
;AutoItSetOption("MustDeclareVars", 1)

Func AutoIt_Debugger_CreateMessageWindow()
	;#Include <winapi.au3>
	;#include <GUIConstants.au3>
	;#include <WindowsConstants.au3>
	;#include-once

	#region ### START Koda GUI section ### Form=_AutoIt Debugger Include.kxf
	$AutoItDebuggerCommandWindow = GUICreate("AutoIt Debugger Command Window", 621, 328, 193, 126)
	$AutoItDebuggerCommandWindowListbox = GUICtrlCreateList("", 8, 8, 609, 305)
	#endregion ### END Koda GUI section ###
	;GUISetState(@SW_SHOW)

	; Register Windows Messages
	GUIRegisterMsg(0x004A, "_GUIRegisterMsgProc") ;Global Const $WM_COPYDATA = 0x004A

	;Dim $AutoItDebugger_ClosedByUser
	;Dim $AutoItDebugger_LastError
	;Dim $AutoItDebugger_LastExtended
EndFunc   ;==>AutoIt_Debugger_CreateMessageWindow


Func AutoItDebuggerEvent_ChangeVariable($VariableName, $VariableValue)
	;MsgBox(0, "_AutoIt Debugger Include", "Entered 'AutoItDebuggerEvent_ChangeVariable'")

	Dim $AutoItDebugger_ArrayIndexString = ""
	Dim $StrippedVariableName = $VariableName

	;Convert array variables from $asMyArray[1] format to a
	Local $iOpenSquareBracketPos
	$iOpenSquareBracketPos = StringInStr($VariableName, "[")
	If $iOpenSquareBracketPos <> 0 Then
		$StrippedVariableName = StringLeft($VariableName, $iOpenSquareBracketPos - 1)
		;Strip the variable name and open bracket to leave '1][1]' etc.
		$AutoItDebugger_ArrayIndexString = StringTrimLeft($VariableName, $iOpenSquareBracketPos)
		;Strip the close bracket to leave '1][1' etc.
		$AutoItDebugger_ArrayIndexString = StringTrimRight($AutoItDebugger_ArrayIndexString, 1)
		;Remove any ][ from the string and replace with | to make 1][1 into 1|1
		$AutoItDebugger_ArrayIndexString = StringReplace($AutoItDebugger_ArrayIndexString, "][", "|")
		;MsgBox(0, "_AutoIt Debugger Include", $AutoItDebugger_ArrayIndexString)
	EndIf

	;Check if the variable is actually a variable
	If IsDeclared(StringTrimLeft($VariableName, 1)) Then
		CheckForVariableChange($StrippedVariableName, $AutoItDebugger_ArrayIndexString, $VariableValue)
	Else
		;MsgBox features: Title=Yes, Text=Yes, Buttons=OK, Icon=Warning
		MsgBox(48, "_AutoIt Debugger Include", "AutoIt Debugger GUI sent attempted to change the value of an undeclared variable (" & $StrippedVariableName & ")")
	EndIf
EndFunc   ;==>AutoItDebuggerEvent_ChangeVariable


Func AutoIt_Debugger_NextLine($Filepath, $Filename, $LineNumber, $SkipLine)
	Local $sChangedVariableName

	;Default to single step
	$AutoItDebugger_Paused = 1

	;Send new line status to the Debug GUI
	_AU3COM_SendData_NewLine($Filepath & "|" & $Filename & "|" & $LineNumber & "|" & $SkipLine)

	;Wait for the GUI to come off pause
	While $AutoItDebugger_Paused
		;Quit if necessary
		If $AutoItDebugger_Quit Then
			Exit
		EndIf

		;Wait
		Sleep(50)
	WEnd
EndFunc   ;==>AutoIt_Debugger_NextLine


Func AutoIt_Debugger_FinishedLine($Filepath, $Filename, $LineNumber, $SkipLine, $NextLine_Error, $NextLine_Extended)

	;If Not $SkipLine Then
	;Send new line status to the Debug GUI
	_AU3COM_SendData_FinishedLine($Filepath & "|" & $Filename & "|" & $LineNumber & "|" & $SkipLine)

	;Send the @error and @extended data on each new line
	_AU3COM_SendData_SendVariable("@error" & "|" & $NextLine_Error)
	_AU3COM_SendData_SendVariable("@extended" & "|" & $NextLine_Extended)
	;EndIf
EndFunc   ;==>AutoIt_Debugger_FinishedLine


Func AutoIt_Debugger_WaitForExit()
	;Send script finished message
	_AU3COM_SendData_ScriptFinished("ScriptFinishing")

	#region --- CodeWizard generated code Start ---
	;MsgBox features: Title=No, Text=Yes, Buttons=OK, Icon=Question
	MsgBox(64, "AutoIt Debugger", "Script Finished. Click OK to return to development mode.")
	#endregion --- CodeWizard generated code Start ---

	_AU3COM_SendData_ScriptFinished("ScriptFinished")
EndFunc   ;==>AutoIt_Debugger_WaitForExit


Func AutoIt_Debugger_LoadFile($ORiginalScriptFilePath, $ORiginalScriptFileName)
	If $AutoItDebuggerCommandWindowName = "" Then
		;Take the first script name as the command window name
		$AutoItDebuggerCommandWindowName = $ORiginalScriptFilePath

		;Change this windows name
		WinSetTitle("AutoIt Debugger Command Window", "", $AutoItDebuggerCommandWindowName & " AutoIt Debugger Command Window")
	EndIf

	;Default to single step
	$AutoItDebugger_Paused = 1

	_AU3COM_SendData_LoadFile($ORiginalScriptFilePath & "|" & $ORiginalScriptFileName)

	;Wait for the GUI to come off pause
	While $AutoItDebugger_Paused
		;Quit if necessary
		If $AutoItDebugger_Quit Then
			Exit
		EndIf

		;Wait
		Sleep(50)
	WEnd
EndFunc   ;==>AutoIt_Debugger_LoadFile


Func AutoIt_Debugger_DebugFile($DebugScriptFilePath)
	;Default to single step
	$AutoItDebugger_Paused = 1

	_AU3COM_SendData_DebugFile($DebugScriptFilePath)

	;Wait for the GUI to come off pause
	While $AutoItDebugger_Paused
		;Quit if necessary
		If $AutoItDebugger_Quit Then
			Exit
		EndIf

		;Wait
		Sleep(50)
	WEnd
EndFunc   ;==>AutoIt_Debugger_DebugFile


Func AutoIt_Debugger_SendVariable($VariableName, $VariableValue)
	Local $iNumberOfDims
	Local $iDimXIndex
	Local $iDimYIndex
	Local $iDimZIndex

	;Determine if this is a array variable
	If IsArray($VariableValue) Then
		;Find the number of dimensions
		$iNumberOfDims = UBound($VariableValue, 0)
		Select
			Case $iNumberOfDims = 1
				;Send each array index seperatly
				For $iDimXIndex = 0 To UBound($VariableValue, 1) - 1
					;$oDebug.SendVariable ($VariableName & "[" & $iDimXIndex & "]", AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue[$iDimXIndex]))
					_AU3COM_SendData_SendVariable($VariableName & "[" & $iDimXIndex & "]" & "|" & AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue[$iDimXIndex]))
				Next

			Case $iNumberOfDims = 2
				;Repeat for each X dimension
				For $iDimXIndex = 0 To UBound($VariableValue, 1) - 1
					;Repeat for each Y dimension
					For $iDimYIndex = 0 To UBound($VariableValue, 2) - 1
						;$oDebug.SendVariable ($VariableName & "[" & $iDimXIndex & "][" & $iDimYIndex & "]", AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue[$iDimXIndex][$iDimYIndex]))
						_AU3COM_SendData_SendVariable($VariableName & "[" & $iDimXIndex & "][" & $iDimYIndex & "]" & "|" & AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue[$iDimXIndex][$iDimYIndex]))
					Next
				Next

			Case $iNumberOfDims = 3
				;Repeat for each X dimension
				For $iDimXIndex = 0 To UBound($VariableValue, 1) - 1
					;Repeat for each Y dimension
					For $iDimYIndex = 0 To UBound($VariableValue, 2) - 1
						;Repeat for each Z dimension
						For $iDimZIndex = 0 To UBound($VariableValue, 3) - 1
							;$oDebug.SendVariable ($VariableName & "[" & $iDimXIndex & "][" & $iDimYIndex & "][" & $iDimZIndex & "]", AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue[$iDimXIndex][$iDimYIndex][$iDimZIndex]))
							_AU3COM_SendData_SendVariable($VariableName & "[" & $iDimXIndex & "][" & $iDimYIndex & "][" & $iDimZIndex & "]" & "|" & AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue[$iDimXIndex][$iDimYIndex][$iDimZIndex]))
						Next
					Next
				Next

			Case Else
				;$oDebug.SendVariable ($VariableName, "<Array has too many dims>")
				_AU3COM_SendData_SendVariable($VariableName & "|" & "<Array has too many dims>")
		EndSelect
	Else
		;$oDebug.SendVariable ($VariableName, AutoIt_Debugger_ReturnVariableValue($VariableValue))
		_AU3COM_SendData_SendVariable($VariableName & "|" & AutoIt_Debugger_ReturnVariableValue($VariableName, $VariableValue))
	EndIf
EndFunc   ;==>AutoIt_Debugger_SendVariable


Func AutoIt_Debugger_SendConsoleWrite($OutputString)
	_AU3COM_SendData_ConsoleWrite($OutputString)
EndFunc   ;==>AutoIt_Debugger_SendConsoleWrite


Func AutoIt_Debugger_ReturnVariableValue($AutoIt_Debugger_VariableName, $AutoIt_Debugger_VariableValue)
	Local $AutoIt_Debugger_sRes = ""
	;$AutoIt_Debugger_VariableValue = Execute($AutoIt_Debugger_VariableName)
	If IsBool($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= $AutoIt_Debugger_VariableValue
	If IsFloat($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= $AutoIt_Debugger_VariableValue
	If IsInt($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= $AutoIt_Debugger_VariableValue
	;If IsNumber($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= $AutoIt_Debugger_VariableValue
	If IsString($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= StringLeft($AutoIt_Debugger_VariableValue, 256)
	If IsArray($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= $AutoIt_Debugger_VariableValue
	If IsObj($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= "<Object>" & $AutoIt_Debugger_VariableValue
	If IsBinary($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= "<Binary>" & $AutoIt_Debugger_VariableValue
	If IsHWnd($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= "<HWnd>" & $AutoIt_Debugger_VariableValue
	If IsKeyword($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= "<Keyword>" & $AutoIt_Debugger_VariableValue
	If IsDllStruct($AutoIt_Debugger_VariableValue) Then $AutoIt_Debugger_sRes &= "<DllStructure>" & $AutoIt_Debugger_VariableValue

	;If StringLeft($AutoIt_Debugger_VariableName, 1) <> "$" Then $AutoIt_Debugger_VariableName = "$" & $AutoIt_Debugger_VariableName
	;If Not IsDeclared(StringTrimLeft($AutoIt_Debugger_VariableName, 1)) Then $AutoIt_Debugger_sRes &= "<Undeclared>"

	Return $AutoIt_Debugger_sRes
EndFunc   ;==>AutoIt_Debugger_ReturnVariableValue


Func AutoIt_Debugger_GetVariableFromEvent($VariableName, ByRef $Variable, $AutoItDebugger_ArrayIndexString, $VariableValue)
	;MsgBox(0, "_AutoIt Debugger Include", "Entered 'AutoIt_Debugger_GetVariableFromEvent'")

	Local $iNumberOfDims
	Local $iDimXIndex
	Local $iDimYIndex
	Local $iDimZIndex
	Local $ArrayIndexArray

	If IsBool($Variable) Or IsFloat($Variable) Or IsInt($Variable) Or IsNumber($Variable) Or IsString($Variable) Then
		$Variable = $VariableValue
		;MsgBox(0, "_AutoIt Debugger Include", "New value of '" & $VariableName & " is '" & $Variable & "'")
	ElseIf IsArray($Variable) Then
		;Extract the array section, split by |s
		$ArrayIndexArray = StringSplit($AutoItDebugger_ArrayIndexString, "|")

		;Find the number of dimensions
		$iNumberOfDims = $ArrayIndexArray[0]
		Select
			Case $iNumberOfDims = 1
				;Set the value based on the array index
				$Variable[$ArrayIndexArray[1]] = $VariableValue

			Case $iNumberOfDims = 2
				;Set the value based on the array index
				$Variable[$ArrayIndexArray[1]][$ArrayIndexArray[2]] = $VariableValue

			Case $iNumberOfDims = 3
				;Set the value based on the array index
				$Variable[$ArrayIndexArray[1]][$ArrayIndexArray[2]][$ArrayIndexArray[3]] = $VariableValue

			Case Else
				;Do nothing
		EndSelect

	ElseIf IsObj($Variable) Then
		;Do nothing
	ElseIf IsBinary($Variable) Then
		;Do nothing
	ElseIf IsHWnd($Variable) Then
		;Do nothing
	ElseIf IsKeyword($Variable) Then
		;Do nothing
	EndIf
EndFunc   ;==>AutoIt_Debugger_GetVariableFromEvent


; Message Handler
Func _GUIRegisterMsgProc($hWnd, $MsgID, $WParam, $LParam)
	If $MsgID = 0x004A Then ;Global Const $WM_COPYDATA = 0x004A

		; $LParam = Poiter to a COPYDATA Struct
		Local $STRUCTDEF_AU3MESSAGE = "char var1[256]"
		Local $STRUCTDEF_AU3MESSAGELEN = "dword var1"
		Local $StructDef_COPYDATA = "dword var1;dword var2;ptr var3"

		;Set a reference to the COPYDATA structure
		Local $vs_cds = DllStructCreate($StructDef_COPYDATA, $LParam)
		;Extract the command (the 1st element)
		Local $msgType = DllStructGetData($vs_cds, 1)

		;MsgBox(0, "AutoIt Debugger", "Command Received: " & $msgType)

		Select
			Case $msgType = 0

				;Log message
				;GUICtrlSetData($AutoItDebuggerCommandWindowListbox,_Now() & ": New variable")

				;Get the message length from the 2nd element
				Local $msglen1 = DllStructGetData($vs_cds, 2)
				Local $STRUCTDEF_AU3MESSAGE1 = "char var1[" & $msglen1 & "]"
				Local $vs_msg1 = DllStructCreate($STRUCTDEF_AU3MESSAGE1, DllStructGetData($vs_cds, 3))

				;Display what we have recived
				Local $MSGRECVD = DllStructGetData($vs_msg1, 1)
				;MsgBox(0, "Recver - Test String", $MSGRECVD)

				Local $iSpacePos
				$iSpacePos = StringInStr($MSGRECVD, " ")
				Dim $sChangedVariableName = StringLeft($MSGRECVD, $iSpacePos - 1)
				Dim $sChangedVariableValue = StringRight($MSGRECVD, StringLen($MSGRECVD) - $iSpacePos)

				;MsgBox(0, "Variable Name", "'" & $sChangedVariableName & "'")
				;MsgBox(0, "Variable Value", "'" & $sChangedVariableValue & "'")

				;Run change variable code
				AutoItDebuggerEvent_ChangeVariable($sChangedVariableName, $sChangedVariableValue)

			Case $msgType = 1
				$AutoItDebugger_Paused = 0

				;Log message
				;GUICtrlSetData($AutoItDebuggerCommandWindowListbox,_Now() & ": Removed Pause")

			Case $msgType = 2
				$AutoItDebugger_Quit = 1

				;Log message
				;GUICtrlSetData($AutoItDebuggerCommandWindowListbox, _Now() & ": Received Quit")

		EndSelect

	ElseIf $MsgID = 0x0010 Then ;=== We Recived a WM_CLOSE Message ;Global Const $WM_CLOSE = 0x0010
		Exit
	EndIf
EndFunc   ;==>_GUIRegisterMsgProc


Func _AU3COM_SendData($MessageType, $InfoToSend)
	Local $StructDef_COPYDATA = "dword var1;dword var2;ptr var3"
	Local $CDString = DllStructCreate("char var1[256];char var2[256]") ;the array to hold the string we are sending

	DllStructSetData($CDString, 1, $InfoToSend)
	Local $pCDString = DllStructGetPtr($CDString) ;the pointer to the string
	Local $vs_cds = DllStructCreate($StructDef_COPYDATA);create the message struct
	DllStructSetData($vs_cds, "var1", $MessageType)
	DllStructSetData($vs_cds, "var2", String(StringLen($InfoToSend)));tell the receiver the length of the string
	DllStructSetData($vs_cds, "var3", $pCDString) ;the pointer to the string
	Local $pStruct = DllStructGetPtr($vs_cds)

	AutoIt_Debugger_SendMessage(WinGetHandle("AutoIt Debugger - " & $AutoItDebuggerCommandWindowName), 0x004A, 0, $pStruct) ;Global Const $WM_COPYDATA = 0x004A

	$vs_cds = 0 ;free the struct
	$CDString = 0 ;free the struct

	Return 1
EndFunc   ;==>_AU3COM_SendData


Func _AU3COM_SendData_NewLine($InfoToSend)
	_AU3COM_SendData(1, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_NewLine


Func _AU3COM_SendData_FinishedLine($InfoToSend)
	_AU3COM_SendData(2, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_FinishedLine


Func _AU3COM_SendData_SendVariable($InfoToSend)
	_AU3COM_SendData(3, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_SendVariable


Func _AU3COM_SendData_LoadFile($InfoToSend)
	_AU3COM_SendData(4, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_LoadFile


Func _AU3COM_SendData_ScriptFinished($InfoToSend)
	_AU3COM_SendData(5, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_ScriptFinished


Func _AU3COM_SendData_DebugFile($InfoToSend)
	_AU3COM_SendData(6, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_DebugFile

Func _AU3COM_SendData_ConsoleWrite($InfoToSend)
	_AU3COM_SendData(7, $InfoToSend)
EndFunc   ;==>_AU3COM_SendData_ConsoleWrite

; #FUNCTION# ====================================================================================================================
; Name...........: _SendMessage
; Description ...: Wrapper for commonly used Dll Call
; Syntax.........: _SendMessage($hWnd, $iMsg[, $wParam = 0[, $lParam = 0[, $iReturn = 0[, $wParamType = "wparam"[, $lParamType = "lparam"[, $sReturnType = "lresult"]]]]]])
; Parameters ....: $hWnd       - Window/control handle
;                  $iMsg       - Message to send to control (number)
;                  $wParam     - Specifies additional message-specific information
;                  $lParam     - Specifies additional message-specific information
;                  $iReturn    - What to return:
;                  |0 - Return value from dll call
;                  |1 - $ihWnd
;                  |2 - $iMsg
;                  |3 - $wParam
;                  |4 - $lParam
;                  |<0 or > 4 - array same as dllcall
;                  $wParamType - See DllCall in Related
;                  $lParamType - See DllCall in Related
;                  $sReturnType - See DllCall in Related
; Return values .: Success      - User selected value from the DllCall() result
;                  Failure      - @error is set
; Author ........: Valik
; Modified.......: Gary Frost (GaryFrost) aka gafrost
; Remarks .......:
; Related .......: _SendMessage, DllCall
; Link ..........:
; Example .......: Yes
; ===============================================================================================================================
Func AutoIt_Debugger_SendMessage($hWnd, $iMsg, $WParam = 0, $LParam = 0, $iReturn = 0, $wParamType = "wparam", $lParamType = "lparam", $sReturnType = "lresult")
	Local $aResult = DllCall("user32.dll", $sReturnType, "SendMessageW", "hwnd", $hWnd, "uint", $iMsg, $wParamType, $WParam, $lParamType, $LParam)
	If @error Then Return SetError(@error, @extended, "")
	If $iReturn >= 0 And $iReturn <= 4 Then Return $aResult[$iReturn]
	Return $aResult
EndFunc   ;==>AutoIt_Debugger_SendMessage

