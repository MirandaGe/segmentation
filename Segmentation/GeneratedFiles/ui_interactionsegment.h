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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InteractionSegment
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *foreButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *segmentButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *InteractionSegment)
    {
        if (InteractionSegment->objectName().isEmpty())
            InteractionSegment->setObjectName(QStringLiteral("InteractionSegment"));
        InteractionSegment->resize(439, 406);
        verticalLayout_2 = new QVBoxLayout(InteractionSegment);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageLabel = new QLabel(InteractionSegment);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(imageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
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

        cancelButton = new QPushButton(InteractionSegment);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(InteractionSegment);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(InteractionSegment);
        QObject::connect(segmentButton, SIGNAL(clicked()), InteractionSegment, SLOT(accept()));

        QMetaObject::connectSlotsByName(InteractionSegment);
    } // setupUi

    void retranslateUi(QDialog *InteractionSegment)
    {
        InteractionSegment->setWindowTitle(QApplication::translate("InteractionSegment", "InteractionSegment", 0));
        imageLabel->setText(QString());
        foreButton->setText(QApplication::translate("InteractionSegment", "foreground", 0));
        backButton->setText(QApplication::translate("InteractionSegment", "background", 0));
        segmentButton->setText(QApplication::translate("InteractionSegment", "segment", 0));
        cancelButton->setText(QApplication::translate("InteractionSegment", "Cancel", 0));
        okButton->setText(QApplication::translate("InteractionSegment", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class InteractionSegment: public Ui_InteractionSegment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIONSEGMENT_H
