#include-once
#include <GuiListView.au3>
#include <GuiEdit.au3>
#include "ImageLoaderGui.au3"
#include "ImageLoaderIf.au3"



;--- Global Params --------------------------------------------------------------
Global $backUpClipStr = ""
Global $mainCycleTime = 500
Global Const $listColumns[4][2] = 	[					   _
										["Name"    , 200] , _
                                        ["Images"  ,  75] , _
                                        ["URL"     , 100] , _
                                        ["Progress", 100]   _
									]

Global Enum $MAIN_ITEM = 0
			$SUB_ITEM  = 1
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

	For $i = 0 To UBound($listColumns) - 1
		_GUICtrlListView_AddColumn($DataList, $listColumns[$i][0]    , $listColumns[$i][1])
	Next

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
	GUICtrlSetOnEvent($FolderButton, "ChooseFolder")
	GUICtrlSetOnEvent($StartButton , "StartDownload")
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

; #FUNCTION# ====================================================================================================================
; Name ..........: SetDefaults
; Description ...:
; Syntax ........: SetDefaults()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func SetDefaults()
	_GUICtrlEdit_SetText($ParameterInput1,'<x>')
	_GUICtrlEdit_SetText($ParameterInput2,'<y>')

	_GUICtrlEdit_SetText($FromToInput1,'1 to 99')
	_GUICtrlEdit_SetText($FromToInput2,'1 to 99')

EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: AddDataToListView
; Description ...:
; Syntax ........: AddDataToListView($sUrl)
; Parameters ....: $sUrl                - a string value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func AddDataToListView($sUrl)
	Local $index
	Local $sUrlName, $avUrlLinks, $iUrlLinksRet
	If $sUrl <> "" Then
		$sUrlName = GetName($sUrl)
		$iUrlLinksRet = GetLinks($sUrl,$avUrlLinks)
		If $iUrlLinksRet > 0 Then
			$index = SetListViewItemByName($MAIN_ITEM, "Name"  , $sUrlName )
					 SetListViewItemByName($SUB_ITEM , "Images", $iUrlLinksRet & " found", $index )
					 SetListViewItemByName($SUB_ITEM , "URL"   , $sUrl, $index )
			For $i = 0 To UBound($avUrlLinks) - 1
			$index = SetListViewItemByName($MAIN_ITEM, "Name"  , "" )
					 SetListViewItemByName($SUB_ITEM , "Images", $i + 1         , $index)
					 SetListViewItemByName($SUB_ITEM , "URL"   , $avUrlLinks[$i], $index )

			Next
		Else
			; Add Status Message "No Links found"
		EndIf
	Else
		;Add Status Message "Gigen String is empty"
	Endif
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: DeleteEntryFromList
; Description ...:
; Syntax ........: DeleteEntryFromList()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func DeleteEntryFromList()
	Local $index, $avIndex, $msgBoxRet

	$index =_GUICtrlListView_GetSelectedIndices($DataList)
	If $index <> "" Then
		$avIndex = StringSplit($index,'|')
		$msgBoxRet = MsgBox(BitOR($MB_YESNO,$MB_ICONQUESTION),"Delete Objects","Do you want to delete " & $avIndex[0] & " Objects?", 10)
		If $msgBoxRet = $IDYES Then
			_GUICtrlListView_DeleteItemsSelected ($DataList)
		Else
			; Add Status Message "Deletion canceld"
		EndIf
	EndIf
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: SetStatusBarMessage
; Description ...:
; Syntax ........: SetStatusBarMessage($message)
; Parameters ....: $message             - a map.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func SetStatusBarMessage($message)


EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: StatusMessageTask
; Description ...:
; Syntax ........: StatusMessageTask()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func StatusMessageTask()


EndFunc



;--- Gui Events ------------------------------------------------------------

; #FUNCTION# ====================================================================================================================
; Name ..........: ExitExec
; Description ...:
; Syntax ........: ExitExec()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func ExitExec()


	Exit
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: AddToList
; Description ...:
; Syntax ........: AddToList()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func AddToList()
	Local $url = _GUICtrlEdit_GetText($ModifiedUrlInput)
	AddDataToListView($url)
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: DeleteFromList
; Description ...:
; Syntax ........: DeleteFromList()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func DeleteFromList()

	DeleteEntryFromList()
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: ChooseFolder
; Description ...:
; Syntax ........: ChooseFolder()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func ChooseFolder()
	Local $folder = FileSelectFolder("Select folder where data has to be stored:",@ScriptDir, $FSF_CREATEBUTTON +  $FSF_NEWDIALOG ,"",$ImageLoader)
	If @error = 0 Then
		_GUICtrlEdit_SetText($SaveInput,$folder)
	Else
		;Add Status Message "No Folder Choosen"
	EndIf
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: StartDownload
; Description ...:
; Syntax ........: StartDownload()
; Parameters ....:
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func StartDownload()


EndFunc

;--- End of Gui Events -----------------------------------------------------------


; #FUNCTION# ====================================================================================================================
; Name ..........: GetColumnIndexByName
; Description ...:
; Syntax ........: GetColumnIndexByName($sColumnName)
; Parameters ....: $sColumnName         - a string value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func GetColumnIndexByName($sColumnName)
	Local $index = -1
	For $i = 0 To UBound($listColumns) - 1
		If $sColumnName = $listColumns[$i][0] Then
			$index = $i
			ExitLoop
		EndIf
	Next
	Return $index
EndFunc

; #FUNCTION# ====================================================================================================================
; Name ..........: SetListViewItemByName
; Description ...:
; Syntax ........: SetListViewItemByName($eItemType, $sColumnName, $sData[, $mainItemIndex = -1])
; Parameters ....: $eItemType           - an enum value.
;                  $sColumnName         - a string value.
;                  $sData               - a string value.
;                  $mainItemIndex       - [optional] a map. Default is -1.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func SetListViewItemByName($eItemType, $sColumnName, $sData, $mainItemIndex = -1)

	Local $ret = -1
	Local $index = GetColumnIndexByName($sColumnName)

	If $eItemType = $MAIN_ITEM Then
		$ret = _GUICtrlListView_AddItem ($DataList,$sData)
	ElseIf $eItemType = $SUB_ITEM And $mainItemIndex >= 0 Then
		If $index >= 0 Then
			_GUICtrlListView_AddSubItem($DataList,$mainItemIndex,$sData,$index)
		Else

		EndIf
	Else

	EndIf
	Return $ret
EndFunc