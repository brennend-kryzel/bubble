import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import 'package:youtube_downloader/widgets/nav-drawer.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations([DeviceOrientation.portraitUp]);
    return MaterialApp(
      title: 'ytdownload',
      theme: ThemeData(
        primarySwatch: Colors.green,
        fontFamily: 'NimbusMono',
      ),
      home: HomePage(),
    );
  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
          title: Padding(
              padding: EdgeInsets.only(top: 8),
              child: Text(
                'Download',
                style: TextStyle(
                    color: Colors.blueAccent, fontWeight: FontWeight.bold),
              ))),
      drawer: NavDrawer(),
    );
  }
}
