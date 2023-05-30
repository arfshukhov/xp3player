/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *add_button;
    QListWidget *track_list;
    QSlider *time_line;
    QLabel *track_name;
    QSlider *volume;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *prev_button;
    QPushButton *next_button;
    QPushButton *play_button;
    QPushButton *stop_button;
    QPushButton *del_button;
    QPushButton *search_button;
    QLabel *qr_label1;
    QLabel *error_label;
    QLabel *donate_label;
    QLabel *volume_label;
    QLabel *qr_label2;
    QLineEdit *author_line;
    QLineEdit *title_line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 657);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 606));
        MainWindow->setMaximumSize(QSize(800, 800));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"color:\n"
"}"));
        MainWindow->setIconSize(QSize(30, 30));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(231, 229, 255);\n"
"}"));
        add_button = new QPushButton(centralwidget);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(630, 10, 151, 31));
        add_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        track_list = new QListWidget(centralwidget);
        track_list->setObjectName("track_list");
        track_list->setGeometry(QRect(10, 10, 611, 441));
        QFont font;
        font.setBold(true);
        track_list->setFont(font);
        track_list->setStyleSheet(QString::fromUtf8("QListView {\n"
"    show-decoration-selected: 1; /* make the selection span the entire width of the view */\n"
"}\n"
"\n"
"QListView::item:alternate {\n"
"    background: #EEEEEE;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    border: 1px solid #6a6ea9;\n"
"}\n"
"\n"
"QListView::item:selected:!active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"}\n"
"\n"
"QListView::item:selected:active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"}"));
        track_list->setAutoScrollMargin(20);
        track_list->setSpacing(0);
        time_line = new QSlider(centralwidget);
        time_line->setObjectName("time_line");
        time_line->setGeometry(QRect(20, 500, 751, 22));
        time_line->setStyleSheet(QString::fromUtf8(" QSlider::groove:horizontal {\n"
"     border: 1px solid #999999;\n"
"     height: 8px; /* \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\260 \321\200\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\264\320\276 \321\200\320\260\320\267\320\274\320\265\321\200\320\276\320\262 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260. \320\267\320\260\320\264\320\260\320\262 \320\262\321\213\321\201\320\276\321\202\321\203 \320\276\320\275\320\260 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202 \321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 */\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"     margin: 2px 0;\n"
" }\n"
"\n"
" QSlider::handle:horizontal {\n"
"     background: qlineargradi"
                        "ent(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\260 \321\200\320\260\321\201\320\277\320\276\320\273\320\260\320\263\320\260\320\265\321\202\321\201\321\217 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\262 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\265 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270. \320\240\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\275\320\260\321\200\321\203\320\266\321\203 \320\276\321\202 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270 */\n"
"     border-radius: 3px;\n"
" }"));
        time_line->setMinimum(0);
        time_line->setMaximum(1000000000);
        time_line->setPageStep(1);
        time_line->setValue(4);
        time_line->setOrientation(Qt::Horizontal);
        time_line->setTickPosition(QSlider::NoTicks);
        time_line->setTickInterval(1);
        track_name = new QLabel(centralwidget);
        track_name->setObjectName("track_name");
        track_name->setGeometry(QRect(20, 460, 751, 31));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        track_name->setFont(font1);
        track_name->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 10px;\n"
"     padding: 0 8px;\n"
"     background-color: rgb(201, 199, 255);\n"
"	font: bold 14px;\n"
" }"));
        track_name->setTextFormat(Qt::AutoText);
        volume = new QSlider(centralwidget);
        volume->setObjectName("volume");
        volume->setGeometry(QRect(610, 530, 160, 22));
        volume->setStyleSheet(QString::fromUtf8(" QSlider::groove:horizontal {\n"
"     border: 1px solid #999999;\n"
"     height: 8px; /* \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\260 \321\200\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\264\320\276 \321\200\320\260\320\267\320\274\320\265\321\200\320\276\320\262 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260. \320\267\320\260\320\264\320\260\320\262 \320\262\321\213\321\201\320\276\321\202\321\203 \320\276\320\275\320\260 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202 \321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 */\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"     margin: 2px 0;\n"
" }\n"
"\n"
" QSlider::handle:horizontal {\n"
"     background: qlineargradi"
                        "ent(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\260 \321\200\320\260\321\201\320\277\320\276\320\273\320\260\320\263\320\260\320\265\321\202\321\201\321\217 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\262 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\265 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270. \320\240\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\275\320\260\321\200\321\203\320\266\321\203 \320\276\321\202 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270 */\n"
"     border-radius: 3px;\n"
" }"));
        volume->setMaximum(100);
        volume->setPageStep(1);
        volume->setValue(100);
        volume->setTracking(true);
        volume->setOrientation(Qt::Horizontal);
        volume->setTickPosition(QSlider::TicksAbove);
        volume->setTickInterval(1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(350, 520, 248, 51));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        prev_button = new QPushButton(layoutWidget);
        prev_button->setObjectName("prev_button");
        prev_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));

        gridLayout->addWidget(prev_button, 0, 1, 1, 1);

        next_button = new QPushButton(layoutWidget);
        next_button->setObjectName("next_button");
        next_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
""));

        gridLayout->addWidget(next_button, 0, 5, 1, 1);

        play_button = new QPushButton(layoutWidget);
        play_button->setObjectName("play_button");
        play_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));

        gridLayout->addWidget(play_button, 0, 2, 1, 1);

        stop_button = new QPushButton(layoutWidget);
        stop_button->setObjectName("stop_button");
        stop_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));

        gridLayout->addWidget(stop_button, 0, 3, 1, 1);

        del_button = new QPushButton(centralwidget);
        del_button->setObjectName("del_button");
        del_button->setGeometry(QRect(630, 50, 151, 31));
        del_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        search_button = new QPushButton(centralwidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(630, 90, 151, 31));
        search_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton::pressed{\n"
"    background-color: rgb(149, 130, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        qr_label1 = new QLabel(centralwidget);
        qr_label1->setObjectName("qr_label1");
        qr_label1->setGeometry(QRect(640, 132, 131, 131));
        error_label = new QLabel(centralwidget);
        error_label->setObjectName("error_label");
        error_label->setGeometry(QRect(600, 580, 181, 31));
        error_label->setFont(font);
        donate_label = new QLabel(centralwidget);
        donate_label->setObjectName("donate_label");
        donate_label->setGeometry(QRect(640, 420, 141, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        donate_label->setFont(font2);
        volume_label = new QLabel(centralwidget);
        volume_label->setObjectName("volume_label");
        volume_label->setGeometry(QRect(650, 550, 81, 21));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        volume_label->setFont(font3);
        qr_label2 = new QLabel(centralwidget);
        qr_label2->setObjectName("qr_label2");
        qr_label2->setGeometry(QRect(640, 275, 131, 131));
        author_line = new QLineEdit(centralwidget);
        author_line->setObjectName("author_line");
        author_line->setGeometry(QRect(20, 530, 301, 31));
        author_line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        author_line->setReadOnly(true);
        title_line = new QLineEdit(centralwidget);
        title_line->setObjectName("title_line");
        title_line->setGeometry(QRect(20, 580, 301, 31));
        title_line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: rgb(201, 199, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: grey;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        title_line->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "XP3Player", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "add new track", nullptr));
        track_name->setText(QCoreApplication::translate("MainWindow", "Playing", nullptr));
        prev_button->setText(QCoreApplication::translate("MainWindow", "prev", nullptr));
        next_button->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        play_button->setText(QCoreApplication::translate("MainWindow", "play", nullptr));
        stop_button->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        del_button->setText(QCoreApplication::translate("MainWindow", "delete current track", nullptr));
        search_button->setText(QCoreApplication::translate("MainWindow", "search tracks", nullptr));
        qr_label1->setText(QString());
        error_label->setText(QString());
        donate_label->setText(QCoreApplication::translate("MainWindow", "donate for developer", nullptr));
        volume_label->setText(QCoreApplication::translate("MainWindow", "volume", nullptr));
        qr_label2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
