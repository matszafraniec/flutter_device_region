#include "include/device_region/device_region_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "device_region_plugin.h"

void DeviceRegionPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  device_region::DeviceRegionPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
