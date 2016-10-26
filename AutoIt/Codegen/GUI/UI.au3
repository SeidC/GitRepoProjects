#include <ButtonConstants.au3>
#include <ComboConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <TabConstants.au3>
#include <WindowsConstants.au3>
#Region ### START Koda GUI section ### Form=z:\projekte\projects\autoit\codegen\gui\ui.kxf


Func UI_Init()

	Global $UI = GUICreate("TP Configurator", 498, 431, 194, 137)
	Global $Tab1 = GUICtrlCreateTab(13, 57, 477, 303)
	Global $TPConfigTab = GUICtrlCreateTabItem("TP Config")
	Global $Label2 = GUICtrlCreateLabel("Max. Message Length: ", 27, 99, 115, 17, $SS_CENTERIMAGE)
	Global $MaxMsgLenEdit = GUICtrlCreateInput("", 167, 99, 303, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_NUMBER))
	Global $Group1 = GUICtrlCreateGroup("Message Indicator (Start) Configuration:", 27, 197, 449, 65)
	Global $Label9 = GUICtrlCreateLabel("Value/Parameter", 37, 227, 84, 17, $SS_CENTERIMAGE)
	Global $msgIndiStartEdit = GUICtrlCreateInput("", 141, 227, 111, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT,$ES_NUMBER))
	Global $Label10 = GUICtrlCreateLabel("Indicator Type", 258, 227, 72, 17, $SS_CENTERIMAGE)
	Global $msgIndiStartCombo = GUICtrlCreateCombo("", 328, 227, 131, 25, BitOR($CBS_DROPDOWN,$CBS_AUTOHSCROLL))
		   GUICtrlSetData(-1, "String|Integer")
		   GUICtrlCreateGroup("", -99, -99, 1, 1)
	Global $Group3 = GUICtrlCreateGroup("Message Indicator (Stop) Configuration:", 27, 276, 449, 66)
	Global $Label7 = GUICtrlCreateLabel("Value/Parameter", 37, 306, 84, 17, $SS_CENTERIMAGE)
	Global $msgIndiStopEdit = GUICtrlCreateInput("", 141, 306, 111, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT))
	Global $Label8 = GUICtrlCreateLabel("Indicator Type", 258, 306, 72, 17, $SS_CENTERIMAGE)
	Global $msgIndiStopCombo = GUICtrlCreateCombo("", 336, 306, 131, 25, BitOR($CBS_DROPDOWN,$CBS_AUTOHSCROLL))
	       GUICtrlSetData(-1, "String|Integer")
	       GUICtrlCreateGroup("", -99, -99, 1, 1)
	Global $Group5 = GUICtrlCreateGroup("Delimiter Configuration", 27, 132, 449, 52)
	Global $Label13 = GUICtrlCreateLabel("Delimiter:", 37, 156, 47, 17, $SS_CENTERIMAGE)
	Global $DelimInput = GUICtrlCreateInput("\r\n", 173, 156, 79, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT))
	Global $Label14 = GUICtrlCreateLabel("Delimiter Type", 258, 156, 71, 17, $SS_CENTERIMAGE)
	Global $DelimTypeCombo = GUICtrlCreateCombo("", 336, 156, 131, 25, BitOR($CBS_DROPDOWN,$CBS_AUTOHSCROLL))
		   GUICtrlSetData(-1, "String|Integer")
		   GUICtrlCreateGroup("", -99, -99, 1, 1)
		   GUICtrlCreateTabItem("")
	Global $Label1 = GUICtrlCreateLabel("TP Modul:", 13, 20, 53, 17, $SS_CENTERIMAGE)
	Global $ModuleCombo = GUICtrlCreateCombo("", 77, 20, 190, 25, BitOR($CBS_DROPDOWNLIST,$CBS_AUTOHSCROLL))
	       GUICtrlSetData(-1, "USART|SPI")
	Global $GenerateButton = GUICtrlCreateButton("Generate Code", 24, 367, 61, 54, $BS_MULTILINE)
	Global $AddModuleButton = GUICtrlCreateButton("Add Module", 272, 14, 80, 32)
	Global $DeleteModuleButton = GUICtrlCreateButton("Delete Module", 357, 14, 94, 32)

EndFunc

#EndRegion ### END Koda GUI section ###

