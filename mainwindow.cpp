#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <logic.h>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTextCodec>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QDesktopServices>
#include <QMediaMetaData>
#include <QCloseEvent>
#include <QAction>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tracks = dat::get_tracks();

    player = new QMediaPlayer;

    output = new QAudioOutput;

    tray_icon = new QSystemTrayIcon(this);
    set_tray();
    connect(player, &QMediaPlayer::positionChanged, this, &::MainWindow::on_time_line_changed);
    connect(player, &QMediaPlayer::durationChanged, this, &::MainWindow::on_volume_value_changed);
    connect(player, &QMediaPlayer::positionChanged, this, &::MainWindow::next_track);
    connect(ui->del_button, &QPushButton::clicked, this, &::MainWindow::delete_track);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    player->setAudioOutput(output);

    draw_tracks();

    set_qr();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete output;
}

void MainWindow::draw_tracks(){
    ui->track_list->clear();
    auto tracks = dat::get_tracks();
    auto model = QStandardItemModel();
    for(auto&track:tracks){
        ui->track_list->addItem(QString::fromStdString(track));
    }
}


void MainWindow::set_qr(){
    QSize PicSize(131, 131);

    QPixmap pix1("pay_qr.png");
    QPixmap pix2("card_qr.png");

    pix1 = pix1.scaled(PicSize, Qt::KeepAspectRatio);
    pix2 = pix2.scaled(PicSize, Qt::KeepAspectRatio);

    ui->qr_label1->setPixmap(pix1);
    ui->qr_label1->repaint();
    ui->qr_label1->show();


    ui->qr_label2->setPixmap(pix2);
    ui->qr_label2->repaint();
    ui->qr_label2->show();
}


void MainWindow::set_track(std::string name){

    player->setSource(QUrl::fromLocalFile(QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(name))));
    ui->time_line->setMaximum(player->duration());
    ui->track_name->setText("playing: "+QString::fromStdString(name));
    ui->author_line->setText("author: "+player->metaData().stringValue(player->metaData().AlbumArtist));
    //qDebug()<<player->metaData().stringValue(player->metaData().Author)<<"author"<<"\n";
    ui->title_line->setText("title: "+player->metaData().stringValue(player->metaData().Title));
    //qDebug()<<player->metaData().stringValue(player->metaData().Title)<<"title"<<"\n";
}


void MainWindow::on_add_button_clicked()
{
    QString path1 = QFileDialog::getOpenFileName(0, "Directory Dialog", ".", "");
    std::string path = path1.toStdString();
    dat::add_track(path);
    draw_tracks();
    tracks = dat::get_tracks();
}


void MainWindow::set_tray(){
    tray_icon->setIcon(QIcon("icon.ico"));
    tray_icon->setToolTip(QString("XP3 Player"));
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction("Show player", this);
    QAction * quitAction = new QAction("Close player", this);
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, &QAction::triggered, this, exit);
    menu->addAction(viewWindow);
    menu->addAction(quitAction);
    tray_icon->setContextMenu(menu);
    tray_icon->show();
    connect(tray_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}


void MainWindow::on_track_list_itemDoubleClicked(QListWidgetItem *item)
{
    set_track(item->text().toStdString());
}


void MainWindow::on_volume_value_changed(int value)
{
    ui->volume->setValue(value);
}


void MainWindow::on_time_line_changed(int value)
{
    ui->time_line->setValue(value);
}


void MainWindow::next_track(int position){
    if(position==(int)player->duration()){
        std::string source =player->source().toString().toStdString();source.replace(0,8, "");

        unsigned idx = logic::index(tracks, source);
        if (idx == tracks.size()-1)
            set_track(tracks[0]);
        else
            set_track(tracks[idx+1]);
        player->stop();
        player->play();
    }
}


void MainWindow::on_play_button_clicked()
{
    player->play();
}


void MainWindow::on_stop_button_clicked()
{
    player->pause();
}


void MainWindow::on_prev_button_clicked()
{
    if(tracks.size() == 0)
        return;
    std::string source =player->source().toString().toStdString();source.replace(0,8, "");
    unsigned idx = logic::index(tracks, source);
    if (idx == 0)
        set_track(tracks[tracks.size()-1]);
    else
        set_track(tracks[idx-1]);
    player->play();
}


void MainWindow::on_next_button_clicked()
{
    if(tracks.size() == 0)
        return;
    std::string source =player->source().toString().toStdString();source.replace(0,8, "");
    unsigned idx = logic::index(tracks, source);
    if (idx == tracks.size()-1)
        set_track(tracks[0]);
    else
        set_track(tracks[idx+1]);
    player->play();
}


void MainWindow::delete_track(){
    std::string source = player->source().toString().toStdString();source.replace(0,8, "");
    unsigned idx = logic::index(tracks, source);
    tracks.erase(tracks.begin()+idx);
    dat::renew_tracks(tracks);
    draw_tracks();
    set_track("");
}


void MainWindow::on_search_button_clicked()
{
    QString link = "https://ru.hitmotop.com";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_time_line_sliderMoved(int position)
{
    player->setPosition(position);
}


void MainWindow::on_volume_sliderMoved(int position)
{
    float pos = float(position)/100.f;
    output->setVolume(pos);
}


void MainWindow::closeEvent(QCloseEvent * event)
{
    event->ignore();
    this->hide();
    tray_icon->showMessage(tr("XP3 Player"), tr("Player is hidden in tray"));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }
            break;

        break;
    default:
        break;
    }
}


