## 1.4.0

Added very basic support for Windows and Linux. `getSIMCountryCode` will return null instead of throwing an exception. Thanks to Martin Clauss.

## 1.3.0

Updated dart SDK constraints from <3.0.0 to <4.0.0.

## 1.2.0

[iOS] Due to deprecated properties in [CTTelephonyNetworkInfo][1] class, from iOS 16.0 plugin uses [Locale][2] class and returns Locale.current.region.[identifier][3].

[1]: https://developer.apple.com/documentation/coretelephony/cttelephonynetworkinf
[2]: https://developer.apple.com/documentation/foundation/locale
[3]: https://developer.apple.com/documentation/foundation/locale/region/3952434-identifier

## 1.1.0

[Android] Updated Gradle properties and dependencies.

## 1.0.2

Now return null if there is no SIM Card (UICC) in Android device (didn't return at all before).

## 1.0.1

Updated readme.

## 1.0.0

Updated to Flutter 3.

## 0.9.1

Updated readme.

## 0.9.0

Added platform specific code and shared `getSIMCountryCode` method. 