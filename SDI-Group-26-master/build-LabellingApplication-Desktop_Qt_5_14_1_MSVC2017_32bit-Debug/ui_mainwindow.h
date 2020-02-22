/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QListWidget *imageList;
    QPushButton *loadImagesButton;
    QPushButton *dateSortButton;
    QPushButton *nameSortButton;
    QGroupBox *groupBox_2;
    QPushButton *classLoad;
    QListWidget *classList;
    QLineEdit *classEnter;
    QPushButton *classRemove;
    QPushButton *classAdd;
    QPushButton *classSave;
    QGroupBox *groupBox_3;
    QPushButton *saveYOLOButton;
    QPushButton *saveVOCButton;
    QPushButton *saveCOCOButton;
    QPushButton *restoreButton;
    QPlainTextEdit *editVOCName;
    QLabel *label;
    QLabel *imageDisplay;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QPushButton *loadBboxButton;
    QComboBox *shapeCombo;
    QLabel *label_3;
    QRadioButton *editShapeButton;
    QPushButton *helpButton;
    QPushButton *copyButton;
    QPushButton *pasteButton;
    QPushButton *cropButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 789, 160));
        imageList = new QListWidget(groupBox);
        imageList->setObjectName(QString::fromUtf8("imageList"));
        imageList->setGeometry(QRect(180, 20, 591, 131));
        loadImagesButton = new QPushButton(groupBox);
        loadImagesButton->setObjectName(QString::fromUtf8("loadImagesButton"));
        loadImagesButton->setGeometry(QRect(10, 20, 151, 31));
        dateSortButton = new QPushButton(groupBox);
        dateSortButton->setObjectName(QString::fromUtf8("dateSortButton"));
        dateSortButton->setGeometry(QRect(10, 70, 151, 31));
        nameSortButton = new QPushButton(groupBox);
        nameSortButton->setObjectName(QString::fromUtf8("nameSortButton"));
        nameSortButton->setGeometry(QRect(10, 120, 151, 31));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(800, 0, 779, 160));
        classLoad = new QPushButton(groupBox_2);
        classLoad->setObjectName(QString::fromUtf8("classLoad"));
        classLoad->setGeometry(QRect(10, 20, 161, 31));
        classList = new QListWidget(groupBox_2);
        classList->setObjectName(QString::fromUtf8("classList"));
        classList->setGeometry(QRect(180, 20, 581, 131));
        classEnter = new QLineEdit(groupBox_2);
        classEnter->setObjectName(QString::fromUtf8("classEnter"));
        classEnter->setGeometry(QRect(10, 90, 161, 20));
        QFont font;
        font.setPointSize(7);
        classEnter->setFont(font);
        classRemove = new QPushButton(groupBox_2);
        classRemove->setObjectName(QString::fromUtf8("classRemove"));
        classRemove->setGeometry(QRect(90, 50, 81, 31));
        classAdd = new QPushButton(groupBox_2);
        classAdd->setObjectName(QString::fromUtf8("classAdd"));
        classAdd->setGeometry(QRect(10, 50, 81, 31));
        classSave = new QPushButton(groupBox_2);
        classSave->setObjectName(QString::fromUtf8("classSave"));
        classSave->setGeometry(QRect(10, 120, 161, 31));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1580, 0, 331, 160));
        saveYOLOButton = new QPushButton(groupBox_3);
        saveYOLOButton->setObjectName(QString::fromUtf8("saveYOLOButton"));
        saveYOLOButton->setGeometry(QRect(10, 20, 151, 31));
        saveVOCButton = new QPushButton(groupBox_3);
        saveVOCButton->setObjectName(QString::fromUtf8("saveVOCButton"));
        saveVOCButton->setGeometry(QRect(10, 70, 151, 31));
        saveCOCOButton = new QPushButton(groupBox_3);
        saveCOCOButton->setObjectName(QString::fromUtf8("saveCOCOButton"));
        saveCOCOButton->setGeometry(QRect(170, 20, 151, 31));
        restoreButton = new QPushButton(groupBox_3);
        restoreButton->setObjectName(QString::fromUtf8("restoreButton"));
        restoreButton->setGeometry(QRect(170, 70, 151, 31));
        editVOCName = new QPlainTextEdit(groupBox_3);
        editVOCName->setObjectName(QString::fromUtf8("editVOCName"));
        editVOCName->setGeometry(QRect(170, 120, 151, 31));
        QFont font1;
        font1.setPointSize(9);
        editVOCName->setFont(font1);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 120, 71, 31));
        imageDisplay = new QLabel(centralwidget);
        imageDisplay->setObjectName(QString::fromUtf8("imageDisplay"));
        imageDisplay->setGeometry(QRect(10, 210, 1901, 841));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 160, 1900, 51));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 55, 31));
        loadBboxButton = new QPushButton(groupBox_4);
        loadBboxButton->setObjectName(QString::fromUtf8("loadBboxButton"));
        loadBboxButton->setGeometry(QRect(80, 10, 150, 30));
        shapeCombo = new QComboBox(groupBox_4);
        shapeCombo->addItem(QString());
        shapeCombo->addItem(QString());
        shapeCombo->addItem(QString());
        shapeCombo->addItem(QString());
        shapeCombo->addItem(QString());
        shapeCombo->setObjectName(QString::fromUtf8("shapeCombo"));
        shapeCombo->setGeometry(QRect(350, 10, 291, 30));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 10, 55, 31));
        editShapeButton = new QRadioButton(groupBox_4);
        editShapeButton->setObjectName(QString::fromUtf8("editShapeButton"));
        editShapeButton->setGeometry(QRect(670, 10, 121, 31));
        helpButton = new QPushButton(groupBox_4);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(1740, 10, 150, 30));
        copyButton = new QPushButton(groupBox_4);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        copyButton->setGeometry(QRect(840, 10, 151, 31));
        pasteButton = new QPushButton(groupBox_4);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        pasteButton->setGeometry(QRect(1020, 10, 151, 31));
        cropButton = new QPushButton(groupBox_4);
        cropButton->setObjectName(QString::fromUtf8("cropButton"));
        cropButton->setGeometry(QRect(1200, 10, 151, 31));
        MainWindow->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();
        imageDisplay->raise();
        groupBox_4->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Image", nullptr));
        loadImagesButton->setText(QCoreApplication::translate("MainWindow", "Load Images", nullptr));
        dateSortButton->setText(QCoreApplication::translate("MainWindow", "Order By Date", nullptr));
        nameSortButton->setText(QCoreApplication::translate("MainWindow", "Order By Name", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Class", nullptr));
        classLoad->setText(QCoreApplication::translate("MainWindow", "Load Class", nullptr));
        classEnter->setPlaceholderText(QCoreApplication::translate("MainWindow", "Add Class Name Then Press \"Add\"", nullptr));
        classRemove->setText(QCoreApplication::translate("MainWindow", "Remove Class", nullptr));
        classAdd->setText(QCoreApplication::translate("MainWindow", "Add New Class", nullptr));
        classSave->setText(QCoreApplication::translate("MainWindow", "Save Classes", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
        saveYOLOButton->setText(QCoreApplication::translate("MainWindow", "Save YOLO", nullptr));
        saveVOCButton->setText(QCoreApplication::translate("MainWindow", "Save VOC", nullptr));
        saveCOCOButton->setText(QCoreApplication::translate("MainWindow", "Save COCO", nullptr));
        restoreButton->setText(QCoreApplication::translate("MainWindow", "Restore", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "VOC Folder", nullptr));
        imageDisplay->setText(QString());
        groupBox_4->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "BBoxes:", nullptr));
        loadBboxButton->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        shapeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Pick a shape...", nullptr));
        shapeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Square/Rectangle", nullptr));
        shapeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        shapeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Trapezium", nullptr));
        shapeCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Polygon", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Shapes:", nullptr));
        editShapeButton->setText(QCoreApplication::translate("MainWindow", "Edit Shape", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        pasteButton->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        cropButton->setText(QCoreApplication::translate("MainWindow", "Crop/Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
