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

public slots:
    void set_photos_path();
    void make_copy();
    void delete_photo();
    void next_photo();
    void prev_photo();
    void load_photos();
    void make_negative();
    void mirror_horizontal();
    void mirror_vertical();
    void grayscale_photo();
    void rotate_photo();


private:
    Ui::MainWindow *ui;
    QVector<QString> paths;
    int current_photo;

};
#endif // MAINWINDOW_H
