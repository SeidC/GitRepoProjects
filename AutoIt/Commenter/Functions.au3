#include-once
#include <File.au3>
#include <Array.au3>
#include "Globals.au3"


Func GetAllFromFileToArray($path)
	Local $dataAv, $hndl, $error

	$hndl = FileOpen($path,$FO_READ)
	$error = @error

	If Not $error Then
		$dataAv = FileReadToArray($hndl)
		SetError(@error,@extended)
		FileClose($hndl)
	Else
		SetError($error)
	EndIf

	Return $dataAv
EndFunc



Func CommentFiles(ByRef $files)
	Local $dataAv, $path
	For $i = 1 To UBound($files) - 1
		$path   = $files[$i]
		$dataAv = GetAllFromFileToArray($path)
		CheckCodeData($dataAv)
	Next
EndFunc


Func VerifyCodeLines($lineTxt,$type)
	Local $av, $res

	Switch($type)
		Case $HEADER_FUNCTIONS
			$av = VerifyHeader($lineTxt)
			_ArrayAdd($res,$av)
			;--- Add Verification for Parameter ---
		Case Else

	EndSwitch

EndFunc


Func CheckCodeData(ByRef $dAv)
	If IsArray($dAv) Then
		For $i = 0 To UBound($dAv) - 1


		Next
	Else

	EndIf
EndFunc

Func VerifyHeader($lineTxt)
	Local $av
	$av = LineRegExp($lineTxt,$HEADER_FUNCTIONS)
	SetError(@error)
	return $av
EndFunc

Func VerifyCodeParameter($paramLst)
	Local $av
	$av = LineRegExp($paramLst,$HEADER_PARAMETER)
	SetError(@error)
	return $av
EndFunc

Func LineRegExp($txt,$regExp)
	Local $av, $error
	$regExp = GetRegExp($regExp)
	$av = StringRegExp($txt,$regExp,3)
	$error = @error

	If $error <> 0 Then
		$av = -1
	EndIf

	SetError($error)
	return $av
EndFunc

Func GetRegExp($type)
	Local $ret = -1
	If $type < $NUMBER_OF_REG_EXP Then
		$ret = $regExp[$type]
	EndIf
	Return $ret
EndFunc