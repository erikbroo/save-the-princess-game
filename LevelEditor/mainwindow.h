#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "levelitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_newButton_clicked();

    void on_itemsTable_cellClicked(int row, int column);

    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    void setUpItemList();
    QVector<LevelItem*> itemsList;
    QString currentFilename;

    void loadLevelItems();
    void writeLevelItems();

    void showFileIOErorrMessage(QString info);

    int getItemId(QString itemName);
    QVector<int> getNumbersFromString(QByteArray data);
    LevelItem getItemData(int id);
    bool isDigit(char symbol);

    void setColumnWidth();
};

#endif // MAINWINDOW_H
