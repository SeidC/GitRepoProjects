#include-once
#include <FileConstants.au3>
#include <File.au3>
#include <Array.au3>
#include "Ini.au3"
#include "Globals.au3"


Global $path = "Z:\Projekte\Projects\AVR\Test\"
Global $recurSearch = $FLTAR_RECUR
Global $retPath = $FLTAR_RELPATH
Global $filter = "*.cpp"

Init()


Main()


DeInit()



Func Init()


EndFunc


Func Main()

	Local $av = _FileListToArrayRec($path,$filter,$FLTAR_FILES,$recurSearch,$FLTAR_SORT,$retPath)
	ConsoleWrite("Av: " & @extended & @CRLF)
	_ArrayDisplay($av)

EndFunc


Func DeInit()


EndFunc

