#include-once
#include <GuiListView.au3>
#include <GuiEdit.au3>
#include "ImageLoaderGui.au3"
#include "ImageLoaderIf.au3"



Init()


Main()


Func Init()

	SetUpGuiEvents()
	AddListViewColums()


	StartGUI()
EndFunc

Func Main()

	While (1)
		MainCycleTasks()
		Sleep (500)
	WEnd
EndFunc

Func AddListViewColums()

	_GUICtrlListView_AddColumn($DataList, "URL", 200)
	_GUICtrlListView_AddColumn($DataList, "Search Settings", 100)
	_GUICtrlListView_AddColumn($DataList, "Image", 100)
	_GUICtrlListView_AddColumn($DataList, "Info", 100)
	_GUICtrlListView_AddColumn($DataList, "Progress", 100)

EndFunc



Func StartGUI()
	GUISetState(@SW_SHOW,$ImageLoader)
EndFunc


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


Func MainCycleTasks()

	HandleClipBoard()
EndFunc


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


;--- Gui Events -------------------------

Func ExitExec()


	Exit
EndFunc


Func AddToList()


EndFunc


Func DeleteFromList()

EndFunc