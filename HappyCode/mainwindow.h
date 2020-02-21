#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  //  static bool symbol = 0;

private slots:
    void on_btnOne_clicked();

    void on_btnTwo_clicked();

    void on_btnThree_clicked();

    void on_btnFour_clicked();

    void on_btnFive_clicked();

    void on_btnSix_clicked();

    void on_btnSeven_clicked();

    void on_btnEight_clicked();

    void on_btnNive_clicked();

    void on_btnZero_clicked();

    void on_btnDiv_clicked();

    void on_btnMul_clicked();

    void on_btnSub_clicked();

    void on_btnAdd_clicked();

    void on_btnEqu_clicked();

    void on_btnCal_clicked();

private:
    Ui::MainWindow *ui;
    void Calculate(QString str,int flag);
};

#endif // MAINWINDOW_H
