/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QListWidget *face_listWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_now;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *btn_chbox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioBtn2;
    QRadioButton *radioBtn3;
    QRadioButton *radioBtn1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cam_open;
    QPushButton *cam_close;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *cam_group;
    QHBoxLayout *horizontalLayout;
    QCheckBox *NSblurring_CKB;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *saveindex_btn;
    QPushButton *replay_btn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_2;
    QSlider *video_silder;
    QLabel *label_3;
    QPushButton *play_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1048, 737);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setWindowFilePath(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(700, 500));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(true);
        label->setLocale(QLocale(QLocale::Korean, QLocale::SouthKorea));
        label->setFrameShape(QFrame::Box);
        label->setText(QString::fromUtf8(""));
        label->setScaledContents(false);
        label->setMargin(0);

        horizontalLayout_5->addWidget(label);

        face_listWidget = new QListWidget(centralwidget);
        face_listWidget->setObjectName(QString::fromUtf8("face_listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(face_listWidget->sizePolicy().hasHeightForWidth());
        face_listWidget->setSizePolicy(sizePolicy1);
        face_listWidget->setMinimumSize(QSize(300, 500));

        horizontalLayout_5->addWidget(face_listWidget);

        horizontalLayout_5->setStretch(0, 10);
        horizontalLayout_5->setStretch(1, 4);

        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        label_now = new QLabel(centralwidget);
        label_now->setObjectName(QString::fromUtf8("label_now"));
        label_now->setLayoutDirection(Qt::LeftToRight);
        label_now->setMargin(0);

        horizontalLayout_7->addWidget(label_now);

        horizontalLayout_7->setStretch(0, 7);

        gridLayout->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(20, -1, -1, -1);
        btn_chbox = new QGroupBox(centralwidget);
        btn_chbox->setObjectName(QString::fromUtf8("btn_chbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_chbox->sizePolicy().hasHeightForWidth());
        btn_chbox->setSizePolicy(sizePolicy2);
        horizontalLayout_2 = new QHBoxLayout(btn_chbox);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, 0, 20, 0);
        radioBtn2 = new QRadioButton(btn_chbox);
        radioBtn2->setObjectName(QString::fromUtf8("radioBtn2"));

        horizontalLayout_2->addWidget(radioBtn2);

        radioBtn3 = new QRadioButton(btn_chbox);
        radioBtn3->setObjectName(QString::fromUtf8("radioBtn3"));

        horizontalLayout_2->addWidget(radioBtn3);

        radioBtn1 = new QRadioButton(btn_chbox);
        radioBtn1->setObjectName(QString::fromUtf8("radioBtn1"));

        horizontalLayout_2->addWidget(radioBtn1);


        horizontalLayout_6->addWidget(btn_chbox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(20, 20, 10, 0);
        cam_open = new QPushButton(centralwidget);
        cam_open->setObjectName(QString::fromUtf8("cam_open"));

        horizontalLayout_4->addWidget(cam_open);

        cam_close = new QPushButton(centralwidget);
        cam_close->setObjectName(QString::fromUtf8("cam_close"));
        cam_close->setMouseTracking(false);
        cam_close->setTabletTracking(false);
        cam_close->setAutoFillBackground(false);

        horizontalLayout_4->addWidget(cam_close);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(20, 10, 10, 10);
        cam_group = new QGroupBox(centralwidget);
        cam_group->setObjectName(QString::fromUtf8("cam_group"));
        sizePolicy2.setHeightForWidth(cam_group->sizePolicy().hasHeightForWidth());
        cam_group->setSizePolicy(sizePolicy2);
        cam_group->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(cam_group);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, 0, 0, 0);
        NSblurring_CKB = new QCheckBox(cam_group);
        NSblurring_CKB->setObjectName(QString::fromUtf8("NSblurring_CKB"));

        horizontalLayout->addWidget(NSblurring_CKB);

        horizontalLayout->setStretch(0, 1);

        horizontalLayout_8->addWidget(cam_group);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(20, 20, 20, -1);
        saveindex_btn = new QPushButton(centralwidget);
        saveindex_btn->setObjectName(QString::fromUtf8("saveindex_btn"));

        horizontalLayout_9->addWidget(saveindex_btn);

        replay_btn = new QPushButton(centralwidget);
        replay_btn->setObjectName(QString::fromUtf8("replay_btn"));
        replay_btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(replay_btn);


        horizontalLayout_8->addLayout(horizontalLayout_9);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, -1, 10, -1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(65, 16777215));
        label_2->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(label_2);

        video_silder = new QSlider(centralwidget);
        video_silder->setObjectName(QString::fromUtf8("video_silder"));
        video_silder->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(video_silder);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(65, 16777215));

        horizontalLayout_3->addWidget(label_3);

        play_btn = new QPushButton(centralwidget);
        play_btn->setObjectName(QString::fromUtf8("play_btn"));
        play_btn->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(play_btn);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 4);
        horizontalLayout_3->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QString());
        label_now->setText(QString());
        btn_chbox->setTitle(QCoreApplication::translate("MainWindow", "Choose Media Type", nullptr));
        radioBtn2->setText(QCoreApplication::translate("MainWindow", "cam 29", nullptr));
        radioBtn3->setText(QCoreApplication::translate("MainWindow", "cam 180", nullptr));
        radioBtn1->setText(QCoreApplication::translate("MainWindow", "video", nullptr));
        cam_open->setText(QCoreApplication::translate("MainWindow", "1. Open", nullptr));
        cam_close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        cam_group->setTitle(QCoreApplication::translate("MainWindow", "NSprocess", nullptr));
        NSblurring_CKB->setText(QCoreApplication::translate("MainWindow", "Blurring", nullptr));
        saveindex_btn->setText(QCoreApplication::translate("MainWindow", " 2. Save Start ", nullptr));
        replay_btn->setText(QCoreApplication::translate("MainWindow", "4. Face View", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        play_btn->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
