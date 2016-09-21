import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Драутути")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Тыкнул");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        anchors.fill: parent
        button1.onClicked: messageDialog.show(qsTr("Тык 1"))
        button2.onClicked: messageDialog.show(qsTr("Тык 2"))
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("Заголовок")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
