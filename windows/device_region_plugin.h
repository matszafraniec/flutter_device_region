#ifndef FLUTTER_PLUGIN_DEVICE_REGION_PLUGIN_H_
#define FLUTTER_PLUGIN_DEVICE_REGION_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace device_region {

class DeviceRegionPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  DeviceRegionPlugin();

  virtual ~DeviceRegionPlugin();

  // Disallow copy and assign.
  DeviceRegionPlugin(const DeviceRegionPlugin&) = delete;
  DeviceRegionPlugin& operator=(const DeviceRegionPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace device_region

#endif  // FLUTTER_PLUGIN_DEVICE_REGION_PLUGIN_H_
