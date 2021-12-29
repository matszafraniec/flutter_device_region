import 'dart:async';

import 'package:flutter/services.dart';

class DeviceRegion {
  static const MethodChannel _channel = MethodChannel('device_region');

  /// ## Android:
  /// 
  /// Using [TelephonyManager][1] class:
  /// 
  /// Returns *simCountryIso* if available, even if card is not in the slot. Otherwise, it should return *networkCountryIso*. 
  ///
  /// In case the value cannot be retrieved or an error occurs, null value will be returned
  /// 
  /// [1]: https://developer.android.com/reference/android/telephony/TelephonyManager
  /// 

  static Future<String?> getSIMCountryCode() async =>
      await _channel.invokeMethod(
        'getSIMCountryCode',
      );
}
