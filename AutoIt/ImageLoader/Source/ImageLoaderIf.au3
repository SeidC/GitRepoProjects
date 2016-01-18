#include-once
#include <MsgBoxConstants.au3>
#include <StringConstants.au3>
#include "ImageLoaderParam.au3"


Func IsUrl($string)
	Return StringRegExp($string,$regExp_URL,$STR_REGEXPMATCH)
EndFunc