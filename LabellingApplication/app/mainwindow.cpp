#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_helpwindow.h"
#include "helpwindow.h"
#include "binarytree.h"
#include <QApplication>
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
#include <QLabel>
#include <QColorSpace>
#include <QMessageBox>
#include <QImage>
#include <QTextStream>
#include <QDir>
#include <QStringListModel>
#include <string>
#include <iostream>
#include <QGraphicsScene>
#include <iostream>


BinaryTree Tree;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle(tr("Labelling Application"));
    ui->setupUi(this);

    rec = new Rec(this);
    //view = new QGraphicsView(rec);
    //view->setSceneRect(yourScene->sceneRect())
    ui->graphicsView->setScene(rec);// these four lines COPY
    ui->graphicsView->setStyleSheet("background: transparent");

    ui->classSave->setEnabled(false);
    ui->classRemove->setEnabled(false);
    ui->classAdd->setEnabled(false);
    ui->loadButton->setEnabled(false);
    ui->saveButton->setEnabled(false);

    //ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    //ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    //ui->graphicsView->setSceneRect(rec->sceneRect());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadImagesButton_clicked()
{
    for (int z = 0; z < fileNames.size(); z++)
    {
        Tree.remove(fileNames[z]);
    }
    fileNames.clear();
    baseNames.clear();

    fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Images (*.png *.tif *.jpg *.jpeg)"));

    if(fileNames.empty()) {
        QMessageBox::information(0,"Error", "File Missing Or Not Selected");
    }
    else
    {
        ui->imageList->clear();

        for (int i = 0; i < fileNames.size(); i++)
        {
            QFileInfo file(fileNames[i]);

            baseName = file.fileName();

            fileCreatedAt = file.created().toString();


            Tree.insertNode(fileNames[i], fileCreatedAt);
            baseNames.append(baseName);
            dateNameList.append(baseName);
            dateList.append(fileCreatedAt);
            ui->imageList->addItem(baseName);
        }
    }
}



void MainWindow::on_imageList_itemDoubleClicked()
{
    QStringList imageList;
    QImage image;

    int index = ui->imageList->currentRow();

    if (!buttonType)
    {
        if (nameClicked)
            Tree.showNodeInReverseOrder();


        if (!nameClicked)
            Tree.showNodeInOrder();

        imageList = Tree.returnTraversal();

    }
    if (buttonType)
    {
        imageList.append(fileNames);
        if (dateClicked)
            index = fileNames.size() - (index + 1);
    }

    image.load(imageList[index]);


    image = image.scaledToHeight(ui->imageDisplay->height(), Qt::SmoothTransformation);
    ui->imageDisplay->setPixmap(QPixmap::fromImage(image));

    isImage = true;
    ui->saveButton->setEnabled(true);
    ui->loadButton->setEnabled(true);
}


void MainWindow::on_nameSortButton_clicked()
{
    buttonType = false;

    ui->imageList->clear();
    if (!nameClicked)
    {
        nameClicked = true;
        for (int a = baseNames.size(); a --> 0; )
        {
            ui->imageList->addItem(baseNames[a]);
        }
    }
    else
    {
        nameClicked = false;
        for (int b = 0; b < baseNames.size(); b++)
        {
            ui->imageList->addItem(baseNames[b]);
        }
    }
}



void MainWindow::on_dateSortButton_clicked()
{
    buttonType = true;

    ui->imageList->clear();

    if (!dateClicked) {
        dateClicked = true;
        for (int c = 0; c < dateList.size() - 1; c++)
        for (int d = 0; d < dateList.size() - d - 1; d++)
        {
            if (dateList[d] > dateList[d+1])
                swap(&dateList[d], &dateList[d+1]);
                swap(&dateNameList[d], &dateNameList[d+1]);
                swap(&fileNames[d], &fileNames[d+1]);
        }
        for (int e = dateNameList.size(); e --> 0; )
        {
            ui->imageList->addItem(dateNameList[e]);
        }
    }
    else
    {
        dateClicked = false;
        for (int c = 0; c < dateList.size() - 1; c++)
        for (int d = 0; d < dateList.size() - d - 1; d++)
        {
            if (dateList[d] > dateList[d+1])
                swap(&dateList[d], &dateList[d+1]);
                swap(&dateNameList[d], &dateNameList[d+1]);
                swap(&fileNames[d], &fileNames[d+1]);
        }
        for (int e = 0; e < dateNameList.size(); e++)
        {
            ui->imageList->addItem(dateNameList[e]);
        }
    }
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
    for( int i=1; i< Count ;i++ )
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

void MainWindow::on_drawShape_clicked(bool checked)
{
    if (checked == true)
    {
        rec->setMode(Rec::Mode(int(Rec::DrawRec)));

    }
}

void MainWindow::on_moveShape_clicked(bool checked)
{
    if (checked == true)
    {
        rec->setMode(Rec::Mode(int(Rec::SelectObject)));
    }
}

void MainWindow::on_classList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    rec->ClassName = ui->classList->currentItem()->text();
}

void MainWindow::on_saveButton_clicked()
{
    QString Save = QFileDialog::getSaveFileName(this,tr("Please Name And Select Location"),tr("C://*.annotations"));
    rec->saveJson(Save, ui->imageList->currentItem()->text());
}

void MainWindow::on_loadButton_clicked()
{
    QString Load = QFileDialog::getOpenFileName(this,tr("Please Choose an Annotation File"),tr("C://*.annotations"));
    rec->readJson(Load);
}

void MainWindow::on_restoreButton_clicked()
{
    rec->clearRec();
}


void MainWindow::on_helpButton_clicked()
{
    helpwindow helpWindow;
    helpWindow.setModal(true);
    helpWindow.exec();
}
