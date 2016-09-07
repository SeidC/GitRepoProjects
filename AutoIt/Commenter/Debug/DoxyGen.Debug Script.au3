AutoIt_Debugger_LoadFile("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3")
AutoIt_Debugger_DebugFile(@ScriptFullPath)

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 1, False))
#include-once
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 1, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 2, False))
#Include "Z:\Projekte\Projects\AutoIt\Commenter\Debug\Globals.Debug Script.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 2, False, @error, @extended))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 5, False))
Global $doxyGenSign	= '@'
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 5, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("doxyGenSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$doxyGenSign", $doxyGenSign))




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 9, False))
Global $briefTag   = $doxyGenSign & 'brief'
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 9, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("briefTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$briefTag", $briefTag))
If SetError(@error, @extended, IsDeclared("doxyGenSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$doxyGenSign", $doxyGenSign))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 10, False))
Global $paramTag   = $doxyGenSign & 'param [in]'
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 10, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTag", $paramTag))
If SetError(@error, @extended, IsDeclared("doxyGenSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$doxyGenSign", $doxyGenSign))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 11, False))
Global $returnTag  = $doxyGenSign & 'return'
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 11, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("returnTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnTag", $returnTag))
If SetError(@error, @extended, IsDeclared("doxyGenSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$doxyGenSign", $doxyGenSign))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 12, False))
Global $detailsTag = $doxyGenSign & 'details'
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 12, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("detailsTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTag", $detailsTag))
If SetError(@error, @extended, IsDeclared("doxyGenSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$doxyGenSign", $doxyGenSign))



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 15, False))
Func GenBrief($briefTxt= "")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 15, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("briefTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$briefTxt", $briefTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 16, False))
	Return $briefTag & " " & $briefTxt
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 16, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("briefTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$briefTag", $briefTag))
If SetError(@error, @extended, IsDeclared("briefTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$briefTxt", $briefTxt))
EndFunc


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 19, False))
Func GenParam($paramTxt, $paramRegExp = "")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 19, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))
If SetError(@error, @extended, IsDeclared("paramRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramRegExp", $paramRegExp))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 21, False))
	Local $params,$paramTemp = "",$commentSign = ""
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 21, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))
If SetError(@error, @extended, IsDeclared("paramTemp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTemp", $paramTemp))
If SetError(@error, @extended, IsDeclared("commentSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$commentSign", $commentSign))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 23, False))
	If $paramRegExp <> "" Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 23, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramRegExp", $paramRegExp))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 24, False))
		$params = StringRegExp($paramTxt, $paramRegExp,3)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 24, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))
If SetError(@error, @extended, IsDeclared("paramRegExp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramRegExp", $paramRegExp))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 25, False))
	ElseIf IsArray($paramTxt) Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 25, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 26, False))
		$params = $paramTxt
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 26, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 27, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 27, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 28, False))
		ReDim $params[1]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 28, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 29, False))
		$params[0] = ""
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 29, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 30, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 30, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 32, False))
	For $j = 1 To UBound($params) - 1 Step 2
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 32, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("j")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$j", $j))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 33, False))
		If $j > 1 Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 33, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("j")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$j", $j))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 34, False))
			$commentSign = " * "
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 34, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("commentSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$commentSign", $commentSign))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 35, False))
		EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 35, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 36, False))
		$paramTemp &= $commentSign & $paramTag & " " & $params[$j] & " " & " Parameter Description"  & @CRLF
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 36, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramTemp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTemp", $paramTemp))
If SetError(@error, @extended, IsDeclared("commentSign")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$commentSign", $commentSign))
If SetError(@error, @extended, IsDeclared("paramTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTag", $paramTag))
If SetError(@error, @extended, IsDeclared("params")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$params", $params))
If SetError(@error, @extended, IsDeclared("j")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$j", $j))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 37, False))
	Next
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 37, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 38, False))
	Return $paramTemp
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 38, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("paramTemp")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTemp", $paramTemp))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 42, False))
Func GenReturn($returnTxt = "")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 42, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("returnTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnTxt", $returnTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 43, False))
	Return $returnTag & " " &  $returnTxt
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 43, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("returnTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnTag", $returnTag))
If SetError(@error, @extended, IsDeclared("returnTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnTxt", $returnTxt))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 47, False))
Func GenDetails($detailTxt = "")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 47, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("detailTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailTxt", $detailTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 48, False))
	Return $detailsTag & " " & $detailTxt
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 48, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("detailsTag")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTag", $detailsTag))
If SetError(@error, @extended, IsDeclared("detailTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailTxt", $detailTxt))
EndFunc




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 53, False))
Func GetTemplate($projectType,$template)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 53, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 54, False))
	Local $tempPath,$templateData, $hndl, $ret, $error
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 54, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("tempPath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$tempPath", $tempPath))
If SetError(@error, @extended, IsDeclared("templateData")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templateData", $templateData))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 56, False))
 	If $projectType < $NUMBER_OF_PROJECT_TYPES And 	   $template < $NUMBER_OF_TEMPLATES        Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 56, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_PROJECT_TYPES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_PROJECT_TYPES", $NUMBER_OF_PROJECT_TYPES))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("NUMBER_OF_TEMPLATES")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$NUMBER_OF_TEMPLATES", $NUMBER_OF_TEMPLATES))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 59, False))
			$tempPath = GetTemplatePath() & "\" & $templates[$projectType][$template]
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 59, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("tempPath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$tempPath", $tempPath))
If SetError(@error, @extended, IsDeclared("templates")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templates", $templates))
If SetError(@error, @extended, IsDeclared("projectType")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$projectType", $projectType))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 60, False))
			$hndl = FileOpen($tempPath,$FO_READ)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 60, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))
If SetError(@error, @extended, IsDeclared("tempPath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$tempPath", $tempPath))
If SetError(@error, @extended, IsDeclared("FO_READ")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FO_READ", $FO_READ))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 61, False))
			$ret = FileRead($hndl)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 61, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 62, False))
			$error = @error
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 62, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 63, False))
			FileClose($hndl)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 63, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("hndl")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$hndl", $hndl))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 64, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 64, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 65, False))
		$ret = -1
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 65, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 66, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 66, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 67, False))
	SetError($error)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 67, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("error")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$error", $error))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 68, False))
	Return $ret
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 68, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("ret")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ret", $ret))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 72, False))
Func GetTemplatePath()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 72, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 73, False))
	Return $templatePath
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 73, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("templatePath")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$templatePath", $templatePath))
EndFunc



SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 77, False))
Func ReplaceTags($template, $briefTxt, $paramTxt, $returnTxt, $detailsTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 77, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("briefTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$briefTxt", $briefTxt))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))
If SetError(@error, @extended, IsDeclared("returnTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnTxt", $returnTxt))
If SetError(@error, @extended, IsDeclared("detailsTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTxt", $detailsTxt))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 79, False))
	$template =  StringReplace($template,$headerTagsAv[$FUNCTION_TAG],$briefTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 79, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("headerTagsAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTagsAv", $headerTagsAv))
If SetError(@error, @extended, IsDeclared("FUNCTION_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$FUNCTION_TAG", $FUNCTION_TAG))
If SetError(@error, @extended, IsDeclared("briefTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$briefTxt", $briefTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 80, False))
	$template = StringReplace($template,$headerTagsAv[$PARAMETER_TAG],$paramTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 80, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("headerTagsAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTagsAv", $headerTagsAv))
If SetError(@error, @extended, IsDeclared("PARAMETER_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$PARAMETER_TAG", $PARAMETER_TAG))
If SetError(@error, @extended, IsDeclared("paramTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$paramTxt", $paramTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 81, False))
	$template = StringReplace($template,$headerTagsAv[$RETURN_TAG],$returnTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 81, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("headerTagsAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTagsAv", $headerTagsAv))
If SetError(@error, @extended, IsDeclared("RETURN_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$RETURN_TAG", $RETURN_TAG))
If SetError(@error, @extended, IsDeclared("returnTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnTxt", $returnTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 82, False))
	$template = StringReplace($template,$headerTagsAv[$DETAILED_TAG],$detailsTxt)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 82, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
If SetError(@error, @extended, IsDeclared("headerTagsAv")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$headerTagsAv", $headerTagsAv))
If SetError(@error, @extended, IsDeclared("DETAILED_TAG")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$DETAILED_TAG", $DETAILED_TAG))
If SetError(@error, @extended, IsDeclared("detailsTxt")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$detailsTxt", $detailsTxt))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 83, False))
	return $template
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 83, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("template")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$template", $template))
EndFunc


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 86, False))
Func GenFunctionWithComment($functionComment,$returnValus, $functionName, $parameterList)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 86, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("functionComment")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionComment", $functionComment))
If SetError(@error, @extended, IsDeclared("returnValus")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnValus", $returnValus))
If SetError(@error, @extended, IsDeclared("functionName")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionName", $functionName))
If SetError(@error, @extended, IsDeclared("parameterList")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$parameterList", $parameterList))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 87, False))
	Return $functionComment & @CRLF & $returnValus & " " & $functionName &  $parameterList & ";" & @CRLF & @CRLF
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Commenter\DoxyGen.au3", "DoxyGen.au3", 87, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("functionComment")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionComment", $functionComment))
If SetError(@error, @extended, IsDeclared("returnValus")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$returnValus", $returnValus))
If SetError(@error, @extended, IsDeclared("functionName")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$functionName", $functionName))
If SetError(@error, @extended, IsDeclared("parameterList")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$parameterList", $parameterList))
EndFunc
