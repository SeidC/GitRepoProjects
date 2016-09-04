#include-once
#include "Globals.au3"


Global $doxyGenSign	= '@'



Global $briefTag   = $doxyGenSign & 'brief'
Global $paramTag   = $doxyGenSign & 'param [in]'
Global $returnTag  = $doxyGenSign & 'return'
Global $detailsTag = $doxyGenSign & 'details'


Func GenBrief($briefTxt= "")
	Return $briefTag & " " & $briefTxt
EndFunc

Func GenParam($paramTxt, $paramRegExp = "")

	Local $params,$paramTemp = "",$commentSign = ""

	If $paramRegExp <> "" Then
		$params = StringRegExp($paramTxt, $paramRegExp,3)
	ElseIf IsArray($paramTxt) Then
		$params = $paramTxt
	Else
		ReDim $params[1]
		$params[0] = ""
	EndIf

	For $j = 1 To UBound($params) - 1 Step 2
		If $j > 1 Then 
			$commentSign = " * "
		EndIf
		$paramTemp &= $commentSign & $paramTag & " " & $params[$j] & " " & " Parameter Description"  & @CRLF
	Next
	Return $paramTemp
EndFunc


Func GenReturn($returnTxt = "")
	Return $returnTag & " " &  $returnTxt
EndFunc


Func GenDetails($detailTxt = "")
	Return $detailsTag & " " & $detailTxt
EndFunc



Func GetTemplate($projectType,$template)
	Local $tempPath,$templateData, $hndl, $ret, $error

	If $projectType < $NUMBER_OF_PROJECT_TYPES And _
	   $template < $NUMBER_OF_TEMPLATES        Then

			$tempPath = GetTemplatePath() & "\" & $templates[$projectType][$template]
			$hndl = FileOpen($tempPath,$FO_READ)
			$ret = FileRead($hndl)
			$error = @error
			FileClose($hndl)
	Else
		$ret = -1
	EndIf
	SetError($error)
	Return $ret
EndFunc


Func GetTemplatePath()
	Return $templatePath
EndFunc


Func ReplaceTags($template, $briefTxt, $paramTxt, $returnTxt, $detailsTxt)
	
	$template =  StringReplace($template,$headerTagsAv[$FUNCTION_TAG],$briefTxt)
	$template = StringReplace($template,$headerTagsAv[$PARAMETER_TAG],$paramTxt)
	$template = StringReplace($template,$headerTagsAv[$RETURN_TAG],$returnTxt)
	$template = StringReplace($template,$headerTagsAv[$DETAILED_TAG],$detailsTxt)
	return $template
EndFunc

Func GenFunctionWithComment($functionComment,$returnValus, $functionName, $parameterList)
	Return $functionComment & @CRLF & $returnValus & " " & $functionName &  $parameterList & ";" & @CRLF 
EndFunc