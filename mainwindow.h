#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <windows.h>
#include <iostream>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTextCodec>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTextCodec * codec;
    std::vector<std::string> tracks = {};
    QMediaPlayer *player;
    QAudioOutput *output;

    void draw_tracks();

    void set_track(std::string);

    void delete_track();

private slots:
    void on_add_button_clicked();

    void on_track_list_itemDoubleClicked(QListWidgetItem *item);

    void on_volume_valueChanged(int value);

    void on_time_lineChanged(int value);

    void on_volume_sliderMoved(int position);

    void on_time_line_sliderMoved(int position);

    void next_track(int position);

    void on_play_button_clicked();

    void on_stop_button_clicked();

    void on_prev_button_clicked();

    void on_next_button_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
