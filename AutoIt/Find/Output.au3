#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <WindowsConstants.au3>


#Region ### START Koda GUI section ### Form=D:\Projekte\AutoIT\Output.kxf
$Form1 = GUICreate("Output...", 484, 322, 346, 262)
$GroupBox1 = GUICtrlCreateGroup("", 10, 1, 365, 310)
$Output = GUICtrlCreateEdit("", 16, 16, 353, 289)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
GUICtrlCreateGroup("", -99, -99, 1, 1)
$CloseWindowButton = GUICtrlCreateButton("&Close", 384, 18, 92, 31)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$CopyButton = GUICtrlCreateButton("&Copy", 384, 50, 91, 31)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
GUISetState(@SW_HIDE ,$Form1)
#EndRegion ### END Koda GUI section ###

Opt("GUIOnEventMode", 1)

GUISetOnEvent($GUI_EVENT_CLOSE, "HideOutput")
GUICtrlSetOnEvent($CloseWindowButton, "HideOutput")
GUICtrlSetOnEvent($CopyButton, "CopyData")

Func HideOutput()
	GUISetState(@SW_HIDE ,$Form1)
EndFunc


Func CopyData()

EndFunc


Func WriteNextData($data)
	_GUICtrlEdit_AppendText($Output,"In File: " & $data &@CRLF)
EndFunc

Func WriteStartUpInfo($info)
	_GUICtrlEdit_SetText($Output,"")
	_GUICtrlEdit_SetText($Output,"Search Path: ")
	_GUICtrlEdit_AppendText($Output,$info & @CRLF)
	_GUICtrlEdit_AppendText($Output,"====================================================" & @CRLF & @CRLF)
EndFunc