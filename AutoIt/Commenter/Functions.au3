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


	$path = GetPath()
	$mask = GetFilterMask()
	$av = GetAllFileToAv($path,$mask)
	$cReturn = GetFileReturnType()

	for $i = 0 To UBound($av) - 1
		$filePath = $av[$i]
		$fileContent = GetAllFromFile($filePath,$cReturn)
		CommentHeader($fileContent)
	Next
EndFunc



Func GetPath()
	return $filePath
EndFunc


Func GetFilterMask()
	return $filterMask
EndFunc


Func CommentHeader($headerTxt)
	Local $headerRegExp,$params, $projType, $av, $temp
	Local $tag, $paramAv
	If $headerTxt <> "" Then

		$projType       = GetProjectType()
		$headerRegExp   = GetRegExp($projType,$HEADER_FUNCTIONS)
		$temp 	        = GetTemplate($projType,$HEADER_TEMPLATE)

		$av = StringRegExp($headerTxt,$header,3)
		If @error = 0 Then
			For $i = 0 To UBound($av) -1


			Next
		EndIf
	Else

	EndIf
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

Func GetTags($templateType)
	Local $ret
	Switch $templateType
		Case $HEADER_TEMPLATE
			$ret = $headerTags
		Case $SOURCE_TEMPLATE

		Case Else

	EndSwitch
	Return $ret
EndFunc


Func GetRegExpParameter($regExpAv, $parameterType)
	Return $regExpAv[$parameterType]
EndFunc