#include "API_Constants.au3"
#include <Array.au3>




;--- Constants -------------------------------------------------------------------------

; SitenName of this Api
Global Const $H2R_Name = "http://hentai2read.com"
;Regular Expression to filter Links from Site
Global Const $H2R_LinkRegExp = '(<\s*a(\s+.*?>|>).*?<\s*/\s*a\s*>\,)'
;Regular Expression to filter the name of the Site
Global Const $H2R_NameRegExp = '\<h1\>.*\>\s+\>(.*)\<\/h1\>'
;Filename were the Site Dump will be stored
Global Const $H2R_SiteDump = "H2R_Dump.dd"

;--- Debug Section ---------------------------------------------------------------------

;~ 	H2R_GetName('http://hentai2read.com/mamoritai_hito/1/1/')
;--- End Of Debug Section --------------------------------------------------------------



; #FUNCTION# ====================================================================================================================
; Name ..........: H2R_GetNumberOfPisc
; Description ...:
; Syntax ........: H2R_GetNumberOfPisc($url)
; Parameters ....: $url                 - an unknown value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func H2R_GetNumberOfPisc($url)
	Local $str, $ret, $downRet
	Local $av

	;Download HTML from URL
	$downRet = H2R_DownloadUrl($url,$str)
	;Check wheter the URL was downloaded
	If $downRet = $API_OK Then
		;Filter Links with Regular Expresstion
		$av = StringRegExp($str,$H2R_LinkRegExp,3)
		;Check return value whether it is a array with filtered links
		If IsArray($av) Then
			$ret = UBound($av) / 2
		Else
			$ret = $API_NO_LINKS_FOUND
		EndIf
	Else
		$ret = $downRet
	EndIf

	Return $ret
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: H2R_GetLinks
; Description ...:
; Syntax ........: H2R_GetLinks($url, Byref $avToStoreLinks)
; Parameters ....: $url                 - an unknown value.
;                  $avToStoreLinks      - [in/out] an array of variants.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func H2R_GetLinks($url, ByRef $avToStoreLinks)
	Local $str, $ret, $downRet
	Local $av

	;Download HTML from URL
	$downRet = H2R_DownloadUrl($url,$str)
	;Check wheter the URL was downloaded
	If $downRet = $API_OK Then
		;Filter Links with Regular Expresstion
		$av = StringRegExp($str,$H2R_LinkRegExp,3)
		;Check return value whether it is a array with filtered links
		If IsArray($av) Then
			H2R_FilterLinks($av,$avToStoreLinks)
			$ret = UBound($avToStoreLinks)
		Else
			$ret = $API_NO_LINKS_FOUND
			$avToStoreLinks = ""
		EndIf
	Else
		$ret = $downRet
		$avToStoreLinks = ""
	EndIf
	Return $ret

EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: H2R_GetName
; Description ...:
; Syntax ........: H2R_GetName($url)
; Parameters ....: $url                 - an unknown value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func H2R_GetName($url)
	Local $str
	Local $downRet, $ret
	Local $av
	;Get needed HTML-Site
	$downRet = H2R_DownloadUrl($url,$str)
	;Check whether the HTML-Site was donwloaded successfully
	If $downRet = $API_OK Then
		$av = StringRegExp($str,$H2R_NameRegExp,3)
		If IsArray($av) Then
			$ret = $av[0]
		Else
			$ret = $API_NO_NAME_FOUND
		EndIf
	Else
		$ret = $downRet
	EndIf
		Return $ret
EndFunc

;--- Internal Used Functions ---------------------------------------------------------------

; #FUNCTION# ====================================================================================================================
; Name ..........: H2R_FilterLinks
; Description ...:
; Syntax ........: H2R_FilterLinks(Byref $avToFilter, Byref $avToStore)
; Parameters ....: $avToFilter          - [in ] an array with links which has to be filtered.
;                  $avToStore           - [out] an array with flitered links.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func H2R_FilterLinks(ByRef $avToFilter, ByRef $avToStore)

	Local $avSize, $p1,$p2,$offset, $str
	Local $cAv[1]
	Local $count = 0
	$avSize = UBound($avToFilter) / 2
	ReDim $cAv[$avSize]

	For $i = 0 To UBound($avToFilter) - 1
		If Mod($i,2) = 0 Then
			;Filter " from start and from the and. This both postions defines the range
			;of the http - Link
			$p1 = StringInStr($avToFilter[$i + 1],'"',0,1)
			$p2 = StringInStr($avToFilter[$i + 1],'"',0,-1)
			;p2 - p1 ist the needed range
			$offset = $p2 - $p1
			;Cut link from given String and copy into array.
			$str = StringMid($avToFilter[$i + 1],$p1+1,$offset)
			$cAv[$count] = $str
			$count += 1
		EndIf
	Next
	$avToStore = $cAv
	Return $count
EndFunc


; #FUNCTION# ====================================================================================================================
; Name ..........: H2R_DownloadUrl
; Description ...:
; Syntax ........: H2R_DownloadUrl($url, Byref $sRet)
; Parameters ....: $url                 - an unknown value.
;                  $sRet                - [in/out] a string value.
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func H2R_DownloadUrl($url, ByRef $sRet)
	Local $str = ""
	Local $ret = $API_DOWNLOAD_ERROR
	;Download HTML from URL
	$bytes = InetGet($url,$H2R_SiteDump,$INET_LOCALCACHE )
	If $bytes > 0 Then
		;Read Data from downloaded Dump
		$str = FileRead($H2R_SiteDump)
		If $str <> "" Then
			$ret = $API_OK
			$sRet = $str
		Else
			$sRet = ""
			$ret = $API_DOWNLOAD_ERROR
		EndIf
	Else
		$sRet = ""
		$ret = $API_DOWNLOAD_ERROR
	EndIf
		Return $ret
EndFunc