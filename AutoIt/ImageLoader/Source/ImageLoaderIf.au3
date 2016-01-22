#include-once
#include <MsgBoxConstants.au3>
#include <StringConstants.au3>
#include "API/H2R.au3"
#include "Array.au3"


;--- Constants -------------------------------------------------------------------------

Global Const $regExp_URL = "[-a-zA-Z0-9@:%_\+.~#?&//=]{2,256}\.[a-z]{2,4}\b(\/[-a-zA-Z0-9@:%_\+.~#?&//=]*)?"

Global Enum $H2R = 0 , _
			$NUMBER_OF_SUPPORTED_SITES


Global Const $sites[$NUMBER_OF_SUPPORTED_SITES] = 	[				_
														$H2R_Name	_
													]				_



;--- Debug Section ---------------------------------------------------------------------

Global $tAv;
Global $pics = GetLinks('http://hentai2read.com/mamoritai_hito/1/1/',$tAv)
ConsoleWrite("Number of Pics: " & $pics & @CRLF)
_ArrayDisplay($tAv)
;--- End Of Debug Section --------------------------------------------------------------



Func IsUrl($string)
	Return StringRegExp($string,$regExp_URL,$STR_REGEXPMATCH)
EndFunc


Func IsSiteSupported($url)

	Local $ret = $API_SITE_NOT_SUPPORTED
	For $i = 0 To $NUMBER_OF_SUPPORTED_SITES - 1
		If StringInStr($url,$sites[$i],1) Then
			$ret = $i
			ExitLoop
		EndIf
	Next
	Return $ret
EndFunc



Func GetNumberOfPics($url)

	Local $site = IsSiteSupported($url)
	Local $ret

	Switch($site)
		Case $H2R
			$ret = H2R_GetNumberOfPisc($url)
		Case Else
			$ret = $site
	EndSwitch

	Return $ret
EndFunc


Func GetLinks($url, ByRef $avToStoreLinks)

	Local $site = IsSiteSupported($url)
	Local $ret

	Switch($site)
		Case $H2R
			$ret = H2R_GetLinks($url,$avToStoreLinks)
		Case Else
			$ret = $site
	EndSwitch

	Return $ret
EndFunc