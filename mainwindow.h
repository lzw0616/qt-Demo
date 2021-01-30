#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actiondakai_triggered();

    void on_actionbaocun_triggered();

    void on_actionxinjian_triggered();

    void on_actiontuichu_triggered();

    void on_actionchexiao_triggered();

    void on_actionfuzhi_triggered();

    void on_actionzhantie_triggered();

    void on_actionjianqie_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
