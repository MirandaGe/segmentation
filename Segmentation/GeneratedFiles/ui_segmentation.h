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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *RGBLabel;
    QLabel *depthLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *RGBImage;
    QLabel *depthImage;
    QHBoxLayout *horizontalLayout_3;
    QLabel *seedLabel;
    QLabel *resultLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *seedImage;
    QLabel *resultImage;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *seedPathEdit;
    QPushButton *seedButton;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *resultPathEdit;
    QPushButton *resultButton;
    QVBoxLayout *verticalLayout;
    QListWidget *imageList;
    QLabel *methodLabel;
    QRadioButton *gcRadio;
    QRadioButton *gbRadio;
    QRadioButton *mgcRadio;
    QRadioButton *gddRadio;
    QRadioButton *rgbdRadio;
    QRadioButton *ggRadio;
    QRadioButton *hggRadio;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *timeLineEdit;
    QLabel *msLabel;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *segmentButton;
    QPushButton *saveButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SegmentationClass)
    {
        if (SegmentationClass->objectName().isEmpty())
            SegmentationClass->setObjectName(QStringLiteral("SegmentationClass"));
        SegmentationClass->resize(929, 632);
        OpenRGB = new QAction(SegmentationClass);
        OpenRGB->setObjectName(QStringLiteral("OpenRGB"));
        OpenDepth = new QAction(SegmentationClass);
        OpenDepth->setObjectName(QStringLiteral("OpenDepth"));
        centralWidget = new QWidget(SegmentationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        RGBLabel = new QLabel(centralWidget);
        RGBLabel->setObjectName(QStringLiteral("RGBLabel"));

        horizontalLayout_2->addWidget(RGBLabel);

        depthLabel = new QLabel(centralWidget);
        depthLabel->setObjectName(QStringLiteral("depthLabel"));

        horizontalLayout_2->addWidget(depthLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        RGBImage = new QLabel(centralWidget);
        RGBImage->setObjectName(QStringLiteral("RGBImage"));
        RGBImage->setMinimumSize(QSize(320, 240));
        RGBImage->setMaximumSize(QSize(400, 300));
        RGBImage->setCursor(QCursor(Qt::ArrowCursor));
        RGBImage->setLayoutDirection(Qt::LeftToRight);
        RGBImage->setFrameShape(QFrame::NoFrame);
        RGBImage->setScaledContents(false);
        RGBImage->setWordWrap(false);

        horizontalLayout_4->addWidget(RGBImage);

        depthImage = new QLabel(centralWidget);
        depthImage->setObjectName(QStringLiteral("depthImage"));
        depthImage->setMinimumSize(QSize(320, 240));
        depthImage->setMaximumSize(QSize(400, 300));

        horizontalLayout_4->addWidget(depthImage);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        seedLabel = new QLabel(centralWidget);
        seedLabel->setObjectName(QStringLiteral("seedLabel"));

        horizontalLayout_3->addWidget(seedLabel);

        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));

        horizontalLayout_3->addWidget(resultLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        seedImage = new QLabel(centralWidget);
        seedImage->setObjectName(QStringLiteral("seedImage"));
        seedImage->setMinimumSize(QSize(320, 240));
        seedImage->setMaximumSize(QSize(400, 300));

        horizontalLayout_5->addWidget(seedImage);

        resultImage = new QLabel(centralWidget);
        resultImage->setObjectName(QStringLiteral("resultImage"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(resultImage->sizePolicy().hasHeightForWidth());
        resultImage->setSizePolicy(sizePolicy);
        resultImage->setMinimumSize(QSize(320, 240));
        resultImage->setMaximumSize(QSize(400, 300));

        horizontalLayout_5->addWidget(resultImage);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        seedPathEdit = new QLineEdit(centralWidget);
        seedPathEdit->setObjectName(QStringLiteral("seedPathEdit"));
        seedPathEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(seedPathEdit);

        seedButton = new QPushButton(centralWidget);
        seedButton->setObjectName(QStringLiteral("seedButton"));

        horizontalLayout_6->addWidget(seedButton);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        resultPathEdit = new QLineEdit(centralWidget);
        resultPathEdit->setObjectName(QStringLiteral("resultPathEdit"));
        resultPathEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(resultPathEdit);

        resultButton = new QPushButton(centralWidget);
        resultButton->setObjectName(QStringLiteral("resultButton"));

        horizontalLayout_7->addWidget(resultButton);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_11->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        imageList = new QListWidget(centralWidget);
        imageList->setObjectName(QStringLiteral("imageList"));

        verticalLayout->addWidget(imageList);

        methodLabel = new QLabel(centralWidget);
        methodLabel->setObjectName(QStringLiteral("methodLabel"));

        verticalLayout->addWidget(methodLabel);

        gcRadio = new QRadioButton(centralWidget);
        gcRadio->setObjectName(QStringLiteral("gcRadio"));

        verticalLayout->addWidget(gcRadio);

        gbRadio = new QRadioButton(centralWidget);
        gbRadio->setObjectName(QStringLiteral("gbRadio"));

        verticalLayout->addWidget(gbRadio);

        mgcRadio = new QRadioButton(centralWidget);
        mgcRadio->setObjectName(QStringLiteral("mgcRadio"));

        verticalLayout->addWidget(mgcRadio);

        gddRadio = new QRadioButton(centralWidget);
        gddRadio->setObjectName(QStringLiteral("gddRadio"));

        verticalLayout->addWidget(gddRadio);

        rgbdRadio = new QRadioButton(centralWidget);
        rgbdRadio->setObjectName(QStringLiteral("rgbdRadio"));

        verticalLayout->addWidget(rgbdRadio);

        ggRadio = new QRadioButton(centralWidget);
        ggRadio->setObjectName(QStringLiteral("ggRadio"));

        verticalLayout->addWidget(ggRadio);

        hggRadio = new QRadioButton(centralWidget);
        hggRadio->setObjectName(QStringLiteral("hggRadio"));
        hggRadio->setChecked(true);

        verticalLayout->addWidget(hggRadio);

        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout->addWidget(timeLabel);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        timeLineEdit = new QLineEdit(centralWidget);
        timeLineEdit->setObjectName(QStringLiteral("timeLineEdit"));
        timeLineEdit->setReadOnly(true);

        horizontalLayout_9->addWidget(timeLineEdit);

        msLabel = new QLabel(centralWidget);
        msLabel->setObjectName(QStringLiteral("msLabel"));

        horizontalLayout_9->addWidget(msLabel);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        segmentButton = new QPushButton(centralWidget);
        segmentButton->setObjectName(QStringLiteral("segmentButton"));

        horizontalLayout_10->addWidget(segmentButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_10->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_11->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_11, 0, 0, 1, 1);

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
        RGBImage->setText(QString());
        depthImage->setText(QString());
        seedLabel->setText(QApplication::translate("SegmentationClass", "Seed Image:", 0));
        resultLabel->setText(QApplication::translate("SegmentationClass", "Result Image:", 0));
        seedImage->setText(QString());
        resultImage->setText(QString());
        seedButton->setText(QApplication::translate("SegmentationClass", "seed path", 0));
        resultButton->setText(QApplication::translate("SegmentationClass", "result path", 0));
        methodLabel->setText(QApplication::translate("SegmentationClass", "Choose a method:", 0));
        gcRadio->setText(QApplication::translate("SegmentationClass", "graph cut", 0));
        gbRadio->setText(QApplication::translate("SegmentationClass", "grab cut", 0));
        mgcRadio->setText(QApplication::translate("SegmentationClass", "multi-level graph cut", 0));
        gddRadio->setText(QApplication::translate("SegmentationClass", "geodesic distance depth", 0));
        rgbdRadio->setText(QApplication::translate("SegmentationClass", "RGBD grapg cut", 0));
        ggRadio->setText(QApplication::translate("SegmentationClass", "GG", 0));
        hggRadio->setText(QApplication::translate("SegmentationClass", "HGG", 0));
        timeLabel->setText(QApplication::translate("SegmentationClass", "Average Time per Interaction:", 0));
        msLabel->setText(QApplication::translate("SegmentationClass", "ms", 0));
        segmentButton->setText(QApplication::translate("SegmentationClass", "segment", 0));
        saveButton->setText(QApplication::translate("SegmentationClass", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class SegmentationClass: public Ui_SegmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATION_H
