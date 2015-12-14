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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
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
    QSlider *brushSizeSlider;
    QLabel *brushSizeText;
    QLineEdit *seedPathEdit;
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *RGBLabel;
    QLabel *depthLabel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *seedLabel;
    QLabel *resultLabel;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *RGBImage;
    QLabel *depthImage;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *seedImage;
    QLabel *resultImage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SegmentationClass)
    {
        if (SegmentationClass->objectName().isEmpty())
            SegmentationClass->setObjectName(QStringLiteral("SegmentationClass"));
        SegmentationClass->resize(697, 481);
        OpenRGB = new QAction(SegmentationClass);
        OpenRGB->setObjectName(QStringLiteral("OpenRGB"));
        OpenDepth = new QAction(SegmentationClass);
        OpenDepth->setObjectName(QStringLiteral("OpenDepth"));
        centralWidget = new QWidget(SegmentationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(10, 410, 54, 12));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(530, 10, 163, 412));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageList = new QListWidget(layoutWidget);
        imageList->setObjectName(QStringLiteral("imageList"));

        verticalLayout->addWidget(imageList);

        brushSizeSlider = new QSlider(layoutWidget);
        brushSizeSlider->setObjectName(QStringLiteral("brushSizeSlider"));
        brushSizeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(brushSizeSlider);

        brushSizeText = new QLabel(layoutWidget);
        brushSizeText->setObjectName(QStringLiteral("brushSizeText"));

        verticalLayout->addWidget(brushSizeText);

        seedPathEdit = new QLineEdit(layoutWidget);
        seedPathEdit->setObjectName(QStringLiteral("seedPathEdit"));

        verticalLayout->addWidget(seedPathEdit);

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

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 511, 20));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        RGBLabel = new QLabel(widget);
        RGBLabel->setObjectName(QStringLiteral("RGBLabel"));

        horizontalLayout_2->addWidget(RGBLabel);

        depthLabel = new QLabel(widget);
        depthLabel->setObjectName(QStringLiteral("depthLabel"));

        horizontalLayout_2->addWidget(depthLabel);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 210, 511, 20));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        seedLabel = new QLabel(widget1);
        seedLabel->setObjectName(QStringLiteral("seedLabel"));

        horizontalLayout_3->addWidget(seedLabel);

        resultLabel = new QLabel(widget1);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));

        horizontalLayout_3->addWidget(resultLabel);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(9, 29, 511, 171));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        RGBImage = new QLabel(widget2);
        RGBImage->setObjectName(QStringLiteral("RGBImage"));
        RGBImage->setFrameShape(QFrame::NoFrame);

        horizontalLayout_4->addWidget(RGBImage);

        depthImage = new QLabel(widget2);
        depthImage->setObjectName(QStringLiteral("depthImage"));

        horizontalLayout_4->addWidget(depthImage);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(10, 230, 511, 171));
        horizontalLayout_5 = new QHBoxLayout(widget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        seedImage = new QLabel(widget3);
        seedImage->setObjectName(QStringLiteral("seedImage"));

        horizontalLayout_5->addWidget(seedImage);

        resultImage = new QLabel(widget3);
        resultImage->setObjectName(QStringLiteral("resultImage"));

        horizontalLayout_5->addWidget(resultImage);

        SegmentationClass->setCentralWidget(centralWidget);
        timeLabel->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        RGBLabel->raise();
        seedLabel->raise();
        depthLabel->raise();
        resultLabel->raise();
        depthLabel->raise();
        mainToolBar = new QToolBar(SegmentationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SegmentationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SegmentationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SegmentationClass->setStatusBar(statusBar);

        retranslateUi(SegmentationClass);

        QMetaObject::connectSlotsByName(SegmentationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SegmentationClass)
    {
        SegmentationClass->setWindowTitle(QApplication::translate("SegmentationClass", "Segmentation", 0));
        OpenRGB->setText(QApplication::translate("SegmentationClass", "open RGB", 0));
        OpenDepth->setText(QApplication::translate("SegmentationClass", "open Depth", 0));
        timeLabel->setText(QApplication::translate("SegmentationClass", "Time:", 0));
        brushSizeText->setText(QApplication::translate("SegmentationClass", "Brush Size:", 0));
        seedButton->setText(QApplication::translate("SegmentationClass", "seed path", 0));
        gcRadio->setText(QApplication::translate("SegmentationClass", "graph cut", 0));
        gbRadio->setText(QApplication::translate("SegmentationClass", "grab cut", 0));
        mgcRadio->setText(QApplication::translate("SegmentationClass", "multi-level graph cut", 0));
        gddRadio->setText(QApplication::translate("SegmentationClass", "geodesic distance depth", 0));
        rgbdRadio->setText(QApplication::translate("SegmentationClass", "RGBD grapg cut", 0));
        ggRadio->setText(QApplication::translate("SegmentationClass", "GG", 0));
        hggRadio->setText(QApplication::translate("SegmentationClass", "HGG", 0));
        saveButton->setText(QApplication::translate("SegmentationClass", "save", 0));
        RGBLabel->setText(QApplication::translate("SegmentationClass", "RGB Image:", 0));
        depthLabel->setText(QApplication::translate("SegmentationClass", "Depth Image:", 0));
        seedLabel->setText(QApplication::translate("SegmentationClass", "Seed Image:", 0));
        resultLabel->setText(QApplication::translate("SegmentationClass", "Result Image:", 0));
        RGBImage->setText(QString());
        depthImage->setText(QString());
        seedImage->setText(QString());
        resultImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SegmentationClass: public Ui_SegmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATION_H
