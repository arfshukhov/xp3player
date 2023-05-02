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


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tracks = dat::get_tracks();

    player = new QMediaPlayer;

    output = new QAudioOutput;

    connect(player, &QMediaPlayer::positionChanged, this, &::MainWindow::on_time_lineChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &::MainWindow::on_volume_valueChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &::MainWindow::next_track);
    connect(ui->del_button, &QPushButton::clicked, this, &::MainWindow::delete_track);

    player->setAudioOutput(output);

    draw_tracks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_tracks(){
    ui->track_list->clear();
    auto tracks = dat::get_tracks();
    auto model = QStandardItemModel();
    for(auto&track:tracks){
        ui->track_list->addItem(QString::fromStdString(track));
    }
}


void MainWindow::set_track(std::string name){

    player->setSource(QUrl::fromLocalFile(QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(name))));
    ui->time_line->setMaximum(player->duration());
    ui->track_name->setText("playing: "+QString::fromStdString(name));
    ui->statusbar->setAccessibleName(player->errorString());
}


void MainWindow::on_add_button_clicked()
{
    QString path1 = QFileDialog::getOpenFileName(0, "Directory Dialog", ".", "");
    std::string path = path1.toStdString();
    dat::add_track(path);
    draw_tracks();
    tracks = dat::get_tracks();
}


void MainWindow::on_track_list_itemDoubleClicked(QListWidgetItem *item)
{
    set_track(item->text().toStdString());
}


void MainWindow::on_volume_valueChanged(int value)
{
    ui->volume->setValue(value);
}


void MainWindow::on_time_lineChanged(int value)
{
    ui->time_line->setValue(value);
}


void MainWindow::on_volume_sliderMoved(int position)
{
    float pos = float(position)/100.f;
    output->setVolume(pos);
}


void MainWindow::on_time_line_sliderMoved(int position)
{
    player->setPosition(position);
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

