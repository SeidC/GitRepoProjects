#include-once
#include <FileConstants.au3>
#include <File.au3>


Func GetDataFromFileToArray($path)
	Local $dataAv, $hndl

	$hndl = FileOpen($av[$i],$FO_READ)
	$dataAv = FileReadToArray($hndl)

	SetError(@error,@extended)
	FileClose($hndl)

	return $dataAv
EndFunc



Func CommentFiles(ByRef files)
	Local $dataAv, $path
	For $i to UBound($files) - 1
		$path   = $files[$i]
		$dataAv = GetDataFromFileToArray($path)


	Next
EndFunc