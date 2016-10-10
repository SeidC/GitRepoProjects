AutoIt_Debugger_LoadFile("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3")
AutoIt_Debugger_DebugFile(@ScriptFullPath)

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 1, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\File.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 1, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 2, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\Array.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 2, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 3, False))
#Include "Z:\Projekte\Projects\AutoIt\Commenter\Debug\DoxyGen.Debug Script.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 3, False, @error, @extended))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 6, False))
Func GetAllFromFile($path,$retType)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 6, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))
If SetError(@error, @extended, IsDeclared("retType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$retType", $retType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 7, False))
	Local $ret
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 7, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 8, False))
	If $retType = $RETURN_AS_ARRAY Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 8, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("retType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$retType", $retType))
If SetError(@error, @extended, IsDeclared("RETURN_AS_ARRAY")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_AS_ARRAY", $RETURN_AS_ARRAY))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 9, False))
		$ret = GetAllFromFileToArray($path)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 9, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 10, False))
		SetError(@error)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 10, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 11, False))
	ElseIf $retType = $RETURN_AS_STRING Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 11, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("retType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$retType", $retType))
If SetError(@error, @extended, IsDeclared("RETURN_AS_STRING")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_AS_STRING", $RETURN_AS_STRING))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 12, False))
		$ret = GetAllFromFileToString($path)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 12, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 13, False))
		SetError(@error)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 13, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 14, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 14, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 15, False))
		SetError(-1)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 15, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 16, False))
		$ret = -1
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 16, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 17, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 17, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 18, False))
	Return $ret
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 18, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
EndFunc


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 21, False))
Func GetAllFromFileToString($path)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 21, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 22, False))
	Local $data, $hndl, $error
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 22, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("data")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$data", $data))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 24, False))
	$hndl = FileOpen($path,$FO_READ)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 24, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))
If SetError(@error, @extended, IsDeclared("FO_READ")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FO_READ", $FO_READ))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 25, False))
	$error = @error
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 25, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 27, False))
	If Not $error Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 27, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 28, False))
		$data = FileRead($hndl)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 28, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("data")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$data", $data))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 29, False))
		SetError(@error,@extended)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 29, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 30, False))
		FileClose($hndl)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 30, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 31, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 31, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 32, False))
		SetError($error)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 32, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 33, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 33, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 35, False))
	Return $data
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 35, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("data")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$data", $data))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 39, False))
Func GetAllFromFileToArray($path)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 39, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 40, False))
	Local $dataAv, $hndl, $error
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 40, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("dataAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$dataAv", $dataAv))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 42, False))
	$hndl = FileOpen($path,$FO_READ)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 42, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))
If SetError(@error, @extended, IsDeclared("FO_READ")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FO_READ", $FO_READ))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 43, False))
	$error = @error
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 43, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 45, False))
	If Not $error Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 45, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 46, False))
		$dataAv = FileReadToArray($hndl)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 46, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("dataAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$dataAv", $dataAv))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 47, False))
		SetError(@error,@extended)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 47, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 48, False))
		FileClose($hndl)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 48, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 49, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 49, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 50, False))
		SetError($error)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 50, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 51, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 51, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 53, False))
	Return $dataAv
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 53, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("dataAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$dataAv", $dataAv))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 57, False))
Func GetRegExp($projectType,$regExpType)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 57, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("regExpType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExpType", $regExpType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 58, False))
	Local $ret = -1
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 58, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 59, False))
	If $regExpType < $NUMBER_OF_REG_EXP Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 59, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("regExpType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExpType", $regExpType))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_REG_EXP")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_REG_EXP", $NUMBER_OF_REG_EXP))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 60, False))
		$ret = $regExp[$projectType][$regExpType]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 60, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
If SetError(@error, @extended, IsDeclared("regExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExp", $regExp))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("regExpType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExpType", $regExpType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 61, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 61, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 62, False))
	Return $ret
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 62, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 66, False))
Func GetProjectType()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 66, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 67, False))
	Return $projectType
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 67, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
EndFunc


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 70, False))
Func GetFileReturnType()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 70, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 71, False))
	Return $fileReturnType
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 71, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("fileReturnType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$fileReturnType", $fileReturnType))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 75, False))
Func GetAllFileToAv($filePath, $filterMask)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 75, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))
If SetError(@error, @extended, IsDeclared("filterMask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filterMask", $filterMask))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 76, False))
	return _FileListToArrayRec($filePath,$filterMask,$FLTAR_FILES,$FLTAR_RECUR,$FLTAR_SORT,$FLTAR_FULLPATH )
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 76, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))
If SetError(@error, @extended, IsDeclared("filterMask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filterMask", $filterMask))
If SetError(@error, @extended, IsDeclared("FLTAR_FILES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FLTAR_FILES", $FLTAR_FILES))
If SetError(@error, @extended, IsDeclared("FLTAR_RECUR")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FLTAR_RECUR", $FLTAR_RECUR))
If SetError(@error, @extended, IsDeclared("FLTAR_SORT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FLTAR_SORT", $FLTAR_SORT))
If SetError(@error, @extended, IsDeclared("FLTAR_FULLPATH")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FLTAR_FULLPATH", $FLTAR_FULLPATH))
EndFunc


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 79, False))
Func MainTask()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 79, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 80, False))
	Local $av, $mask
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 80, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("mask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$mask", $mask))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 81, False))
	Local $path, $filePath
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 81, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 82, False))
	Local $fileContent,$contentReturn
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 82, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("fileContent")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$fileContent", $fileContent))
If SetError(@error, @extended, IsDeclared("contentReturn")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$contentReturn", $contentReturn))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 85, False))
	$path = GetPath()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 85, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 86, False))
	$mask = GetFilterMask()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 86, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("mask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$mask", $mask))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 87, False))
	$av = GetAllFileToAv($path,$mask)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 87, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("path")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$path", $path))
If SetError(@error, @extended, IsDeclared("mask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$mask", $mask))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 88, False))
	$cReturn = GetFileReturnType()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 88, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("cReturn")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$cReturn", $cReturn))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 90, False))
	for $i = 1 To UBound($av) - 1
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 90, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 91, False))
		$filePath = $av[$i]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 91, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 92, False))
		$fileContent = GetAllFromFile($filePath,$cReturn)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 92, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("fileContent")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$fileContent", $fileContent))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))
If SetError(@error, @extended, IsDeclared("cReturn")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$cReturn", $cReturn))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 93, False))
		CommentHeader($fileContent)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 93, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("fileContent")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$fileContent", $fileContent))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 94, False))
	Next
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 94, False, @error, @extended))
EndFunc




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 99, False))
Func GetPath()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 99, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 100, False))
	return $filePath
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 100, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filePath", $filePath))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 104, False))
Func GetFilterMask()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 104, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 105, False))
	return $filterMask
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 105, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("filterMask")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$filterMask", $filterMask))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 109, False))
Func CommentHeader($headerTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 109, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("headerTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTxt", $headerTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 110, False))
	Local $headerRegExp,$paramTxt, $projType, $detailsTxt, $av, $temp
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 110, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("headerRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerRegExp", $headerRegExp))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))
If SetError(@error, @extended, IsDeclared("projType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projType", $projType))
If SetError(@error, @extended, IsDeclared("detailsTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTxt", $detailsTxt))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("temp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$temp", $temp))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 111, False))
	Local $returnValue,$functionName,$comment,$result,$outputTxt
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 111, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("returnValue")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnValue", $returnValue))
If SetError(@error, @extended, IsDeclared("functionName")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionName", $functionName))
If SetError(@error, @extended, IsDeclared("comment")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$comment", $comment))
If SetError(@error, @extended, IsDeclared("result")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$result", $result))
If SetError(@error, @extended, IsDeclared("outputTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$outputTxt", $outputTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 112, False))
	If $headerTxt <> "" Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 112, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("headerTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTxt", $headerTxt))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 114, False))
		$projType       = GetProjectType()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 114, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("projType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projType", $projType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 115, False))
		$headerRegExp   = GetRegExp($projType,$HEADER_FUNCTIONS)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 115, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("headerRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerRegExp", $headerRegExp))
If SetError(@error, @extended, IsDeclared("projType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projType", $projType))
If SetError(@error, @extended, IsDeclared("HEADER_FUNCTIONS")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_FUNCTIONS", $HEADER_FUNCTIONS))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 116, False))
		$paramRegExp    = GetRegExp($projectType,$HEADER_PARAMETER)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 116, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramRegExp", $paramRegExp))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("HEADER_PARAMETER")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_PARAMETER", $HEADER_PARAMETER))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 118, False))
		$av = StringRegExp($headerTxt,$headerRegExp,3)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 118, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("headerTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTxt", $headerTxt))
If SetError(@error, @extended, IsDeclared("headerRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerRegExp", $headerRegExp))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 119, False))
		If @error = 0 Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 119, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 120, False))
			For $i = 0 To UBound($av) -1 Step $NUMBER_OF_REG_EXP_HEADER_VALUES
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 120, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_REG_EXP_HEADER_VALUES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_REG_EXP_HEADER_VALUES", $NUMBER_OF_REG_EXP_HEADER_VALUES))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 122, False))
				$temp 	       = GetTemplate($projType,$HEADER_TEMPLATE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 122, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("temp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$temp", $temp))
If SetError(@error, @extended, IsDeclared("projType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projType", $projType))
If SetError(@error, @extended, IsDeclared("HEADER_TEMPLATE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_TEMPLATE", $HEADER_TEMPLATE))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 124, False))
				$returnValue   =  GenReturn($av[$i + $RETURN_VALUE])
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 124, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("returnValue")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnValue", $returnValue))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("RETURN_VALUE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_VALUE", $RETURN_VALUE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 125, False))
				$functionName  =  GenBrief($av[$i + $FUNCTION_NAME])
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 125, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("functionName")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionName", $functionName))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("FUNCTION_NAME")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FUNCTION_NAME", $FUNCTION_NAME))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 126, False))
				$paramTxt	   =  GenParam($av[$i + $PARAMETER_LIST],$paramRegExp)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 126, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("PARAMETER_LIST")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_LIST", $PARAMETER_LIST))
If SetError(@error, @extended, IsDeclared("paramRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramRegExp", $paramRegExp))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 127, False))
				$detailsTxt	   =  GenDetails()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 127, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("detailsTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTxt", $detailsTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 128, False))
				$comment	   =  ReplaceTags($temp,$functionName,$paramTxt,$returnValue,$detailsTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 128, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("comment")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$comment", $comment))
If SetError(@error, @extended, IsDeclared("temp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$temp", $temp))
If SetError(@error, @extended, IsDeclared("functionName")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionName", $functionName))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))
If SetError(@error, @extended, IsDeclared("returnValue")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnValue", $returnValue))
If SetError(@error, @extended, IsDeclared("detailsTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTxt", $detailsTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 129, False))
				$result		   =  GenFunctionWithComment($comment,$av[$i + $RETURN_VALUE],$av[$i + $FUNCTION_NAME],$av[$i + $PARAMETER_LIST])
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 129, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("result")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$result", $result))
If SetError(@error, @extended, IsDeclared("comment")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$comment", $comment))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("RETURN_VALUE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_VALUE", $RETURN_VALUE))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("FUNCTION_NAME")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FUNCTION_NAME", $FUNCTION_NAME))
If SetError(@error, @extended, IsDeclared("av")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$av", $av))
If SetError(@error, @extended, IsDeclared("i")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$i", $i))
If SetError(@error, @extended, IsDeclared("PARAMETER_LIST")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_LIST", $PARAMETER_LIST))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 131, False))
				$outputTxt    += $result
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 131, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("outputTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$outputTxt", $outputTxt))
If SetError(@error, @extended, IsDeclared("result")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$result", $result))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 132, False))
			Next
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 132, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 133, False))
		EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 133, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 134, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 134, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 136, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 136, False, @error, @extended))
EndFunc




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 141, False))
Func GetTags($templateType)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 141, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("templateType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templateType", $templateType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 142, False))
	Local $ret
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 142, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 143, False))
	Switch $templateType
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 143, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("templateType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templateType", $templateType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 144, False))
		Case $HEADER_TEMPLATE
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 144, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("HEADER_TEMPLATE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$HEADER_TEMPLATE", $HEADER_TEMPLATE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 145, False))
			$ret = $headerTags
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 145, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
If SetError(@error, @extended, IsDeclared("headerTags")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTags", $headerTags))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 146, False))
		Case $SOURCE_TEMPLATE
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 146, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("SOURCE_TEMPLATE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SOURCE_TEMPLATE", $SOURCE_TEMPLATE))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 148, False))
		Case Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 148, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 150, False))
	EndSwitch
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 150, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 151, False))
	Return $ret
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 151, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 155, False))
Func GetRegExpParameter($regExpAv, $parameterType)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 155, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("regExpAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExpAv", $regExpAv))
If SetError(@error, @extended, IsDeclared("parameterType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$parameterType", $parameterType))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 156, False))
	Return $regExpAv[$parameterType]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\Functions.au3", "Functions.au3", 156, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("regExpAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$regExpAv", $regExpAv))
If SetError(@error, @extended, IsDeclared("parameterType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$parameterType", $parameterType))
EndFunc
