# device_region

A Flutter plugin which uses platform-specific API to return a SIM country code. Supports
iOS and Android.

## Installation

In your Flutter project, in pubspec.yaml file add the dependency:

```
dependencies:
  device_region: ^1.3.0
```

## Usage example

Import `device_region.dart` package.

``` dart
import 'package:device_region/device_region.dart';
```
### Get SIM country code

Call `getSIMCountryCode` method to receive SIM country code.

``` dart
await DeviceRegion.getSIMCountryCode();
```

#### Android:

Using [TelephonyManager][1] class:

Returns *simCountryIso* if available. Otherwise, it should return *networkCountryIso*. 

In case the value cannot be retrieved or an error occurs, null value will be returned
  
[1]: https://developer.android.com/reference/android/telephony/TelephonyManager
  
#### iOS:

##### iOS 16.0 and higher

Due to deprecated properties in [CTTelephonyNetworkInfo][2] class, plugin uses [Locale][4] class and returns Locale.current.region.[identifier][5].

##### iOS up to 16.0
 
Using [CTTelephonyNetworkInfo][2] class:
  
Returns [*isoCountryCode*][3] if available.
 
In case the value cannot be retrieved or an error occurs, null value will be returned
  
[2]: https://developer.apple.com/documentation/coretelephony/cttelephonynetworkinfo
[3]: https://developer.apple.com/documentation/coretelephony/ctcarrier/1620317-isocountrycode
[4]: https://developer.apple.com/documentation/foundation/locale
[5]: https://developer.apple.com/documentation/foundation/locale/region/3952434-identifier

## Important notes

- While call `getSIMCountryCode` on iOS (up to 16.0), it returns proper country code and can throw error log in debugger as below:
```
[Client] Updating selectors after delegate addition failed with: Error Domain=NSCocoaErrorDomain Code=4099 "The connection to service with pid 91 named com.apple.commcenter.coretelephony.xpc was invalidated from this process." UserInfo={NSDebugDescription=The connection to service with pid 91 named com.apple.commcenter.coretelephony.xpc was invalidated from this process.}
```

It's well known bug on iOS and it does not affect the operation of the application.

- Method returns `null` in case if for some reason it was not possible to retrieve the information from the SIM slot. So it will return null i.e on iOS simulators and devices without SIM card inserted.

- On iOS, it only works from 12.0 and above. For lower versions it will return `null`.