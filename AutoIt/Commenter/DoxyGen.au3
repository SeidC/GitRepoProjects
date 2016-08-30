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

Func GenParam(ByRef $paramTxt, $paramRegExp = "")

	Local $params,$$paramTemp

	If $paramRegExp <> "" Then
		$params = StringRegExp($paramTxt, $paramRegExp,3)
	Else If IsArray($paramTxt)
		$params = $paramTxt
	Else
		ReDim $param[1]
		$param[0] = ""
	EndFunc

	For $j = 1 To UBound($params) - 1
		$paramTemp = $paramTag & " " & $params " " & " Parameter Description"  & @CRLF
	Next
	Return $paramTemp
EndFunc


Func GenReturn($returnTxt = "")
	Return $returnTag & " " &  $returnTxt
EndFunc


Func GenDetails($detailTxt = "")
	$detailsTag & " " & $detailTxt
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