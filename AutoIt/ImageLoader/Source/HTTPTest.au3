#include <Array.au3>

Global const $regExp = '(<\s*a(\s+.*?>|>).*?<\s*/\s*a\s*>\,)'

GetNumberOfPics("")








Func GetNumberOfPics($url)
	Local $str
	InetGet($url,"Dump.dd")
	$str = FileRead("Dump.dd")
	FileDelete("Dump.dd")


	Local $av = StringRegExp($str,$regExp,3)

	_ArrayDisplay($av)
EndFunc