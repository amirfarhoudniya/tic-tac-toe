#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public :

    /*the status od each place .. 0 : not played ,
    1: 'X' player played , 2 : 'O' player played */
    int place_1;
    int place_2;
    int place_3;
    int place_4;
    int place_5;
    int place_6;
    int place_7;
    int place_8;
    int place_9;

    //the place is filled or not
    bool place1_filled = false;
    bool place2_filled = false;
    bool place3_filled = false;
    bool place4_filled = false;
    bool place5_filled = false;
    bool place6_filled = false;
    bool place7_filled = false;
    bool place8_filled = false;
    bool place9_filled = false;

    //player's turn : true means player_X and false means player_O
    bool turn = true;

    //winner
    char winner ;

    //restart the mainwindow after the winning masssage showed
    static bool restart ;

public:
    MainWindow(QWidget *parent = nullptr);
    void changeTurn();
    void chackWinner();

    ~MainWindow();

private slots:


    void on_place_1_clicked();

    void on_place_2_clicked();

    void on_place_3_clicked();

    void on_place_4_clicked();

    void on_place_5_clicked();

    void on_place_6_clicked();

    void on_place_7_clicked();

    void on_place_8_clicked();

    void on_place_9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
