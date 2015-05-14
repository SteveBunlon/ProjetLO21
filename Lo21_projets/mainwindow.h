#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "edittache.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openWindow();

private:
    Ui::MainWindow *ui;
    EditTache* newW;
};

#endif // MAINWINDOW_H
