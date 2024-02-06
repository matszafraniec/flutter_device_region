#include "device_region_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

namespace device_region {

// static
void DeviceRegionPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "device_region",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<DeviceRegionPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

DeviceRegionPlugin::DeviceRegionPlugin() {}

DeviceRegionPlugin::~DeviceRegionPlugin() {}

void DeviceRegionPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("getSIMCountryCode") == 0) {
      result->Success(flutter::EncodableValue());
  } else {
    result->NotImplemented();
  }
}

}  // namespace device_region
