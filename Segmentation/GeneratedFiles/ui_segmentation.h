/********************************************************************************
** Form generated from reading UI file 'segmentation.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGMENTATION_H
#define UI_SEGMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SegmentationClass
{
public:
    QAction *OpenRGB;
    QAction *OpenDepth;
    QWidget *centralWidget;
    QLabel *timeLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *imageList;
    QPushButton *objButton;
    QPushButton *bkgButton;
    QPushButton *seedButton;
    QRadioButton *gcRadio;
    QRadioButton *gbRadio;
    QRadioButton *mgcRadio;
    QRadioButton *gddRadio;
    QRadioButton *rgbdRadio;
    QRadioButton *ggRadio;
    QRadioButton *hggRadio;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *RGBImage;
    QLabel *depthImage;
    QLabel *seedImage;
    QLabel *resultImage;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SegmentationClass)
    {
        if (SegmentationClass->objectName().isEmpty())
            SegmentationClass->setObjectName(QStringLiteral("SegmentationClass"));
        SegmentationClass->resize(697, 449);
        OpenRGB = new QAction(SegmentationClass);
        OpenRGB->setObjectName(QStringLiteral("OpenRGB"));
        OpenDepth = new QAction(SegmentationClass);
        OpenDepth->setObjectName(QStringLiteral("OpenDepth"));
        centralWidget = new QWidget(SegmentationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(10, 380, 54, 12));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(530, 10, 163, 381));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageList = new QListWidget(layoutWidget);
        imageList->setObjectName(QStringLiteral("imageList"));

        verticalLayout->addWidget(imageList);

        objButton = new QPushButton(layoutWidget);
        objButton->setObjectName(QStringLiteral("objButton"));

        verticalLayout->addWidget(objButton);

        bkgButton = new QPushButton(layoutWidget);
        bkgButton->setObjectName(QStringLiteral("bkgButton"));

        verticalLayout->addWidget(bkgButton);

        seedButton = new QPushButton(layoutWidget);
        seedButton->setObjectName(QStringLiteral("seedButton"));

        verticalLayout->addWidget(seedButton);

        gcRadio = new QRadioButton(layoutWidget);
        gcRadio->setObjectName(QStringLiteral("gcRadio"));

        verticalLayout->addWidget(gcRadio);

        gbRadio = new QRadioButton(layoutWidget);
        gbRadio->setObjectName(QStringLiteral("gbRadio"));

        verticalLayout->addWidget(gbRadio);

        mgcRadio = new QRadioButton(layoutWidget);
        mgcRadio->setObjectName(QStringLiteral("mgcRadio"));

        verticalLayout->addWidget(mgcRadio);

        gddRadio = new QRadioButton(layoutWidget);
        gddRadio->setObjectName(QStringLiteral("gddRadio"));

        verticalLayout->addWidget(gddRadio);

        rgbdRadio = new QRadioButton(layoutWidget);
        rgbdRadio->setObjectName(QStringLiteral("rgbdRadio"));

        verticalLayout->addWidget(rgbdRadio);

        ggRadio = new QRadioButton(layoutWidget);
        ggRadio->setObjectName(QStringLiteral("ggRadio"));

        verticalLayout->addWidget(ggRadio);

        hggRadio = new QRadioButton(layoutWidget);
        hggRadio->setObjectName(QStringLiteral("hggRadio"));

        verticalLayout->addWidget(hggRadio);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 511, 361));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        RGBImage = new QLabel(layoutWidget1);
        RGBImage->setObjectName(QStringLiteral("RGBImage"));
        RGBImage->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(RGBImage, 0, 0, 1, 1);

        depthImage = new QLabel(layoutWidget1);
        depthImage->setObjectName(QStringLiteral("depthImage"));

        gridLayout->addWidget(depthImage, 0, 1, 1, 1);

        seedImage = new QLabel(layoutWidget1);
        seedImage->setObjectName(QStringLiteral("seedImage"));

        gridLayout->addWidget(seedImage, 1, 0, 1, 1);

        resultImage = new QLabel(layoutWidget1);
        resultImage->setObjectName(QStringLiteral("resultImage"));

        gridLayout->addWidget(resultImage, 1, 1, 1, 1);

        SegmentationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SegmentationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 697, 23));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        SegmentationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SegmentationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SegmentationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SegmentationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SegmentationClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuOpen->addAction(OpenRGB);
        menuOpen->addAction(OpenDepth);

        retranslateUi(SegmentationClass);

        QMetaObject::connectSlotsByName(SegmentationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SegmentationClass)
    {
        SegmentationClass->setWindowTitle(QApplication::translate("SegmentationClass", "Segmentation", 0));
        OpenRGB->setText(QApplication::translate("SegmentationClass", "open RGB", 0));
        OpenDepth->setText(QApplication::translate("SegmentationClass", "open Depth", 0));
        timeLabel->setText(QApplication::translate("SegmentationClass", "Time:", 0));
        objButton->setText(QApplication::translate("SegmentationClass", "set object color", 0));
        bkgButton->setText(QApplication::translate("SegmentationClass", "set background color", 0));
        seedButton->setText(QApplication::translate("SegmentationClass", "set seed path", 0));
        gcRadio->setText(QApplication::translate("SegmentationClass", "graph cut", 0));
        gbRadio->setText(QApplication::translate("SegmentationClass", "grab cut", 0));
        mgcRadio->setText(QApplication::translate("SegmentationClass", "multi-level graph cut", 0));
        gddRadio->setText(QApplication::translate("SegmentationClass", "geodesic distance depth", 0));
        rgbdRadio->setText(QApplication::translate("SegmentationClass", "RGBD grapg cut", 0));
        ggRadio->setText(QApplication::translate("SegmentationClass", "GG", 0));
        hggRadio->setText(QApplication::translate("SegmentationClass", "HGG", 0));
        saveButton->setText(QApplication::translate("SegmentationClass", "save", 0));
        RGBImage->setText(QString());
        depthImage->setText(QString());
        seedImage->setText(QString());
        resultImage->setText(QString());
        menuOpen->setTitle(QApplication::translate("SegmentationClass", "open", 0));
    } // retranslateUi

};

namespace Ui {
    class SegmentationClass: public Ui_SegmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATION_H
