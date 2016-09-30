#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_Compile_Both=y
#AutoIt3Wrapper_UseX64=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****
#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include <GuiEdit.au3>
#include <File.au3>
#include <FileConstants.au3>
#include <Array.au3>
#include <GuiStatusBar.au3>
#include "Output.au3"

#Region ### START Koda GUI section ### Form=d:\projekte\autoit\file.kxf
$Form1_1 = GUICreate("Find...", 493, 185, 192, 133)
$SearchEdit = GUICtrlCreateInput("", 128, 24, 273, 24)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$Label1 = GUICtrlCreateLabel("Search Path:", 8, 24, 91, 20, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$SearchButton = GUICtrlCreateButton("...", 408, 24, 75, 25)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$StringLine = GUICtrlCreateInput("", 128, 56, 273, 24, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT))
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$String = GUICtrlCreateLabel("String To Search:", 8, 56, 122, 20, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$StatusBar1 = _GUICtrlStatusBar_Create($Form1_1)
Dim $StatusBar1_PartsWidth[2] = [300, -1]
_GUICtrlStatusBar_SetParts($StatusBar1, $StatusBar1_PartsWidth)
_GUICtrlStatusBar_SetText($StatusBar1, @TAB & @TAB & "", 0)
_GUICtrlStatusBar_SetText($StatusBar1, @TAB & "", 1)
$StartButton = GUICtrlCreateButton("Start", 408, 64, 75, 89)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$OpenOutputButton = GUICtrlCreateButton("Output", 328, 88, 75, 65)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$Label2 = GUICtrlCreateLabel("File Filter:", 8, 88, 70, 20, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$FiterEdit = GUICtrlCreateInput("*.c;*.h", 128, 88, 193, 24, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT))
GUICtrlSetFont(-1, 8, 800, 0, "Verdana")
GUISetState(@SW_SHOW,$Form1_1)
#EndRegion ### END Koda GUI section ###

Opt("GUIOnEventMode", 1)

Global $av
Global $searchPath
Global $start = False
Global $avCount
Global $string
Global $status = False
Global $fCount

GUICtrlSetPos($Form1_1,0.0)

GUISetOnEvent($GUI_EVENT_CLOSE, "CloseApp")
GUICtrlSetOnEvent($OpenOutputButton, "ShowOutput")
GUICtrlSetOnEvent($SearchButton,"OpenSearchDialog")
GUICtrlSetOnEvent($StartButton,"StartApp")

While 1
	If $start = True Then
		$status = Search($string)
		If $status = -2 Then			; Array index out of bound
			_GUICtrlEdit_AppendText($Output,@CRLF & "Finished" & @CRLF)
			$start = False
		ElseIf $status = -1 Then		; Not started
			$start = False
		ElseIf $status = 0 Then			; Nothing found

		Else							; Found
			WriteNextData($av[$fCount])
		EndIf
	EndIf
WEnd


Func Start()
	Local $path, $searchString
	$path =  _GUICtrlEdit_GetText ( $SearchEdit )
	If $path <> "" Then
		Return $path
	EndIf
	Return -1
EndFunc


Func FilterData($path)
	Local $filter = GetFilter()
	return _FileListToArrayRec($path,$filter,$FLTAR_FILES,$FLTAR_RECUR,$FLTAR_NOSORT,$FLTAR_FULLPATH)
EndFunc


Func Search($string)
	Local $hndl, $fileData, $ret, $return, $pos, $file, $percentValue

	If $start = True Then
		If $avCount < UBound($av) -1 Then
			$pos = StringInStr($av[$avCount],"\",0,-1)
			$file = StringMid($av[$avCount],$pos + 1)
			$fileData = GetFileData($av[$avCount])
			$ret      = StringInStr($fileData,$string)
			$fCount = $avCount
			$avCount += 1
			$return =  $ret
			$percentValue = CalculatePercent($avCount,UBound($av))
			UpdateStatusBar($av[$avCount],$percentValue)
		Else
			$return =  -2
		EndIf
	Else
		UpdateStatusBar("","100")
		$return =  -1
	EndIf
	return $return
EndFunc


Func CloseApp()
	Exit
EndFunc

Func StartApp()
	$searchPath = Start()
	$string = _GUICtrlEdit_GetText ( $StringLine )
	If $searchPath <> "" And $string <> "" And $start = False Then
		UpdateStatusBar("Seek Started, Please Wait...","0")
		WriteStartUpInfo($searchPath)
		$av = FilterData($searchPath)
		$start = True
		$avCount = 0
	Else
		If $searchPath = "" Then

		ElseIf $string = "" Then

		Else

		EndIf
	EndIf
EndFunc

Func ShowOutput()
	GUISetState(@SW_SHOW ,$Form1)
EndFunc


Func OpenSearchDialog()
	Local $pth = FileSelectFolder("Select Folder to Search","")
	If $pth <> "" Then
		_GUICtrlEdit_SetText($SearchEdit,$pth)
	EndIf
EndFunc

Func GetFileData($path)
	Local $hndl     = FileOpen($path, $FO_READ )
	Local $outputData = FileRead($hndl)
	FileClose($hndl)
	Return $outputData
EndFunc

Func GetFilter()
	return _GUICtrlEdit_GetText($FiterEdit)
EndFunc

Func CalculatePercent($curValue,$maxValue)
	Local $value
	$value = ($curValue/$maxValue * 100)
	Return Int($value)
EndFunc


Func UpdateStatusBar($message,$percent = "")
	Local $percentTxt

	If $percent <> "" Then
		$percentTxt = $percent & "%"
	EndIf

	_GUICtrlStatusBar_SetText($StatusBar1,$message)
	_GUICtrlStatusBar_SetText($StatusBar1,$percentTxt,1)
EndFunc