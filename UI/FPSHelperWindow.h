/********************************************************************************
** Form generated from reading UI file 'FPSHelperWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FPSHELPERWINDOW_H
#define FPSHELPERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../Control/ControlModel.h"

QT_BEGIN_NAMESPACE

class Ui_FPSHelperWindow
{
public:
    QAction *actionAuthor;
    QAction *actionHelp;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *fileChooseParamButton;
    QPushButton *fileChooseBinButton;
    QPushButton *configureAIModelConfirmButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *confidenceThresholdSpinBox;
    QDoubleSpinBox *nmsThresholdSpinBox;
    QCheckBox *gpuCheckBox;
    QSpinBox *cpuThreadSpinBox;
    QPushButton *configureEngineConfirmButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QComboBox *modeCombBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_13;
    QComboBox *controlModeComb;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QComboBox *imageSourceComb;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_15;
    QSpinBox *frameRateSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *startButton;
    QPushButton *stopButton;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FPSHelperWindow)
    {
        if (FPSHelperWindow->objectName().isEmpty())
            FPSHelperWindow->setObjectName(QString::fromUtf8("FPSHelperWindow"));
        FPSHelperWindow->resize(335, 655);
        actionAuthor = new QAction(FPSHelperWindow);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        actionHelp = new QAction(FPSHelperWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralwidget = new QWidget(FPSHelperWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font;
        font.setPointSize(20);
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_11);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color:red"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_12);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(15);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("SimSun-ExtB"));
        font3.setPointSize(12);
        label->setFont(font3);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fileChooseParamButton = new QPushButton(groupBox);
        fileChooseParamButton->setObjectName(QString::fromUtf8("fileChooseParamButton"));

        verticalLayout_2->addWidget(fileChooseParamButton);

        fileChooseBinButton = new QPushButton(groupBox);
        fileChooseBinButton->setObjectName(QString::fromUtf8("fileChooseBinButton"));

        verticalLayout_2->addWidget(fileChooseBinButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        configureAIModelConfirmButton = new QPushButton(groupBox);
        configureAIModelConfirmButton->setObjectName(QString::fromUtf8("configureAIModelConfirmButton"));
        configureAIModelConfirmButton->setFont(font2);

        verticalLayout_3->addWidget(configureAIModelConfirmButton);


        verticalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(false);
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_8);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        confidenceThresholdSpinBox = new QDoubleSpinBox(groupBox_2);
        confidenceThresholdSpinBox->setObjectName(QString::fromUtf8("confidenceThresholdSpinBox"));
        confidenceThresholdSpinBox->setMinimum(0.100000000000000);
        confidenceThresholdSpinBox->setMaximum(1.000000000000000);
        confidenceThresholdSpinBox->setSingleStep(0.100000000000000);
        confidenceThresholdSpinBox->setValue(0.700000000000000);

        verticalLayout_5->addWidget(confidenceThresholdSpinBox);

        nmsThresholdSpinBox = new QDoubleSpinBox(groupBox_2);
        nmsThresholdSpinBox->setObjectName(QString::fromUtf8("nmsThresholdSpinBox"));
        nmsThresholdSpinBox->setMinimum(0.100000000000000);
        nmsThresholdSpinBox->setMaximum(1.000000000000000);
        nmsThresholdSpinBox->setSingleStep(0.100000000000000);
        nmsThresholdSpinBox->setValue(0.450000000000000);

        verticalLayout_5->addWidget(nmsThresholdSpinBox);

        gpuCheckBox = new QCheckBox(groupBox_2);
        gpuCheckBox->setObjectName(QString::fromUtf8("gpuCheckBox"));

        verticalLayout_5->addWidget(gpuCheckBox);

        cpuThreadSpinBox = new QSpinBox(groupBox_2);
        cpuThreadSpinBox->setObjectName(QString::fromUtf8("cpuThreadSpinBox"));
        cpuThreadSpinBox->setMaximum(20);
        cpuThreadSpinBox->setValue(4);
        cpuThreadSpinBox->setDisplayIntegerBase(10);

        verticalLayout_5->addWidget(cpuThreadSpinBox);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        configureEngineConfirmButton = new QPushButton(groupBox_2);
        configureEngineConfirmButton->setObjectName(QString::fromUtf8("configureEngineConfirmButton"));
        configureEngineConfirmButton->setFont(font2);

        verticalLayout_6->addWidget(configureEngineConfirmButton);


        verticalLayout_8->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(false);
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_9);

        modeCombBox = new QComboBox(groupBox_3);
        modeCombBox->setObjectName(QString::fromUtf8("modeCombBox"));

        horizontalLayout_3->addWidget(modeCombBox);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font3);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_13);

        controlModeComb = new QComboBox(groupBox_3);
        controlModeComb->setObjectName(QString::fromUtf8("controlModeComb"));

        horizontalLayout_5->addWidget(controlModeComb);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_14);

        imageSourceComb = new QComboBox(groupBox_3);
        imageSourceComb->setObjectName(QString::fromUtf8("imageSourceComb"));

        horizontalLayout_6->addWidget(imageSourceComb);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font3);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_15);

        frameRateSpinBox = new QSpinBox(groupBox_3);
        frameRateSpinBox->setObjectName(QString::fromUtf8("frameRateSpinBox"));
        frameRateSpinBox->setMaximum(100);
        frameRateSpinBox->setValue(4);
        frameRateSpinBox->setDisplayIntegerBase(10);

        horizontalLayout_7->addWidget(frameRateSpinBox);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        startButton = new QPushButton(groupBox_3);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout_4->addWidget(startButton);

        stopButton = new QPushButton(groupBox_3);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout_4->addWidget(stopButton);


        verticalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_8->addWidget(groupBox_3);

        FPSHelperWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FPSHelperWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 335, 21));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        FPSHelperWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FPSHelperWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FPSHelperWindow->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());
        menuAbout->addSeparator();

        retranslateUi(FPSHelperWindow);
        QObject::connect(fileChooseParamButton, SIGNAL(clicked()), FPSHelperWindow, SLOT(chooseParam()));
        QObject::connect(fileChooseBinButton, SIGNAL(clicked()), FPSHelperWindow, SLOT(chooseBin()));
        QObject::connect(configureAIModelConfirmButton, SIGNAL(clicked()), FPSHelperWindow, SLOT(confirmAIModel()));
        QObject::connect(configureEngineConfirmButton, SIGNAL(clicked()), FPSHelperWindow, SLOT(confirmAIEngine()));
        QObject::connect(startButton, SIGNAL(clicked()), FPSHelperWindow, SLOT(start()));
        QObject::connect(stopButton, SIGNAL(clicked()), FPSHelperWindow, SLOT(stop()));

        QMetaObject::connectSlotsByName(FPSHelperWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FPSHelperWindow)
    {
        FPSHelperWindow->setWindowTitle(QCoreApplication::translate("FPSHelperWindow", "FPSHelperWindow", nullptr));
        actionAuthor->setText(QCoreApplication::translate("FPSHelperWindow", "Author", nullptr));
        actionHelp->setText(QCoreApplication::translate("FPSHelperWindow", "Help", nullptr));
        label_11->setText(QCoreApplication::translate("FPSHelperWindow", "FPS AI Helper", nullptr));
        label_12->setText(QCoreApplication::translate("FPSHelperWindow", "For research ONLY!!", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FPSHelperWindow", "Step 1:", nullptr));
        label_3->setText(QCoreApplication::translate("FPSHelperWindow", "Configure AI Model", nullptr));
        label->setText(QCoreApplication::translate("FPSHelperWindow", "Choose .param file", nullptr));
        label_2->setText(QCoreApplication::translate("FPSHelperWindow", "Choose .bin file", nullptr));
        fileChooseParamButton->setText(QCoreApplication::translate("FPSHelperWindow", "\351\200\211\346\213\251", nullptr));
        fileChooseBinButton->setText(QCoreApplication::translate("FPSHelperWindow", "\351\200\211\346\213\251", nullptr));
        configureAIModelConfirmButton->setText(QCoreApplication::translate("FPSHelperWindow", "Confirm", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FPSHelperWindow", "Step 2:", nullptr));
        label_4->setText(QCoreApplication::translate("FPSHelperWindow", "Configure AI Engine", nullptr));
        label_5->setText(QCoreApplication::translate("FPSHelperWindow", "Confidence Threshold", nullptr));
        label_6->setText(QCoreApplication::translate("FPSHelperWindow", "NMS Threshold", nullptr));
        label_7->setText(QCoreApplication::translate("FPSHelperWindow", "GPU Boost", nullptr));
        label_8->setText(QCoreApplication::translate("FPSHelperWindow", "CPU Threads", nullptr));
        gpuCheckBox->setText(QCoreApplication::translate("FPSHelperWindow", "GPU Not available", nullptr));
        configureEngineConfirmButton->setText(QCoreApplication::translate("FPSHelperWindow", "Confirm", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FPSHelperWindow", "Step 3:", nullptr));
        label_10->setText(QCoreApplication::translate("FPSHelperWindow", "Start", nullptr));
        label_9->setText(QCoreApplication::translate("FPSHelperWindow", "Assistant Mode", nullptr));
        label_13->setText(QCoreApplication::translate("FPSHelperWindow", "Control Executor", nullptr));
        label_14->setText(QCoreApplication::translate("FPSHelperWindow", "Image Source", nullptr));
        label_15->setText(QCoreApplication::translate("FPSHelperWindow", "Frame Rate", nullptr));
        startButton->setText(QCoreApplication::translate("FPSHelperWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("FPSHelperWindow", "Stop", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("FPSHelperWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FPSHelperWindow: public QMainWindow, public Ui_FPSHelperWindow {
    Q_OBJECT
    public:
        FPSHelperWindow(QWidget *parent = nullptr, ControlModel::ControlInterface *controlInterface = nullptr);

        ~FPSHelperWindow() override;

    private:
        ControlModel::ControlInterface *controlInterface = nullptr;
        bool binChosen = false;
        bool paramChosen = false;
    private Q_SLOTS:

        void chooseParam();

        void chooseBin();

        void confirmAIModel();

        void confirmAIEngine();

        void start();

        void stop();
    };
} // namespace Ui


QT_END_NAMESPACE

#endif // FPSHELPERWINDOW_H
