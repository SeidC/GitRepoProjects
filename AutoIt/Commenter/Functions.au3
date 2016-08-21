#include-once
#include <FileConstants.au3>
#include <File.au3>


Func GetAllFromFileToArray($path)
	Local $dataAv, $hndl

	$hndl = FileOpen($av[$i],$FO_READ)
	$dataAv = FileReadToArray($hndl)

	SetError(@error,@extended)
	FileClose($hndl)

	return $dataAv
EndFunc



Func CommentFiles(ByRef $files)
	Local $dataAv, $path
	For $i to UBound($files) - 1
		$path   = $files[$i]
		$dataAv = GetAllFromFileToArray($path)


	Next
EndFunc


Func VerifyCodeLines($lineTxt,$type)
	Local $av,$error,$regExp
	$regExp = GetRegExp($type)
	$av = StringRegExp($lineTxt,$regExp,3)
	$error = @error

	If $error <> 0 Then
		$av = -1
	EndIf

	SetError($error)
	return $av
EndFunc


Func CheckCodeData(ByRef $dAv)
	If IsArray($dataAv) Then
		For $i = 0 To UBound($dAv) - 1


		Next
	Else

	EndIf
EndFunc


Func GetRegExpt($type)
	Return ""
EndFunc