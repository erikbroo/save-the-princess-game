#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpItemList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newButton_clicked()
{
   int levelRowsNumber = ui->rowSpinBox->value();
   int levelColumnsNumber = ui->columnSpinBox->value();

   ui->itemsTable->setRowCount(levelRowsNumber);
   ui->itemsTable->setColumnCount(levelColumnsNumber);

   setColumnWidth();

   for(int row = 0; row < ui->itemsTable->rowCount(); row++)
   {
       for(int column = 0; column < ui->itemsTable->columnCount(); column++)
       {
           ui->itemsTable->setItem(row, column, new QTableWidgetItem(ui->listItems->item(0)->icon(),"Grass"));

       }

   }

   currentLevelFilename = QFileDialog::getSaveFileName(this,"Save File",0,"*.spg");

}

void MainWindow::setUpItemList()
{
    int i = 0;

    itemsList.append(new LevelItem(i++,QIcon("Grass.png"),QString("Grass")));
    itemsList.append(new LevelItem(i++,QIcon("GrassWall.png"),"Grass wall"));
    itemsList.append(new LevelItem(i++,QIcon("Water.png"),"Water"));
    itemsList.append(new LevelItem(i++,QIcon("StoneWall.png"),"Stone wall"));
    itemsList.append(new LevelItem(i++,QIcon("Board.png"),"Board"));
    itemsList.append(new LevelItem(i++,QIcon("Hero.png"),"Hero"));
    itemsList.append(new LevelItem(i++,QIcon("Princess.png"),"Princess"));
    itemsList.append(new LevelItem(i++,QIcon("Enemy1.png"),"Enemy1"));

    for(int j = 0; j < itemsList.size(); j++)
    {
        ui->listItems->addItem(new QListWidgetItem(itemsList[j]->icon, itemsList[j]->name));
    }

}


void MainWindow::writeLevelItems()
{
    QFile file(currentLevelFilename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        showFileIOErorrMessage("Error opening file: ");
        return;
    }

    QByteArray rowAndColumnNumbers;
    int rows = ui->itemsTable->rowCount();
    int columns = ui->itemsTable->columnCount();

    rowAndColumnNumbers.append(QString("%1 %2\n")
                               .arg(QString::number(rows))
                               .arg(QString::number(columns)));

    file.write(rowAndColumnNumbers);

    for(int row = 0; row < ui->itemsTable->rowCount(); row++)
    {
        QByteArray numbersId;
        for(int column = 0; column < ui->itemsTable->columnCount(); column++)
        {
            numbersId.append(QString("%1 ").arg(QString::number(getItemId(ui->itemsTable->item(row,column)->text()))));
        }
        numbersId.append("\n");
        file.write(numbersId);
        numbersId = "";
    }

    file.close();
}

void MainWindow::showFileIOErorrMessage(QString info)
{
    QMessageBox msgBox;
    msgBox.setText(info + "\'" + currentLevelFilename + "\'.");
}

int MainWindow::getItemId(QString itemName)
{
    for(int i = 0; i < itemsList.size(); i++)
    {
      if (itemsList[i]->name == itemName)
          return itemsList[i]->id;
    }
    return -1;
}

QVector<int> MainWindow::getNumbersFromString(QByteArray data)
{
    QVector<int> numbers;
    const char* line = data.constData();

    int i = 0;
    while (i < data.size())
    {

        if(isDigit(line[i]))
        {
            QByteArray number;
            while (i < data.size() && isDigit(line[i]))
            {
                number.append(line[i]);
                i++;
            }
            numbers.append(number.toInt());
        } else {
            i++;
        }
    }

    return numbers;
}

LevelItem MainWindow::getItemData(int id)
{
    foreach (LevelItem* item, itemsList){
       if (item->id == id) return *item;
    }
}

bool MainWindow::isDigit(char symbol)
{
    QChar c(symbol);
    return c.isDigit();
}

void MainWindow::setColumnWidth()
{
    for(int i = 0; i < ui->itemsTable->columnCount(); i++) ui->itemsTable->setColumnWidth(i, 32);
}

bool MainWindow::checkIfItemPlaced(QString itemName) {
    for(int row = 0; row < ui->itemsTable->rowCount(); row++)
    {
        for(int column = 0; column < ui->itemsTable->columnCount(); column++)
        {
            QTableWidgetItem* item = ui->itemsTable->item(row,column);
            if (QString::compare(item->text(),itemName) == 0) {
                return true;
            }
        }
    }
    return false;
}

bool MainWindow::checkIfHeroWasPlaced()
{
    return checkIfItemPlaced("Hero");
}

bool MainWindow::checkIfPrincessWasPlaced()
{
    return checkIfItemPlaced("Princess");
}

void MainWindow::on_itemsTable_cellClicked(int row, int column)
{
    QTableWidgetItem* item = ui->itemsTable->item(row,column);

    if (ui->listItems->selectedItems().isEmpty() == false &&
        ui->insertModeBox->isChecked())
    {
        QString itemName = ui->listItems->currentItem()->text();

        if (QString::compare(itemName,"Hero") == 0) {
            if (checkIfHeroWasPlaced())
            {
                return;
            }
        }

        if (QString::compare(itemName,"Princess") == 0) {
            if (checkIfPrincessWasPlaced()){
                return;
            }
        }
        item->setText(ui->listItems->currentItem()->text());
        item->setIcon(ui->listItems->currentItem()->icon());
    }

}

void MainWindow::on_saveButton_clicked()
{
    writeLevelItems();
}

void MainWindow::on_loadButton_clicked()
{
    currentLevelFilename = QFileDialog::getOpenFileName(this,"Load file",0,"*.spg");

    QVector<int> idList;

    QFile file(currentLevelFilename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        showFileIOErorrMessage("Error opening file: ");
        return;
    }

    QByteArray numbers;

    numbers = file.readLine();

    idList = getNumbersFromString(numbers);

    if (numbers.isEmpty() || idList.size() != 2)
    {
        showFileIOErorrMessage("Error reading dimension from file: ");
        file.close();
        return;
    }

    ui->itemsTable->setRowCount(idList[0]);
    ui->itemsTable->setColumnCount(idList[1]);

    setColumnWidth();

    for (int row = 0; row < ui->itemsTable->rowCount(); row++)
    {
       numbers = file.readLine();
       idList = getNumbersFromString(numbers);

       if (numbers.isEmpty() || idList.size() == 0)
       {
           showFileIOErorrMessage("Error reading items info from file: ");
           file.close();
           return;
       }
       for(int col = 0; col < ui->itemsTable->columnCount(); col++)
       {
           LevelItem item = getItemData(idList[col]);
           ui->itemsTable->setItem(row,col,new QTableWidgetItem(item.icon,item.name));
       }
    }

    file.close();
}
