#include-once
#include <File.au3>
#include <Array.au3>
#include "Globals.au3"


Func GetAllFromFile($path,$retType)
	Local $ret
	If $retType = $RETURN_AS_ARRAY Then
		$ret = GetAllFromFileToArray($path)
		SetError(@error)
	ElseIf $retType = $RETURN_AS_STRING Then
		$ret = GetAllFromFileToString($path)
		SetError(@error)
	Else
		SetError(-1)
		$ret = -1
	EndIf
	Return $ret
EndFunc

Func GetAllFromFileToString($path)
	Local $data, $hndl, $error

	$hndl = FileOpen($path,$FO_READ)
	$error = @error

	If Not $error Then
		$data = FileRead($hndl)
		SetError(@error,@extended)
		FileClose($hndl)
	Else
		SetError($error)
	EndIf

	Return $data
EndFunc


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




;~ Func LineRegExp($txt,$regExp)
;~ 	Local $av, $error
;~ 	$regExp = GetRegExp($regExp)
;~ 	$av = StringRegExp($txt,$regExp,3)
;~ 	$error = @error

;~ 	If $error <> 0 Then
;~ 		$av = -1
;~ 	EndIf

;~ 	SetError($error)
;~ 	return $av
;~ EndFunc

Func GetRegExp($projectType,$regExpType)
	Local $ret = -1
	If $regExpType < $NUMBER_OF_REG_EXP Then
		$ret = $regExp[$projectType][$regExpType]
	EndIf
	Return $ret
EndFunc


Func GetProjectType()
	Return $projectType
EndFunc

Func GetFileReturnType()
	Return $fileReturnType
EndFunc


Func GetAllFileToAv($filePath, $filterMask)
	return _FileListToArrayRec($filePath,$filterMask,$FLTAR_FILES,$FLTAR_RECUR,$FLTAR_SORT,$FLTAR_FULLPATH )
EndFunc

Func MainTask()
	Local $av, $mask
	Local $path, $filePath
	Local $fileContent,$contentReturn
	Local $project,$regExp

	$path = GetPath()
	$mask = GetFilterMask
	$av = GetAllFileToAv($path,$mask)
	$cReturn = GetFileReturnType()
	$project = GetProjectType()

	for $i = 0 To UBound($av) - 1
		$filePath = $av[$i]
		$fileContent = GetAllFromFile($filePath,$cReturn)

		$regExp =
		GetRegExp()


	Next
EndFunc



Func GetPath()
	return $filePath
EndFunc


Func GetFilterMask()
	return $filterMask
EndFunc