#include "include/device_region/device_region_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#include "device_region_plugin_private.h"

#define DEVICE_REGION_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), device_region_plugin_get_type(), \
                              DeviceRegionPlugin))

struct _DeviceRegionPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(DeviceRegionPlugin, device_region_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void device_region_plugin_handle_method_call(
    DeviceRegionPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getSIMCountryCode") == 0) {
    g_autoptr(FlValue) result = nullptr;
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(result));
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}



static void device_region_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(device_region_plugin_parent_class)->dispose(object);
}

static void device_region_plugin_class_init(DeviceRegionPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = device_region_plugin_dispose;
}

static void device_region_plugin_init(DeviceRegionPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  DeviceRegionPlugin* plugin = DEVICE_REGION_PLUGIN(user_data);
  device_region_plugin_handle_method_call(plugin, method_call);
}

void device_region_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  DeviceRegionPlugin* plugin = DEVICE_REGION_PLUGIN(
      g_object_new(device_region_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "device_region",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
