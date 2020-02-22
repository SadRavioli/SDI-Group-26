#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool loadFile(const QString &fileName);


private slots:

    void on_classLoad_clicked();

    void on_classSave_clicked();

    void on_classAdd_clicked();

    void on_classRemove_clicked();

    void on_classEnter_editingFinished();

    void on_loadImagesButton_clicked();

    void on_imageList_itemDoubleClicked(QListWidgetItem *item);

    void on_dateSortButton_clicked();


private:
    void setImage(const QImage &newImage);

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor = 1;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
