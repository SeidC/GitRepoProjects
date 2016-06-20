#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_Change2CUI=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

#include <File.au3>
#include <Array.au3>

Global $loadPath = "W:\Movies"
Global $savePath = "C:\Users\AP\Desktop"
Global $dbName   = "Dat.txt"
Global $type 	= "*.mkv"
Global $av

If PathCheck($loadPath) Then
	If PathCheck($savePath) Then
		$av = GetData($loadPath)
		WriteDb($savePath,$av)
	EndIf
EndIf



Func EnterPath(ByRef $storeParam, $msgToShow)

	ConsoleWrite($msgToShow & @CRLF)
	While 1
		$storeParam = ConsoleRead(TRUE)

		If @extended > 0 Then
			ExitLoop
		EndIf
	WEnd
EndFunc


Func PathCheck($path)
	If FileExists($path) Then
		Return TRUE
	Else
		ConsoleWrite("Path: " &@CRLF & $path & @CRLF & "does not exist" & @CRLF)
		Return FALSE
	EndIf
EndFunc


Func GetData($path)
		return _FileListToArrayRec($path, $type, $FLTAR_FILES, $FLTAR_RECUR, $FLTAR_SORT)
EndFunc


Func WriteDb($savePath, ByRef $db)
	Local $hndl = FileOpen($savePath & "\" & $dbName,1)
	For $i = 0 To UBound($db) - 1
		FileWrite($hndl,$db[$i] & @CRLF)
	Next
	FileClose($hndl)
EndFunc