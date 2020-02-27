#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include <QApplication>
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
#include <QLabel>
//#include <QColorSpace>
#include <QMessageBox>
#include <QImage>
#include <QTextStream>
#include <QDir>
#include <QStringListModel>
#include <string>
#include <iostream>

QString GLocation;
QStringList fileNames;
QStringList baseNames;
bool isImage = false;

LinkedList List;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle(tr("Labelling Application"));
    ui->setupUi(this);



    ui->classSave->setEnabled(false);
    ui->classRemove->setEnabled(false);
    ui->classAdd->setEnabled(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_loadImagesButton_clicked()
{

    fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Images (*.png *.tif *.jpg *.jpeg)"));

    if(fileNames.empty()) {
        QMessageBox::information(0,"Error","File Missing Or Not Selected");
    }
    else
    {

        QString baseName;
        for (int i = 0; i < fileNames.size(); i++)
        {




            QFileInfo file(fileNames[i]);

            baseName = file.fileName();

            int itemFound = List.FindNode(fileNames[i]);

            if (itemFound == 0)
            {
                List.InsertNode(i, fileNames[i]);
                baseNames.append(baseName);
                ui->imageList->addItem(baseName);
            }
            else
            {
                QMessageBox::information(0,"Error","File Already Exists");
            }
        }
    }
}



void MainWindow::on_imageList_itemDoubleClicked()
{
    int index = ui->imageList->currentRow();
    QImage image;
    image.load(List.FindItem(index));
    image = image.scaledToHeight(ui->imageDisplay->height(), Qt::SmoothTransformation);
    ui->imageDisplay->setPixmap(QPixmap::fromImage(image));
    isImage = true;
}


void MainWindow::on_dateSortButton_clicked()
{

}





void MainWindow::on_classLoad_clicked()//failed load still opens buttons
{
    QString filter ="Text File(*.txt)";
    QString selectFile = QFileDialog::getOpenFileName(this,"Please Select A Class File","C://",filter);
    QFile classesFile(selectFile);
    GLocation = selectFile;

    if(!classesFile.open(QFile::ReadOnly))
    {
        QMessageBox::information(0,"Error","File Missing Or Not Selected");
    }

    else
    {
    QStringList textList;

    QTextStream textStream(&classesFile);

    while (true)
    {

        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            textList.append(line);

    }

    ui->classList->addItems(textList);

    classesFile.close();

    ui->classSave->setEnabled(true);
    ui->classRemove->setEnabled(true);

    }
}



void MainWindow::on_classSave_clicked()
{
    QFile saveFile(GLocation);

    if(!saveFile.open(QFile::WriteOnly|QFile::Truncate))
    {
        QMessageBox::information(0,"File Loading Failed",saveFile.errorString());
    }

    QTextStream saveStream(&saveFile);
    int classCount = ui->classList->count();
    for(int i = 0; i < classCount; i++)
    {
        saveStream << ui->classList->item(i)->text() + "\n";
  }

     QMessageBox::information(0,"File Saved","File Saved");

    saveFile.close();
}

void MainWindow::on_classAdd_clicked()
{
        ui->classList->addItem(ui->classEnter->text());

}

void MainWindow::on_classRemove_clicked()//https://stackoverflow.com/questions/25417348/remove-selected-items-from-listwidget
{
   if (ui->classList->selectedItems().size() !=0)
   {
    QList<QListWidgetItem*> items = ui->classList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->classList->takeItem(ui->classList->row(item));
    }
   }
   else
   {
        QMessageBox::information(0,"Error","Please Select A Class To Remove");
    }
}

void MainWindow::on_classEnter_editingFinished()
{
    QString classInput = ui->classEnter->text();
     if (classInput == "")
     {
         ui->classAdd->setEnabled(false);
     }
     else
         ui->classAdd->setEnabled(true);
}

QStringList bubbleSort(QStringList List, int Count )
{
    for( int i=1; i< Count ;i++ )//for n-1 passes
    {
        for( int j=0; j<Count-1; j++)
        {
            if(List[j] > List[j+1])
            {
                QString const temp = List[j];
                List[j] = List[j+1];
                List[j+1] = temp;

            }

        }
    }
    return List;
}

void MainWindow::on_classAsc_clicked()
{
    QStringList SortList;
    int classCount = ui->classList->count();

    for (int i = 0; i < classCount; ++i)
        SortList.append(ui->classList->item(i)->text());

    QStringList Output = bubbleSort(SortList,classCount);

    ui->classList->clear();
    ui->classList->addItems(Output);

}


void MainWindow::on_nameSortButton_clicked()
{

}
