#include <MsgBoxConstants.au3>



Global $Ini = @ScriptDir & "\" & "StartUp.ini"

Global Const $numberOfDefaults = 5

Global $default = "ProgSectionName_"

Global Enum $PROGRAM_NAME = 0, $PROGRAM_PATH, $PROGRAM_PARAM,$NUMBER_OF_PARAMS

Global Const $programKeys[$NUMBER_OF_PARAMS] = ["ProgName","ProgPath","ProgParam"]



Main()


Func Ini_WriteDefault()

	For  $i = 0 To $numberOfDefaults
		Local $cSection = $default & $i
		IniWrite($Ini,"Programms","NAME_" & $i, $default & $i)
		IniWrite($Ini,$cSection,"ProgName","Test_" & $i & ".exe")
		IniWrite($Ini,$cSection,"ProgPath","C:\")
		IniWrite($Ini,$cSection,"ProgParam", "-a -b -c")
	Next
EndFunc


Func Main()
	Local $av = Ini_ReadProgramSection()
	Local $exec
	If FileExists($ini) Then
		;SplashImageOn("Start Up","C:\Gigatronik\Volume_D\Projekte\AutoIT\startup-business-loans.jpg",648,402,@DesktopWidth/2,@DesktopHeight/2)
		For $i = 1 To UBound($av) - 1
			$exec = Ini_ReadProgram($av[$i][1])
			ExecuteProgramm($exec)
		Next
		;Sleep(5000)
		;SplashOff ( )
	Else
		Ini_WriteDefault()
		MsgBox($MB_ICONINFORMATION,"First Configuration", "Default INI-File created. Please adapt this to setup StartUp Programms. Please Configure INI and start this Tool agin", 10)
	EndIf
EndFunc

Func Ini_ReadProgramSection()
	Local $av = IniReadSection($Ini,"Programms")
	Return $av
EndFunc

Func Ini_ReadProgram($sectionToRead)
	Local $av = IniReadSection($Ini,$sectionToRead)
	Local $path, $param, $program
	For $i = 1 To UBound($av) - 1
		Switch $av[$i][0]
			Case $programKeys[$PROGRAM_NAME]
				$program = $av[$i][1]
			Case $programKeys[$PROGRAM_PATH]
				 $path = $av[$i][1]
			Case $programKeys[$PROGRAM_PARAM]
				If $av[$i][1] <> "" Then
					$param = " " & $av[$i][1]
				Else
					$param = ""
				EndIf
			Case Else
		EndSwitch
	Next

	If Not IsLastBackslashAvailable($path) Then
		$path = $path & "\"
	EndIf

	If Not FileExists($path & $program) Then
		$path    = ""
		$program = ""
	EndIf

	Return $path & $program & $param
EndFunc

Func IsLastBackslashAvailable($pth)
	Local $ret = False
	If StringInStr($pth,"\",0,-1) = StringLen($pth) Then
		$ret = True
	EndIf
	Return $ret
EndFunc

Func ExecuteProgramm($prog)
	Local $pid
	If $prog <> "" Then
		$pid = Run($prog)
	EndIf
EndFunc