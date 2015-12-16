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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *RGBLabel;
    QLabel *depthLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *seedLabel;
    QLabel *resultLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *RGBImage;
    QLabel *depthImage;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *seedImage;
    QLabel *resultImage;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *seedPathEdit;
    QPushButton *seedButton;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *resultPathEdit;
    QPushButton *resultButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout;
    QListWidget *imageList;
    QHBoxLayout *horizontalLayout;
    QLabel *brushSizeText;
    QSpinBox *spinBox;
    QLabel *label;
    QRadioButton *gcRadio;
    QRadioButton *gbRadio;
    QRadioButton *mgcRadio;
    QRadioButton *gddRadio;
    QRadioButton *rgbdRadio;
    QRadioButton *ggRadio;
    QRadioButton *hggRadio;
    QLabel *timeLabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SegmentationClass)
    {
        if (SegmentationClass->objectName().isEmpty())
            SegmentationClass->setObjectName(QStringLiteral("SegmentationClass"));
        SegmentationClass->resize(701, 487);
        OpenRGB = new QAction(SegmentationClass);
        OpenRGB->setObjectName(QStringLiteral("OpenRGB"));
        OpenDepth = new QAction(SegmentationClass);
        OpenDepth->setObjectName(QStringLiteral("OpenDepth"));
        centralWidget = new QWidget(SegmentationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 511, 20));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        RGBLabel = new QLabel(layoutWidget);
        RGBLabel->setObjectName(QStringLiteral("RGBLabel"));

        horizontalLayout_2->addWidget(RGBLabel);

        depthLabel = new QLabel(layoutWidget);
        depthLabel->setObjectName(QStringLiteral("depthLabel"));

        horizontalLayout_2->addWidget(depthLabel);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 200, 511, 20));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        seedLabel = new QLabel(layoutWidget1);
        seedLabel->setObjectName(QStringLiteral("seedLabel"));

        horizontalLayout_3->addWidget(seedLabel);

        resultLabel = new QLabel(layoutWidget1);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));

        horizontalLayout_3->addWidget(resultLabel);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(9, 19, 511, 171));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        RGBImage = new QLabel(layoutWidget2);
        RGBImage->setObjectName(QStringLiteral("RGBImage"));
        RGBImage->setFrameShape(QFrame::NoFrame);

        horizontalLayout_4->addWidget(RGBImage);

        depthImage = new QLabel(layoutWidget2);
        depthImage->setObjectName(QStringLiteral("depthImage"));

        horizontalLayout_4->addWidget(depthImage);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 220, 511, 171));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        seedImage = new QLabel(layoutWidget3);
        seedImage->setObjectName(QStringLiteral("seedImage"));

        horizontalLayout_5->addWidget(seedImage);

        resultImage = new QLabel(layoutWidget3);
        resultImage->setObjectName(QStringLiteral("resultImage"));

        horizontalLayout_5->addWidget(resultImage);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 400, 681, 27));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        seedPathEdit = new QLineEdit(layoutWidget4);
        seedPathEdit->setObjectName(QStringLiteral("seedPathEdit"));

        horizontalLayout_6->addWidget(seedPathEdit);

        seedButton = new QPushButton(layoutWidget4);
        seedButton->setObjectName(QStringLiteral("seedButton"));

        horizontalLayout_6->addWidget(seedButton);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        resultPathEdit = new QLineEdit(layoutWidget4);
        resultPathEdit->setObjectName(QStringLiteral("resultPathEdit"));

        horizontalLayout_7->addWidget(resultPathEdit);

        resultButton = new QPushButton(layoutWidget4);
        resultButton->setObjectName(QStringLiteral("resultButton"));

        horizontalLayout_7->addWidget(resultButton);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        saveButton = new QPushButton(layoutWidget4);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_8->addWidget(saveButton);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(531, 1, 163, 391));
        verticalLayout = new QVBoxLayout(layoutWidget5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageList = new QListWidget(layoutWidget5);
        imageList->setObjectName(QStringLiteral("imageList"));

        verticalLayout->addWidget(imageList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        brushSizeText = new QLabel(layoutWidget5);
        brushSizeText->setObjectName(QStringLiteral("brushSizeText"));

        horizontalLayout->addWidget(brushSizeText);

        spinBox = new QSpinBox(layoutWidget5);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(10);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(layoutWidget5);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        gcRadio = new QRadioButton(layoutWidget5);
        gcRadio->setObjectName(QStringLiteral("gcRadio"));

        verticalLayout->addWidget(gcRadio);

        gbRadio = new QRadioButton(layoutWidget5);
        gbRadio->setObjectName(QStringLiteral("gbRadio"));

        verticalLayout->addWidget(gbRadio);

        mgcRadio = new QRadioButton(layoutWidget5);
        mgcRadio->setObjectName(QStringLiteral("mgcRadio"));

        verticalLayout->addWidget(mgcRadio);

        gddRadio = new QRadioButton(layoutWidget5);
        gddRadio->setObjectName(QStringLiteral("gddRadio"));

        verticalLayout->addWidget(gddRadio);

        rgbdRadio = new QRadioButton(layoutWidget5);
        rgbdRadio->setObjectName(QStringLiteral("rgbdRadio"));

        verticalLayout->addWidget(rgbdRadio);

        ggRadio = new QRadioButton(layoutWidget5);
        ggRadio->setObjectName(QStringLiteral("ggRadio"));

        verticalLayout->addWidget(ggRadio);

        hggRadio = new QRadioButton(layoutWidget5);
        hggRadio->setObjectName(QStringLiteral("hggRadio"));

        verticalLayout->addWidget(hggRadio);

        timeLabel = new QLabel(layoutWidget5);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout->addWidget(timeLabel);

        SegmentationClass->setCentralWidget(centralWidget);
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
        RGBLabel->setText(QApplication::translate("SegmentationClass", "RGB Image:", 0));
        depthLabel->setText(QApplication::translate("SegmentationClass", "Depth Image:", 0));
        seedLabel->setText(QApplication::translate("SegmentationClass", "Seed Image:", 0));
        resultLabel->setText(QApplication::translate("SegmentationClass", "Result Image:", 0));
        RGBImage->setText(QString());
        depthImage->setText(QString());
        seedImage->setText(QString());
        resultImage->setText(QString());
        seedButton->setText(QApplication::translate("SegmentationClass", "seed path", 0));
        resultButton->setText(QApplication::translate("SegmentationClass", "result path", 0));
        saveButton->setText(QApplication::translate("SegmentationClass", "save", 0));
        brushSizeText->setText(QApplication::translate("SegmentationClass", "Brush Size:", 0));
        label->setText(QApplication::translate("SegmentationClass", "Choose a method:", 0));
        gcRadio->setText(QApplication::translate("SegmentationClass", "graph cut", 0));
        gbRadio->setText(QApplication::translate("SegmentationClass", "grab cut", 0));
        mgcRadio->setText(QApplication::translate("SegmentationClass", "multi-level graph cut", 0));
        gddRadio->setText(QApplication::translate("SegmentationClass", "geodesic distance depth", 0));
        rgbdRadio->setText(QApplication::translate("SegmentationClass", "RGBD grapg cut", 0));
        ggRadio->setText(QApplication::translate("SegmentationClass", "GG", 0));
        hggRadio->setText(QApplication::translate("SegmentationClass", "HGG", 0));
        timeLabel->setText(QApplication::translate("SegmentationClass", "Time:", 0));
    } // retranslateUi

};

namespace Ui {
    class SegmentationClass: public Ui_SegmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATION_H
