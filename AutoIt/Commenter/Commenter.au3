#include-once
#include <FileConstants.au3>
#include <File.au3>
#include "Ini.au3"
#include "Globals.au3"


Global $path = ""
Global $recurSearch = $FLTAR_RECUR
Global $retPath = $FLTAR_RELPATH
Global $filter = "*.c"

Init()


Main()


DeInit()



Func Init()


EndFunc


Func Main()

	_FileListToArrayRec($path,$filter,$FLTAR_FILES,$recurSearch,$FLTAR_SORT,)


EndFunc


Func DeInit()


EndFunc

