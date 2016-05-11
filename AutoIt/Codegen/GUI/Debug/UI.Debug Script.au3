AutoIt_Debugger_LoadFile("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3")
AutoIt_Debugger_DebugFile(@ScriptFullPath)

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 1, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\ButtonConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 1, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 2, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\ComboConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 2, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 3, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\EditConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 3, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 4, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\GUIConstantsEx.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 4, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 5, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\StaticConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 5, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 6, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\TabConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 6, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 7, False))
#Include "C:\Development Tools\AutoIt\AutoIt3\Include\WindowsConstants.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 7, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 8, False))
#Region ### START Koda GUI section ### Form=z:\projekte\projects\autoit\codegen\gui\ui.kxf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 8, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 10, False))
Func UI_Init()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 10, False, @error, @extended))


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 12, False))
	Global $UI = GUICreate("TP Configurator", 498, 431, 194, 137)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 12, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("UI")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$UI", $UI))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 13, False))
	Global $Tab1 = GUICtrlCreateTab(13, 57, 477, 303)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 13, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Tab1")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Tab1", $Tab1))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 14, False))
	Global $TPConfigTab = GUICtrlCreateTabItem("TP Config")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 14, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("TPConfigTab")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$TPConfigTab", $TPConfigTab))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 15, False))
	Global $Label2 = GUICtrlCreateLabel("Max. Message Length: ", 27, 99, 115, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 15, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label2")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label2", $Label2))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 16, False))
	Global $MaxMsgLenEdit = GUICtrlCreateInput("", 391, 99, 79, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_NUMBER))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 16, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("MaxMsgLenEdit")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$MaxMsgLenEdit", $MaxMsgLenEdit))
If SetError(@error, @extended, IsDeclared("GUI_SS_DEFAULT_INPUT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$GUI_SS_DEFAULT_INPUT", $GUI_SS_DEFAULT_INPUT))
If SetError(@error, @extended, IsDeclared("ES_NUMBER")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ES_NUMBER", $ES_NUMBER))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 17, False))
	Global $Group1 = GUICtrlCreateGroup("Message Indicator (Start) Configuration:", 27, 197, 449, 65)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 17, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Group1")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Group1", $Group1))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 18, False))
	Global $Label9 = GUICtrlCreateLabel("Value/Parameter", 37, 227, 84, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 18, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label9")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label9", $Label9))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 19, False))
	Global $Input3 = GUICtrlCreateInput("Input1", 141, 227, 111, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT,$ES_NUMBER))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 19, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Input3")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Input3", $Input3))
If SetError(@error, @extended, IsDeclared("GUI_SS_DEFAULT_INPUT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$GUI_SS_DEFAULT_INPUT", $GUI_SS_DEFAULT_INPUT))
If SetError(@error, @extended, IsDeclared("ES_RIGHT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ES_RIGHT", $ES_RIGHT))
If SetError(@error, @extended, IsDeclared("ES_NUMBER")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ES_NUMBER", $ES_NUMBER))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 20, False))
	Global $Label10 = GUICtrlCreateLabel("Indicator Type", 258, 227, 72, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 20, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label10")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label10", $Label10))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 21, False))
	Global $Combo3 = GUICtrlCreateCombo("", 336, 227, 131, 25, BitOR($CBS_DROPDOWN,$CBS_AUTOHSCROLL))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 21, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Combo3")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Combo3", $Combo3))
If SetError(@error, @extended, IsDeclared("CBS_DROPDOWN")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CBS_DROPDOWN", $CBS_DROPDOWN))
If SetError(@error, @extended, IsDeclared("CBS_AUTOHSCROLL")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CBS_AUTOHSCROLL", $CBS_AUTOHSCROLL))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 22, False))
		   GUICtrlSetData(-1, "String|Integer")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 22, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 23, False))
		   GUICtrlCreateGroup("", -99, -99, 1, 1)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 23, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 24, False))
	Global $Group3 = GUICtrlCreateGroup("Message Indicator (Stop) Configuration:", 27, 276, 449, 66)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 24, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Group3")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Group3", $Group3))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 25, False))
	Global $Label7 = GUICtrlCreateLabel("Value/Parameter", 37, 306, 84, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 25, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label7")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label7", $Label7))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 26, False))
	Global $Input2 = GUICtrlCreateInput("Input1", 141, 306, 111, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 26, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Input2")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Input2", $Input2))
If SetError(@error, @extended, IsDeclared("GUI_SS_DEFAULT_INPUT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$GUI_SS_DEFAULT_INPUT", $GUI_SS_DEFAULT_INPUT))
If SetError(@error, @extended, IsDeclared("ES_RIGHT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ES_RIGHT", $ES_RIGHT))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 27, False))
	Global $Label8 = GUICtrlCreateLabel("Indicator Type", 258, 306, 72, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 27, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label8")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label8", $Label8))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 28, False))
	Global $Combo2 = GUICtrlCreateCombo("", 336, 306, 131, 25, BitOR($CBS_DROPDOWN,$CBS_AUTOHSCROLL))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 28, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Combo2")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Combo2", $Combo2))
If SetError(@error, @extended, IsDeclared("CBS_DROPDOWN")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CBS_DROPDOWN", $CBS_DROPDOWN))
If SetError(@error, @extended, IsDeclared("CBS_AUTOHSCROLL")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CBS_AUTOHSCROLL", $CBS_AUTOHSCROLL))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 29, False))
		   GUICtrlSetData(-1, "String|Integer")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 29, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 30, False))
		   GUICtrlCreateGroup("", -99, -99, 1, 1)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 30, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 31, False))
	Global $Group5 = GUICtrlCreateGroup("Delimiter Configuration", 27, 132, 449, 52)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 31, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Group5")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Group5", $Group5))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 32, False))
	Global $Label13 = GUICtrlCreateLabel("Delimiter:", 37, 156, 47, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 32, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label13")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label13", $Label13))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 33, False))
	Global $Input5 = GUICtrlCreateInput("\r\n", 173, 156, 79, 21, BitOR($GUI_SS_DEFAULT_INPUT,$ES_RIGHT))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 33, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Input5")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Input5", $Input5))
If SetError(@error, @extended, IsDeclared("GUI_SS_DEFAULT_INPUT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$GUI_SS_DEFAULT_INPUT", $GUI_SS_DEFAULT_INPUT))
If SetError(@error, @extended, IsDeclared("ES_RIGHT")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$ES_RIGHT", $ES_RIGHT))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 34, False))
	Global $Label14 = GUICtrlCreateLabel("Delimiter Type", 258, 156, 71, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 34, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label14")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label14", $Label14))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 35, False))
	Global $Combo5 = GUICtrlCreateCombo("", 336, 156, 131, 25, BitOR($CBS_DROPDOWN,$CBS_AUTOHSCROLL))
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 35, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Combo5")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Combo5", $Combo5))
If SetError(@error, @extended, IsDeclared("CBS_DROPDOWN")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CBS_DROPDOWN", $CBS_DROPDOWN))
If SetError(@error, @extended, IsDeclared("CBS_AUTOHSCROLL")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$CBS_AUTOHSCROLL", $CBS_AUTOHSCROLL))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 36, False))
		   GUICtrlSetData(-1, "String|Integer")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 36, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 37, False))
		   GUICtrlCreateGroup("", -99, -99, 1, 1)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 37, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 38, False))
		   GUICtrlCreateTabItem("")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 38, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 39, False))
	Global $Label1 = GUICtrlCreateLabel("TP Modul:", 13, 20, 53, 17, $SS_CENTERIMAGE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 39, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("Label1")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$Label1", $Label1))
If SetError(@error, @extended, IsDeclared("SS_CENTERIMAGE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$SS_CENTERIMAGE", $SS_CENTERIMAGE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 40, False))
		   GUICtrlSetData(-1, "USART|SPI")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 40, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 41, False))
	Global $GenerateButton = GUICtrlCreateButton("Generate Code", 24, 367, 61, 54, $BS_MULTILINE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 41, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("GenerateButton")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$GenerateButton", $GenerateButton))
If SetError(@error, @extended, IsDeclared("BS_MULTILINE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$BS_MULTILINE", $BS_MULTILINE))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 42, False))
	Global $AddModuleButton = GUICtrlCreateButton("Add Module", 272, 14, 80, 32)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 42, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("AddModuleButton")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$AddModuleButton", $AddModuleButton))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 43, False))
	Global $DeleteModuleButton = GUICtrlCreateButton("Delete Module", 357, 14, 94, 32)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 43, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("DeleteModuleButton")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$DeleteModuleButton", $DeleteModuleButton))

EndFunc


SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 47, False))
#EndRegion ### END Koda GUI section ###
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\..\GUI\UI.au3", "UI.au3", 47, False, @error, @extended))

