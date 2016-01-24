#include-once
#include <GuiListView.au3>
#include <GuiEdit.au3>
#include "ImageLoaderGui.au3"
#include "ImageLoaderIf.au3"



;--- Global Params --------------------------------------------------------------
Global $backUpClipStr = ""
Global $mainCycleTime = 500

;--- Application ----------------------------------------------------------------

Init()


Main()



;--- Functions -----------------------------------------------------------------

; #FUNCTION# ====================================================================================================================
; Name ..........: Init
; Description ...:
; Syntax ........: Init()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func Init()

	SetUpGuiEvents()
	AddListViewColums()
	SetDefaults()
	SetCycleTime(250)


	StartGUI()
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: Main
; Description ...:
; Syntax ........: Main()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func Main()

	While (1)
		MainCycleTasks()
		Sleep ($mainCycleTime)
	WEnd
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: AddListViewColums
; Description ...:
; Syntax ........: AddListViewColums()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func AddListViewColums()

	_GUICtrlListView_AddColumn($DataList, "Name", 200)
	_GUICtrlListView_AddColumn($DataList, "Image", 100)
	_GUICtrlListView_AddColumn($DataList, "Search Settings", 100)
	_GUICtrlListView_AddColumn($DataList, "Name", 100)
	_GUICtrlListView_AddColumn($DataList, "Progress", 100)

EndFunc



; #FUNCTION# ====================================================================================================================
; Name ..........: StartGUI
; Description ...:
; Syntax ........: StartGUI()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func StartGUI()
	GUISetState(@SW_SHOW,$ImageLoader)
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: SetUpGuiEvents
; Description ...:
; Syntax ........: SetUpGuiEvents()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func SetUpGuiEvents()
	;Set Event Mode
	Opt("GUIOnEventMode", 1)

	; System Events
	GUISetOnEvent($GUI_EVENT_CLOSE, "ExitExec")


	; GUI Events
	GUICtrlSetOnEvent($ExitButton  , "ExitExec")
	GUICtrlSetOnEvent($AddButton   , "AddToList")
	GUICtrlSetOnEvent($DeleteButton, "DeleteFromList")
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: MainCycleTasks
; Description ...:
; Syntax ........: MainCycleTasks()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func MainCycleTasks()

	HandleClipBoard()
	StatusMessageTask()
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: HandleClipBoard
; Description ...:
; Syntax ........: HandleClipBoard()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func HandleClipBoard()
	Local $clipStr = ClipGet()
	If @error = 0 Then
		If $clipStr <> $backUpClipStr Then
			If IsUrl($clipStr) Then
				_GUICtrlEdit_SetText ( $UrlInput		, $clipStr )
				_GUICtrlEdit_SetText ( $ModifiedUrlInput, $clipStr )
				$backUpClipStr = $clipStr
			EndIf
		EndIf
	EndIf
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: SetCycleTime
; Description ...:
; Syntax ........: SetCycleTime($iTimeMs)
; Parameters ....: $iTimeMs             - an integer value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func SetCycleTime($iTimeMs)
	$mainCycleTime = $iTimeMs
EndFunc


Func SetDefaults()
	_GUICtrlEdit_SetText($ParameterInput1,'<x>')
	_GUICtrlEdit_SetText($ParameterInput2,'<y>')

	_GUICtrlEdit_SetText($FromToInput1,'1 to 99')
	_GUICtrlEdit_SetText($FromToInput2,'1 to 99')

EndFunc

Func AddDataToListView($sUrl,$sSettings)
	Local $index
	Local $sUrlName, $avUrlLinks, $iUrlLinksRet
	If $sUrl <> "" And $sSettings <> "" Then
;~ 		$index	= _GUICtrlListView_AddItem ($DataList, $sUrl)
;~ 		_GUICtrlListView_AddSubItem   			($DataList, $index, " ----- ", 1 )
;~ 		_GUICtrlListView_AddSubItem   			($DataList, $index, $sSettings       , 2 )
		$sUrlName = GetName($sUrl)
		$iUrlLinksRet = GetLinks($sUrl,$avUrlLinks)


	Else
		_GUICtrlStatusBar_SetText($StatusBar, "")
	Endif
EndFunc


Func DeleteEntryFromList()
	Local $index, $avIndex, $msgBoxRet

	$index =_GUICtrlListView_GetSelectedIndices($DataList)
	If $index <> "" Then
		$avIndex = StringSplit($index,'|')
		$msgBoxRet = MsgBox(BitOR($MB_YESNO,$MB_ICONQUESTION),"Delete Objects","Do you want to delete " & $avIndex[0] & " Objects?", 10)
		If $msgBoxRet = $IDYES Then
			_GUICtrlListView_DeleteItemsSelected ($DataList)
		Else
			; Add Status Message
		EndIf
	EndIf
EndFunc

Func SetStatusBarMessage($message)


EndFunc

Func StatusMessageTask()


EndFunc



;--- Gui Events -------------------------

Func ExitExec()


	Exit
EndFunc


Func AddToList()
	Local $url = _GUICtrlEdit_GetText($ModifiedUrlInput)
	Local $settings  = _GUICtrlEdit_GetText($ParameterInput1) & "= " & _GUICtrlEdit_GetText($FromToInput1) & @CRLF
		  $settings &= " | "
		  $settings &= _GUICtrlEdit_GetText($ParameterInput2) & "= " & _GUICtrlEdit_GetText($FromToInput2)

	AddDataToListView($url,$settings)

EndFunc


Func DeleteFromList()

	DeleteEntryFromList()
EndFunc