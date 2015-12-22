/********************************************************************************
** Form generated from reading UI file 'interactionsegment.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIONSEGMENT_H
#define UI_INTERACTIONSEGMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <scribblearea.h>

QT_BEGIN_NAMESPACE

class Ui_InteractionSegment
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    ScribbleArea *ScribbleWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *brushLabel;
    QSpinBox *brushSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *foreButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *segmentButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clearButton;
    QPushButton *okButton;

    void setupUi(QDialog *InteractionSegment)
    {
        if (InteractionSegment->objectName().isEmpty())
            InteractionSegment->setObjectName(QStringLiteral("InteractionSegment"));
        InteractionSegment->resize(563, 94);
        verticalLayout_2 = new QVBoxLayout(InteractionSegment);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ScribbleWidget = new ScribbleArea(InteractionSegment);
        ScribbleWidget->setObjectName(QStringLiteral("ScribbleWidget"));

        verticalLayout->addWidget(ScribbleWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        brushLabel = new QLabel(InteractionSegment);
        brushLabel->setObjectName(QStringLiteral("brushLabel"));

        horizontalLayout->addWidget(brushLabel);

        brushSpinBox = new QSpinBox(InteractionSegment);
        brushSpinBox->setObjectName(QStringLiteral("brushSpinBox"));
        brushSpinBox->setMinimum(1);
        brushSpinBox->setMaximum(15);
        brushSpinBox->setValue(8);

        horizontalLayout->addWidget(brushSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        foreButton = new QPushButton(InteractionSegment);
        foreButton->setObjectName(QStringLiteral("foreButton"));

        horizontalLayout->addWidget(foreButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        backButton = new QPushButton(InteractionSegment);
        backButton->setObjectName(QStringLiteral("backButton"));

        horizontalLayout->addWidget(backButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        segmentButton = new QPushButton(InteractionSegment);
        segmentButton->setObjectName(QStringLiteral("segmentButton"));

        horizontalLayout->addWidget(segmentButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        clearButton = new QPushButton(InteractionSegment);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        okButton = new QPushButton(InteractionSegment);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(InteractionSegment);

        QMetaObject::connectSlotsByName(InteractionSegment);
    } // setupUi

    void retranslateUi(QDialog *InteractionSegment)
    {
        InteractionSegment->setWindowTitle(QApplication::translate("InteractionSegment", "InteractionSegment", 0));
        brushLabel->setText(QApplication::translate("InteractionSegment", "Brush size:", 0));
        foreButton->setText(QApplication::translate("InteractionSegment", "foreground", 0));
        backButton->setText(QApplication::translate("InteractionSegment", "background", 0));
        segmentButton->setText(QApplication::translate("InteractionSegment", "segment", 0));
        clearButton->setText(QApplication::translate("InteractionSegment", "clear", 0));
        okButton->setText(QApplication::translate("InteractionSegment", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class InteractionSegment: public Ui_InteractionSegment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIONSEGMENT_H
