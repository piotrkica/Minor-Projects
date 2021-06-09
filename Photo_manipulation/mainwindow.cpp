#include "mainwindow.h"
#include "./ui_mainwindow.h"

# include <QDirIterator>
# include <QDebug>
# include <vector>
# include <QFileDialog>
#include <QImage>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), current_photo(0){
    ui->setupUi(this);

    QObject::connect(ui->load_path_button, SIGNAL(clicked()), this, SLOT(set_photos_path()));
    QObject::connect(ui->next_button, SIGNAL(clicked()), this, SLOT(next_photo()));
    QObject::connect(ui->prev_button, SIGNAL(clicked()), this, SLOT(prev_photo()));
    QObject::connect(ui->load_button, SIGNAL(clicked()), this, SLOT(load_photos()));
    QObject::connect(ui->copy_button, SIGNAL(clicked()), this, SLOT(make_copy()));
    QObject::connect(ui->delete_button, SIGNAL(clicked()), this, SLOT(delete_photo()));
    QObject::connect(ui->negative_button, SIGNAL(clicked()), this, SLOT(make_negative()));
    QObject::connect(ui->horizontal_mirror_button, SIGNAL(clicked()), this, SLOT(mirror_horizontal()));
    QObject::connect(ui->vertical_mirror_button, SIGNAL(clicked()), this, SLOT(mirror_vertical()));
    QObject::connect(ui->grayscale_button, SIGNAL(clicked()), this, SLOT(grayscale_photo()));
    QObject::connect(ui->rotate_button, SIGNAL(clicked()), this, SLOT(rotate_photo()));
}

MainWindow::~MainWindow(){
    delete ui;
}

inline bool ends_with(QString const & value, QString const & ending){
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

void MainWindow::set_photos_path(){
    QString path = QFileDialog::getExistingDirectory(this, "Select photos folder");
    ui->load_path_lineEdit->setText(QApplication::translate("MainWindow", path.toStdString().c_str(), Q_NULLPTR));
}

void MainWindow::make_copy(){
    if (this->paths.empty()){
        return;
    }
    QString path = this->paths[current_photo];
    if (ends_with(path, ".jpg")){
        path = path.mid(0, path.size() - 4);
        path += "-copy.jpg";
    }
    if (ends_with(path, ".png")){
        path = path.mid(0, path.size() - 4);
        path += "-copy.png";
    }
    if (ends_with(path, ".jpeg")){
        path = path.mid(0, path.size() - 5);
        path += "-copy.jpeg";
    }
    QFile::copy(this->paths[current_photo], path);
    this->paths.insert(current_photo, path);
    ui->photo_display->setPixmap(QPixmap(QString(this->paths[current_photo])));
    ui->file_path_LineEdit->setText(QString(this->paths[current_photo]));
    //this->load_photos();
}

void MainWindow::delete_photo(){
    QString path = this->paths[current_photo];
    this->paths.remove(current_photo);
    QFile::remove(path);
    current_photo = current_photo % this->paths.size();
    ui->photo_display->setPixmap(QPixmap(QString(this->paths[current_photo])));
    ui->file_path_LineEdit->setText(QString(this->paths[current_photo]));
}

void MainWindow::next_photo(){
    if (this->paths.size() == 0){
        return;
    }
    current_photo = (current_photo + 1) % this->paths.size();
    ui->photo_display->setPixmap(QPixmap(QString(this->paths[current_photo])));
    ui->file_path_LineEdit->setText(QString(this->paths[current_photo]));
}

void MainWindow::prev_photo(){
    if (this->paths.size() == 0){
        return;
    }
    current_photo--;
    if (current_photo < 0){
        current_photo = this->paths.size() - 1;
    }
    ui->photo_display->setPixmap(QPixmap(QString(this->paths[current_photo])));
    ui->file_path_LineEdit->setText(QString(this->paths[current_photo]));
}

void MainWindow::load_photos(){
    QString dir_path = ui->load_path_lineEdit->text();
    this->paths.clear();
    QDirIterator it(dir_path, QDirIterator::NoIteratorFlags);
    while (it.hasNext()) {
        QString file_path = it.next();
        QString file_name = it.fileName();
        if (file_name == QString("..") || file_name == QString(".")){
            continue;
        }
        if (!ends_with(file_name, ".png") && !ends_with(file_name, ".jpg") && !ends_with(file_name, ".jpeg")){
            continue;
        }
        this->paths.push_back(file_path);
    }
    current_photo = 0;
    ui->photo_display->setPixmap(QPixmap(QString(this->paths[current_photo])));
    ui->file_path_LineEdit->setText(QString(this->paths[current_photo]));
}

void MainWindow::make_negative(){
    QImage image = QImage(QString(this->paths[current_photo]), nullptr);
    image.invertPixels();
    image.save(QString(this->paths[current_photo]), nullptr, -1);
    ui->photo_display->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mirror_horizontal(){
    QImage image = QImage(QString(this->paths[current_photo]), nullptr);
    image = image.mirrored(true, false);
    image.save(QString(this->paths[current_photo]), nullptr, -1);
    ui->photo_display->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mirror_vertical(){
    QImage image = QImage(QString(this->paths[current_photo]), nullptr);
    image = image.mirrored(false, true);
    image.save(QString(this->paths[current_photo]), nullptr, -1);
    ui->photo_display->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::grayscale_photo(){
    QImage image = QImage(QString(this->paths[current_photo]), nullptr);
    image = image.convertToFormat(QImage::Format_Grayscale8);
    image.save(QString(this->paths[current_photo]), nullptr, -1);
    ui->photo_display->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::rotate_photo(){
    QImage image = QImage(QString(this->paths[current_photo]), nullptr);
    image = image.transformed(QTransform().rotate(90), Qt::FastTransformation);
    image.save(QString(this->paths[current_photo]), nullptr, -1);
    ui->photo_display->setPixmap(QPixmap::fromImage(image));
}
