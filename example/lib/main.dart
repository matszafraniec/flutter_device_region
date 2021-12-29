import 'package:flutter/material.dart';
import 'dart:async';

import 'package:device_region/device_region.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String _simRegion = 'Unknown';

  Future<void> askForSIMCountryCode() async {
    final result = await DeviceRegion.getSIMCountryCode();

    setState(() => _simRegion = result ?? 'Can\'t receive country code');
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Device_region example app'),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              ElevatedButton(
                onPressed: askForSIMCountryCode,
                child: const Text('Get SIM country code'),
              ),
              const SizedBox(height: 15),
              Text('Your SIM country code is: $_simRegion\n'),              
            ],
          ),
        ),
      ),
    );
  }
}
