#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <GuiStatusBar.au3>
#include <ListViewConstants.au3>
#include <StaticConstants.au3>
#include <TabConstants.au3>
#include <WindowsConstants.au3>

#Region ### START Koda GUI section ### Form=D:\Projekte\GitRepoProjects\AutoIt\ImageLoader\GUI\ImageLoader.kxf
$ImageLoader = GUICreate("Image Loader", 615, 480, 192, 124)
$DataList = GUICtrlCreateListView("", 88, 200, 514, 254)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
GUICtrlSetResizing(-1, $GUI_DOCKAUTO+$GUI_DOCKLEFT+$GUI_DOCKRIGHT+$GUI_DOCKTOP)
$StopButton = GUICtrlCreateButton("Stop", 8, 320, 75, 25)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$StartButton = GUICtrlCreateButton("Start", 8, 288, 75, 25)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$UrlInput = GUICtrlCreateInput("", 224, 16, 377, 21)
$Label1 = GUICtrlCreateLabel("URL:", 192, 16, 32, 17, BitOR($SS_CENTER,$SS_CENTERIMAGE))
GUICtrlSetFont(-1, 8, 800, 0, "Verdana")
$DeleteButton = GUICtrlCreateButton("Delete", 8, 240, 75, 25)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$Group1 = GUICtrlCreateGroup("Options:", 192, 40, 409, 153, -1, $WS_EX_TRANSPARENT)
GUICtrlSetFont(-1, 8, 800, 0, "Verdana")
$Tab1 = GUICtrlCreateTab(200, 56, 393, 129)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$SearchOptionTab = GUICtrlCreateTabItem("Search Option")
$ModifiedUrlInput = GUICtrlCreateInput("", 304, 88, 273, 21)
$Label2 = GUICtrlCreateLabel("URL Modified:", 212, 88, 82, 21, BitOR($SS_CENTER,$SS_CENTERIMAGE))
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$ParameterInput1 = GUICtrlCreateInput("", 288, 120, 49, 21)
$FromToInput1 = GUICtrlCreateInput("", 416, 120, 89, 21)
$Label3 = GUICtrlCreateLabel("Parameter:", 212, 120, 69, 21, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$Label4 = GUICtrlCreateLabel("Reagion:", 352, 120, 55, 21, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$ParameterInput2 = GUICtrlCreateInput("", 288, 152, 49, 21)
$Label5 = GUICtrlCreateLabel("Parameter:", 212, 152, 69, 21, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$Label6 = GUICtrlCreateLabel("Reagion:", 352, 152, 55, 21, $SS_CENTERIMAGE)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$FromToInput2 = GUICtrlCreateInput("", 416, 152, 89, 21)
$DefaultButton = GUICtrlCreateButton("Set Default ", 512, 120, 67, 50, $BS_MULTILINE)
$OptionsTab = GUICtrlCreateTabItem("Options")
$Label7 = GUICtrlCreateLabel("Save to Folder:", 212, 88, 92, 21, BitOR($SS_CENTER,$SS_CENTERIMAGE))
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$SaveInput = GUICtrlCreateInput("", 312, 88, 217, 21)
$FolderButton = GUICtrlCreateButton("...", 536, 88, 43, 21)
GUICtrlCreateTabItem("")
GUICtrlCreateGroup("", -99, -99, 1, 1)
$ExitButton = GUICtrlCreateButton("Exit", 8, 424, 75, 25)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$Preview = GUICtrlCreatePic("D:\Projekte\GitRepoProjects\AutoIt\ImageLoader\GUI\no-image-available.jpg", 16, 16, 172, 180)
$AddButton = GUICtrlCreateButton("Add", 8, 208, 75, 25)
GUICtrlSetFont(-1, 8, 400, 0, "Verdana")
$StatusBar = _GUICtrlStatusBar_Create($ImageLoader)
_GUICtrlStatusBar_SetSimple($StatusBar)
_GUICtrlStatusBar_SetText($StatusBar, "")
#EndRegion ### END Koda GUI section ###

