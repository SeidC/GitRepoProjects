#include "API_Constants.au3"




;--- Constants -------------------------------------------------------------------------

; SitenName of this Api
Global Const $H2R_Name = "http://hentai2read.com"
;Regular Expression to filter Links from Site
Global Const $H2R_LinkRegExp = '(<\s*a(\s+.*?>|>).*?<\s*/\s*a\s*>\,)'
;Filename were the Site Dump will be stored
Global Const $H2R_SiteDump = "H2R_Dump.dd"




Func H2R_GetNumberOfPisc($url)
	Local $str
	Local $ret = $API_DOWNLOAD_ERROR
	Local $bytes
	Local $av

	;Download HTML from URL
	$bytes = InetGet($url,$H2R_SiteDump)

	;Check Downlod successfull (> 0 Bytes)
	If $bytes > 0 Then
		;Read Data from downloaded Dump
		$str = FileRead($H2R_SiteDump,0)
		;Filter Links with Regular Expresstion
		$av = StringRegExp($str,$H2R_LinkRegExp,3)
		;Check return value whether it is a array with filtered links
		If IsArray($av) Then
			$ret = UBound($av) / 2
		Else
			$ret = $API_NO_LINKS_FOUND
		EndIf
	Else
		$ret = $API_DOWNLOAD_ERROR
	EndIf
	Return $ret
EndFunc


Func H2R_GetLinks($url, ByRef $avToStoreLinks)
	Local $str
	Local $ret = $API_DOWNLOAD_ERROR
	Local $bytes
	Local $av

	;Download HTML from URL
	$bytes = InetGet($url,$H2R_SiteDump,0)

	;Check Downlod successfull (> 0 Bytes)
	If $bytes > 0 Then
		;Read Data from downloaded Dump
		$str = FileRead($H2R_SiteDump)
		;Filter Links with Regular Expresstion
		$av = StringRegExp($str,$H2R_LinkRegExp,3)
		;Check return value whether it is a array with filtered links
		If IsArray($av) Then
			H2R_FilterLinks($av,$avToStoreLinks)
			$ret = UBound($avToStoreLinks)
		Else
			$ret = $API_NO_LINKS_FOUND
		EndIf
	Else
		$ret = $API_DOWNLOAD_ERROR
	EndIf
	Return $ret

EndFunc

;--- Internal Used Functions ---------------------------------------------------------------

Func H2R_FilterLinks(ByRef $avToFilter, ByRef $avToStore)

	Local $avSize
	Local $cAv[1]
	Local $count = 0
	$avSize = UBound($avToFilter) / 2
	ReDim $cAv[$avSize]

	For $i = 0 To UBound($avToFilter) - 1
		If Mod($i,2) = 0 Then
			$cAv[$count] = $avToFilter[$i + 1]
			$count += 1
		EndIf
	Next
	$avToStore = $cAv
	Return $count
EndFunc