import 'package:flutter/material.dart';

class NavDrawer extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
        width: 250,
        child: Drawer(
          child: Column(children: <Widget>[
            Expanded(
              child: ListView(
                padding: EdgeInsets.zero,
                children: <Widget>[
                  DrawerHeader(
                      child: Text(''),
                      decoration: BoxDecoration(
                          color: Colors.white,
                          image: DecorationImage(
                              fit: BoxFit.contain,
                              image: AssetImage(
                                  'assets/images/Kisuke_Urahara_2.jpg')))),
                  ListTile(
                      leading: Icon(Icons.file_download),
                      title: Text('Download',
                          style: TextStyle(fontWeight: FontWeight.bold)),
                      onTap: () => {Navigator.of(context).pop()}),
                  ListTile(
                    leading: Icon(Icons.library_music),
                    title: Text('Library',
                        style: TextStyle(fontWeight: FontWeight.bold)),
                    onTap: () => {Navigator.of(context).pop()},
                  ),
                  ListTile(
                    leading: Icon(Icons.settings),
                    title: Text('Settings',
                        style: TextStyle(fontWeight: FontWeight.bold)),
                    onTap: () => {Navigator.of(context).pop()},
                  ),
                ],
              ),
            ),
            Container(
                child: Align(
                    alignment: FractionalOffset.bottomCenter,
                    child: Container(
                      child: Column(
                        children: <Widget>[
                          Divider(),
                          ListTile(
                              title: Text('Version 1.0.0',
                                  textAlign: TextAlign.center,
                                  style:
                                      TextStyle(fontWeight: FontWeight.bold))),
                          ListTile(
                            title: Text('Credits',
                                textAlign: TextAlign.center,
                                style: TextStyle(fontWeight: FontWeight.bold)),
                            onTap: () => {Navigator.of(context).pop()},
                          )
                        ],
                      ),
                    )))
          ]),
        ));
  }
}
