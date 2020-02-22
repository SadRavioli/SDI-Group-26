#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
#include <QLabel>
#include <QColorSpace>
#include <QMessageBox>
#include <QImage>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle(tr("Labelling Application"));
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


QStringList fileNames;
QStringList baseNames;


void MainWindow::on_loadImagesButton_clicked()
{
    fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Images (*.png *.tif *.jpg *.jpeg)"));

    QString baseName;
    for (int i = 0; i < fileNames.size(); i++)
    {
        QFileInfo file(fileNames[i]);

        baseName = file.fileName();
        baseNames.append(baseName);
        ui->imageList->addItem(baseName);
    }

}



void MainWindow::on_imageList_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->imageList->currentRow();
    QImage image;
    image.load(fileNames[index]);
    image = image.scaledToHeight(ui->imageDisplay->height(), Qt::SmoothTransformation);
    ui->imageDisplay->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_dateSortButton_clicked()
{

}
