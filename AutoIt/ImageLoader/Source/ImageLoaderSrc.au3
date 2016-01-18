#include-once
#include <GuiListView.au3>
#include "ImageLoaderGui.au3"



Init()


Main()


Func Init()

	AddListViewColums()


	StartGUI()
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


Func Main()


EndFunc