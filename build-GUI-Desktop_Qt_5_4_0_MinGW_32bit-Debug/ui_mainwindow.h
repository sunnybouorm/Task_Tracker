/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionTasks;
    QAction *actionAdd_tasks_and_Categories;
    QWidget *centralWidget;
    QTabWidget *main_tabWidget;
    QWidget *taskActivation;
    QGroupBox *activation_groupBox;
    QLCDNumber *activeTimer_LCD;
    QPushButton *activation_pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *activeTask_comboBox;
    QLabel *task_label;
    QToolButton *task_toolButton;
    QLabel *category_label;
    QComboBox *categoryFilter_comboBox;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGraphicsView *graphicsView;
    QWidget *tab_4;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QComboBox *comboBox_3;
    QLabel *label_7;
    QGraphicsView *graphicsView_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGroupBox *groupBox_4;
    QTreeView *treeView;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QLabel *label_4;
    QLineEdit *StatusReporter;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuSetup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1079, 670);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionTasks = new QAction(MainWindow);
        actionTasks->setObjectName(QStringLiteral("actionTasks"));
        actionAdd_tasks_and_Categories = new QAction(MainWindow);
        actionAdd_tasks_and_Categories->setObjectName(QStringLiteral("actionAdd_tasks_and_Categories"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        main_tabWidget = new QTabWidget(centralWidget);
        main_tabWidget->setObjectName(QStringLiteral("main_tabWidget"));
        main_tabWidget->setGeometry(QRect(20, 10, 991, 571));
        taskActivation = new QWidget();
        taskActivation->setObjectName(QStringLiteral("taskActivation"));
        activation_groupBox = new QGroupBox(taskActivation);
        activation_groupBox->setObjectName(QStringLiteral("activation_groupBox"));
        activation_groupBox->setGeometry(QRect(40, 10, 911, 501));
        activeTimer_LCD = new QLCDNumber(activation_groupBox);
        activeTimer_LCD->setObjectName(QStringLiteral("activeTimer_LCD"));
        activeTimer_LCD->setGeometry(QRect(140, 260, 601, 211));
        activeTimer_LCD->setSmallDecimalPoint(false);
        activeTimer_LCD->setMode(QLCDNumber::Dec);
        activeTimer_LCD->setSegmentStyle(QLCDNumber::Flat);
        activation_pushButton = new QPushButton(activation_groupBox);
        activation_pushButton->setObjectName(QStringLiteral("activation_pushButton"));
        activation_pushButton->setGeometry(QRect(210, 100, 451, 151));
        activation_pushButton->setAutoFillBackground(false);
        gridLayoutWidget = new QWidget(activation_groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(250, 20, 371, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        activeTask_comboBox = new QComboBox(gridLayoutWidget);
        activeTask_comboBox->setObjectName(QStringLiteral("activeTask_comboBox"));
        activeTask_comboBox->setEditable(true);

        gridLayout->addWidget(activeTask_comboBox, 0, 1, 1, 1);

        task_label = new QLabel(gridLayoutWidget);
        task_label->setObjectName(QStringLiteral("task_label"));
        task_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(task_label, 0, 0, 1, 1);

        task_toolButton = new QToolButton(gridLayoutWidget);
        task_toolButton->setObjectName(QStringLiteral("task_toolButton"));

        gridLayout->addWidget(task_toolButton, 0, 2, 1, 1);

        category_label = new QLabel(gridLayoutWidget);
        category_label->setObjectName(QStringLiteral("category_label"));
        category_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(category_label, 1, 0, 1, 1);

        categoryFilter_comboBox = new QComboBox(gridLayoutWidget);
        categoryFilter_comboBox->setObjectName(QStringLiteral("categoryFilter_comboBox"));
        categoryFilter_comboBox->setEditable(false);

        gridLayout->addWidget(categoryFilter_comboBox, 1, 1, 1, 1);

        main_tabWidget->addTab(taskActivation, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(400, 40, 591, 521));
        tabWidget_2 = new QTabWidget(groupBox);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(40, 30, 521, 331));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(90, 20, 351, 281));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        formLayoutWidget = new QWidget(tab_4);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 260, 321, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_3 = new QComboBox(formLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_3);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        graphicsView_2 = new QGraphicsView(tab_4);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(25, 30, 481, 221));
        tabWidget_2->addTab(tab_4, QString());
        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(110, 370, 401, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_10 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_3->addWidget(pushButton_10);

        pushButton_8 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_3->addWidget(pushButton_9);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 40, 361, 481));
        treeView = new QTreeView(groupBox_4);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(20, 70, 256, 192));
        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 290, 271, 91));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 251, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_4 = new QComboBox(gridLayoutWidget_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setEditable(true);

        gridLayout_2->addWidget(comboBox_4, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        checkBox = new QCheckBox(gridLayoutWidget_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 71, 16));
        main_tabWidget->addTab(tab_2, QString());
        StatusReporter = new QLineEdit(centralWidget);
        StatusReporter->setObjectName(QStringLiteral("StatusReporter"));
        StatusReporter->setGeometry(QRect(20, 590, 601, 20));
        StatusReporter->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1079, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QStringLiteral("menuSetup"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuSetup->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionTasks);
        menuSetup->addAction(actionAdd_tasks_and_Categories);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        main_tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Task Tracker", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionTasks->setText(QApplication::translate("MainWindow", "Tasks", 0));
        actionAdd_tasks_and_Categories->setText(QApplication::translate("MainWindow", "Tasks and Categories", 0));
        activation_groupBox->setTitle(QApplication::translate("MainWindow", "Task Activation", 0));
        activation_pushButton->setText(QApplication::translate("MainWindow", "Clock on/off", 0));
        activeTask_comboBox->setCurrentText(QString());
        task_label->setText(QApplication::translate("MainWindow", "Task Name", 0));
        task_toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        category_label->setText(QApplication::translate("MainWindow", "Category Filter", 0));
        categoryFilter_comboBox->clear();
        categoryFilter_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0)
        );
        categoryFilter_comboBox->setCurrentText(QApplication::translate("MainWindow", "None", 0));
        main_tabWidget->setTabText(main_tabWidget->indexOf(taskActivation), QApplication::translate("MainWindow", "Run", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Graphs", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Pie", 0));
        comboBox_3->setCurrentText(QApplication::translate("MainWindow", "(hourly,daily,monthly)", 0));
        label_7->setText(QApplication::translate("MainWindow", "Data Interval", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Bar", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "|<", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "<", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "refresh", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", ">|", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Graph Range", 0));
        comboBox_4->setCurrentText(QApplication::translate("MainWindow", "Preset Range", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "DD/MM/YY", 0));
        label_3->setText(QApplication::translate("MainWindow", "to", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "DD/MM/YY", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Custom", 0));
        label_4->setText(QApplication::translate("MainWindow", "Select Tasks", 0));
        main_tabWidget->setTabText(main_tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Statistics", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuSetup->setTitle(QApplication::translate("MainWindow", "Setup", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
