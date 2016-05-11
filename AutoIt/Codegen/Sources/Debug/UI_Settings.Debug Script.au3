AutoIt_Debugger_LoadFile("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3")
AutoIt_Debugger_DebugFile(@ScriptFullPath)

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 1, False))
#Include "Z:\Projekte\Projects\AutoIt\Codegen\Sources\Debug\UI_Callbacks.Debug Script.au3"
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 1, False, @error, @extended))




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 5, False))
Func UI_UseEventMode($bool)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 5, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("bool")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$bool", $bool))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 6, False))
	If $bool = True Then
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 6, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("bool")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$bool", $bool))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 7, False))
		Opt("GUIOnEventMode", TRUE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 7, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 8, False))
	Else
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 8, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 9, False))
		Opt("GUIOnEventMode", FALSE)
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 9, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 10, False))
	EndIf
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 10, False, @error, @extended))
EndFunc




SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 15, False))
Func UI_SetCallbacks()
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 15, False, @error, @extended))

SetError(@error, @extended, AutoIt_Debugger_NextLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 16, False))
	GUISetOnEvent($GUI_EVENT_CLOSE, "UI_Close")
SetError(@error, @extended, AutoIt_Debugger_FinishedLine("Z:\Projekte\Projects\AutoIt\Codegen\Sources\UI_Settings.au3", "UI_Settings.au3", 16, False, @error, @extended))
If SetError(@error, @extended, IsDeclared("GUI_EVENT_CLOSE")) Then SetError(@error, @extended, AutoIt_Debugger_SendVariable("$GUI_EVENT_CLOSE", $GUI_EVENT_CLOSE))


EndFunc



