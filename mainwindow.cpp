#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //make fix the size of window
    this->setFixedSize(this->geometry().width() , this->geometry().height());

    //make a turn
    changeTurn();

    //place's styleSheets
    ui->place_1->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_2->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_3->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_4->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_5->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_6->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_7->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_8->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");
    ui->place_9->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");

}

void MainWindow::changeTurn()
{
    //change the player turn
    turn = !turn ;

    //set ui for turns pushButton
    if(turn){
        ui->turn_pushButton->setText("X");
    }else{
        ui->turn_pushButton->setText("O");
    }
    ui->turn_pushButton->setStyleSheet("QPushButton { font-size: 22px; font-family: Arial; color: white; background-color: rgb(38,56,76); }");


}

void MainWindow::chackWinner()
{
    if( ui->place_1->text() == 'X' && ui->place_2->text() == 'X' && ui->place_3->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_1->text() == 'O' && ui->place_2->text() == 'O' && ui->place_3->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_1->text() == 'X' && ui->place_4->text() == 'X' && ui->place_7->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_1->text() == 'O' && ui->place_4->text() == 'O' && ui->place_7->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_3->text() == 'X' && ui->place_6->text() == 'X' && ui->place_9->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_3->text() == 'O' && ui->place_6->text() == 'O' && ui->place_9->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_7->text() == 'X' && ui->place_8->text() == 'X' && ui->place_9->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_7->text() == 'O' && ui->place_8->text() == 'O' && ui->place_9->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_1->text() == 'X' && ui->place_5->text() == 'X' && ui->place_9->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_1->text() == 'O' && ui->place_5->text() == 'O' && ui->place_9->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_3->text() == 'X' && ui->place_5->text() == 'X' && ui->place_7->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_3->text() == 'O' && ui->place_5->text() == 'O' && ui->place_7->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_4->text() == 'X' && ui->place_5->text() == 'X' && ui->place_6->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_4->text() == 'O' && ui->place_5->text() == 'O' && ui->place_6->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    if( ui->place_2->text() == 'X' && ui->place_5->text() == 'X' && ui->place_8->text() == 'X'){
        winner = 'X';
        QMessageBox::information(this , "winner!" ,"player X won !");
    }else if ( ui->place_2->text() == 'O' && ui->place_5->text() == 'O' && ui->place_8->text() == 'O') {
        winner = 'O';
        QMessageBox::information(this , "winner!" ,"player O won !");
    }

    //if we had winner, restart the game
    if(winner == 'X' || winner == 'O' ){
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }

    //if all the place filled and no one wins, restart the game.
    if(place1_filled && place2_filled && place3_filled && place4_filled && place5_filled
        && place6_filled && place7_filled && place8_filled && place9_filled ){
        QMessageBox::information(this , "no winner .." , "no one win .. !" );
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_place_1_clicked()
{
    if(turn == true && ui->place_1->text() == ""){
        ui->place_1->setText("X");
    }else if(turn == false && ui->place_1->text() == ""){
        ui->place_1->setText("O");
    }
    place1_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_2_clicked()
{
    if(turn == true && ui->place_2->text() == ""){
        ui->place_2->setText("X");
    }else if(turn == false && ui->place_2->text() == ""){
        ui->place_2->setText("O");
    }
    place2_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_3_clicked()
{
    if(turn == true && ui->place_3->text() == ""){
        ui->place_3->setText("X");
    }else if(turn == false && ui->place_3->text() == ""){
        ui->place_3->setText("O");
    }
    place3_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_4_clicked()
{
    if(turn == true && ui->place_4->text() == ""){
        ui->place_4->setText("X");
    }else if(turn == false && ui->place_4->text() == ""){
        ui->place_4->setText("O");
    }
    place4_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_5_clicked()
{
    if(turn == true && ui->place_5->text() == ""){
        ui->place_5->setText("X");
    }else if(turn == false && ui->place_5->text() == ""){
        ui->place_5->setText("O");
    }
    place5_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_6_clicked()
{
    if(turn == true && ui->place_6->text() == ""){
        ui->place_6->setText("X");
    }else if(turn == false && ui->place_6->text() == ""){
        ui->place_6->setText("O");
    }
    place6_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_7_clicked()
{
    if(turn == true && ui->place_7->text() == ""){
        ui->place_7->setText("X");
    }else if(turn == false && ui->place_7->text() == ""){
        ui->place_7->setText("O");
    }
    place7_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_8_clicked()
{
    if(turn == true && ui->place_8->text() == ""){
        ui->place_8->setText("X");
    }else if(turn == false && ui->place_8->text() == ""){
        ui->place_8->setText("O");
    }
    place8_filled = true;
    chackWinner();
    changeTurn();
}


void MainWindow::on_place_9_clicked()
{
    if(turn == true && ui->place_9->text() == ""){
        ui->place_9->setText("X");
    }else if(turn == false && ui->place_9->text() == ""){
        ui->place_9->setText("O");
    }
    place9_filled = true;
    chackWinner();
    changeTurn();
}

