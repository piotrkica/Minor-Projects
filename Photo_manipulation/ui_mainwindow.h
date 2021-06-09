/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CPPGUI_H
#define CPPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *load_path_lineEdit;
    QPushButton *delete_button;
    QLineEdit *photo_display_info_lineEdit;
    QPushButton *next_button;
    QPushButton *prev_button;
    QLabel *photo_display;
    QLineEdit *load_path_info_lineEdit;
    QPushButton *load_path_button;
    QPushButton *negative_button;
    QPushButton *horizontal_mirror_button;
    QPushButton *load_button;
    QPushButton *copy_button;
    QPushButton *vertical_mirror_button;
    QPushButton *rotate_button;
    QPushButton *grayscale_button;
    QLineEdit *file_path_LineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(879, 564);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        load_path_lineEdit = new QLineEdit(centralwidget);
        load_path_lineEdit->setObjectName(QStringLiteral("load_path_lineEdit"));
        load_path_lineEdit->setGeometry(QRect(20, 50, 211, 41));
        load_path_lineEdit->setReadOnly(false);
        delete_button = new QPushButton(centralwidget);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        delete_button->setGeometry(QRect(20, 440, 131, 41));
        photo_display_info_lineEdit = new QLineEdit(centralwidget);
        photo_display_info_lineEdit->setObjectName(QStringLiteral("photo_display_info_lineEdit"));
        photo_display_info_lineEdit->setGeometry(QRect(560, 20, 81, 20));
        photo_display_info_lineEdit->setReadOnly(true);
        next_button = new QPushButton(centralwidget);
        next_button->setObjectName(QStringLiteral("next_button"));
        next_button->setGeometry(QRect(620, 440, 151, 41));
        prev_button = new QPushButton(centralwidget);
        prev_button->setObjectName(QStringLiteral("prev_button"));
        prev_button->setGeometry(QRect(460, 440, 151, 41));
        photo_display = new QLabel(centralwidget);
        photo_display->setObjectName(QStringLiteral("photo_display"));
        photo_display->setGeometry(QRect(360, 50, 491, 381));
        photo_display->setPixmap(QPixmap(QString::fromUtf8("SEM4/GUI-szkic.png")));
        photo_display->setScaledContents(true);
        load_path_info_lineEdit = new QLineEdit(centralwidget);
        load_path_info_lineEdit->setObjectName(QStringLiteral("load_path_info_lineEdit"));
        load_path_info_lineEdit->setGeometry(QRect(20, 20, 211, 20));
        load_path_info_lineEdit->setReadOnly(true);
        load_path_button = new QPushButton(centralwidget);
        load_path_button->setObjectName(QStringLiteral("load_path_button"));
        load_path_button->setGeometry(QRect(240, 50, 51, 41));
        negative_button = new QPushButton(centralwidget);
        negative_button->setObjectName(QStringLiteral("negative_button"));
        negative_button->setGeometry(QRect(20, 190, 131, 41));
        horizontal_mirror_button = new QPushButton(centralwidget);
        horizontal_mirror_button->setObjectName(QStringLiteral("horizontal_photo_button"));
        horizontal_mirror_button->setGeometry(QRect(20, 240, 131, 41));
        load_button = new QPushButton(centralwidget);
        load_button->setObjectName(QStringLiteral("load_button"));
        load_button->setGeometry(QRect(300, 50, 51, 41));
        copy_button = new QPushButton(centralwidget);
        copy_button->setObjectName(QStringLiteral("copy_button"));
        copy_button->setGeometry(QRect(20, 140, 131, 41));
        vertical_mirror_button = new QPushButton(centralwidget);
        vertical_mirror_button->setObjectName(QStringLiteral("vertical_mirror_button"));
        vertical_mirror_button->setGeometry(QRect(20, 290, 131, 41));
        rotate_button = new QPushButton(centralwidget);
        rotate_button->setObjectName(QStringLiteral("vertical_mirror_button_2"));
        rotate_button->setGeometry(QRect(20, 340, 131, 41));
        grayscale_button = new QPushButton(centralwidget);
        grayscale_button->setObjectName(QStringLiteral("vertical_mirror_button_3"));
        grayscale_button->setGeometry(QRect(20, 390, 131, 41));
        file_path_LineEdit = new QLineEdit(centralwidget);
        file_path_LineEdit->setObjectName(QStringLiteral("file_name_LineEdit"));
        file_path_LineEdit->setGeometry(QRect(460, 490, 311, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 879, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Photos manipulation program", Q_NULLPTR));
        load_path_lineEdit->setText(QApplication::translate("MainWindow", "C:\\Users\\Ja\\Desktop\\MyGallery", Q_NULLPTR));
        delete_button->setText(QApplication::translate("MainWindow", "Delete photo", Q_NULLPTR));
        photo_display_info_lineEdit->setText(QApplication::translate("MainWindow", "Photo preview", Q_NULLPTR));
        next_button->setText(QApplication::translate("MainWindow", "Next", Q_NULLPTR));
        prev_button->setText(QApplication::translate("MainWindow", "Previous", Q_NULLPTR));
        photo_display->setText(QString());
        load_path_info_lineEdit->setText(QApplication::translate("MainWindow", "Path to directory with photos", Q_NULLPTR));
        load_path_button->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        negative_button->setText(QApplication::translate("MainWindow", "Negative photo", Q_NULLPTR));
        horizontal_mirror_button->setText(QApplication::translate("MainWindow", "Mirror photo - horizontal", Q_NULLPTR));
        load_button->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        copy_button->setText(QApplication::translate("MainWindow", "Make copy", Q_NULLPTR));
        vertical_mirror_button->setText(QApplication::translate("MainWindow", "Mirror photo - vertical", Q_NULLPTR));
        rotate_button->setText(QApplication::translate("MainWindow", "Rotate 90* photo", Q_NULLPTR));
        grayscale_button->setText(QApplication::translate("MainWindow", "Grayscale photo", Q_NULLPTR));
        file_path_LineEdit->setText(QApplication::translate("MainWindow", "Current photo file path", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CPPGUI_H
