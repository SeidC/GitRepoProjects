#include <File.au3>
#include <Array.au3>
#include "DoxyGen.au3"


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

	for $i = 1 To UBound($av) - 1
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
	Local $headerRegExp,$paramTxt, $projType, $detailsTxt, $av, $temp
	Local $tag
	Local $returnValue,$functionName,$comment,$result
	If $headerTxt <> "" Then

		$projType       = GetProjectType()
		$headerRegExp   = GetRegExp($projType,$HEADER_FUNCTIONS)
		$paramRegExp    = GetRegExp($projectType,$HEADER_PARAMETER)

		$av = StringRegExp($headerTxt,$headerRegExp,3)
		If @error = 0 Then
			For $i = 0 To UBound($av) -1 Step $NUMBER_OF_REG_EXP_HEADER_VALUES

				$temp 	       = GetTemplate($projType,$HEADER_TEMPLATE)

				$returnValue   =  GenReturn($av[$i + $RETURN_VALUE])
				$functionName  =  GenBrief($av[$i + $FUNCTION_NAME])
				$paramTxt	   =  GenParam($av[$i + $PARAMETER_LIST],$paramRegExp)
				$detailsTxt	   =  GenDetails()			   
				$comment	   =  ReplaceTags($temp,$functionName,$paramTxt,$returnValue,$detailsTxt)
				$result		  &=  GenFunctionWithComment($comment,$av[$i + $RETURN_VALUE],$av[$i + $FUNCTION_NAME],$av[$i + $PARAMETER_LIST],$paramRegExp)
			Next
		EndIf
	Else

	EndIf
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