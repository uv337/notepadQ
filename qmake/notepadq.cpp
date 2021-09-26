#include "notepadq.h"
#include "ui_notepadq.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QTextStream>
#include <QFile>

notepadq::notepadq(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notepadq)
{
    ui->setupUi(this);
     this->setCentralWidget(ui->textEdit);

    connect(ui->actionNew, &QAction::triggered, this, &notepadq::newDocument);
           connect(ui->actionOpen, &QAction::triggered, this, &notepadq::open);
           connect(ui->actionSave, &QAction::triggered, this, &notepadq::save);
           connect(ui->actionSave_as, &QAction::triggered, this, &notepadq::saveAs);
           connect(ui->actionPrint, &QAction::triggered, this, &notepadq::print);
           connect(ui->actionExit, &QAction::triggered, this, &notepadq::exit);
           connect(ui->actionCopy, &QAction::triggered, this, &notepadq::copy);
           connect(ui->actionCut, &QAction::triggered, this, &notepadq::cut);
           connect(ui->actionPaste, &QAction::triggered, this, &notepadq::paste);
           connect(ui->actionUndo, &QAction::triggered, this, &notepadq::undo);
           connect(ui->actionRedo, &QAction::triggered, this, &notepadq::redo);
           connect(ui->actionFont, &QAction::triggered, this, &notepadq::selectFont);

           connect(ui->actionAbout_Nightly, &QAction::triggered, this, &notepadq::about);

           // Disable menu actions for unavailable features
           #if !defined(QT_PRINTSUPPORT_LIB) || !QT_CONFIG(printer)
               ui->actionPrint->setEnabled(false);
           #endif

           #if !QT_CONFIG(clipboard)
               ui->actionCut->setEnabled(false);
               ui->actionCopy->setEnabled(false);
               ui->actionPaste->setEnabled(false);
           #endif
}

notepadq::~notepadq()
{
    delete ui;
}

void notepadq::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void notepadq::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void notepadq::save()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void notepadq::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void notepadq::print()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev, this);
    if (dialog.exec() == QDialog::Rejected)
        return;
#endif // QT_CONFIG(printdialog)
    ui->textEdit->print(&printDev);
#endif // QT_CONFIG(printer)
}

void notepadq::exit()
{
    QCoreApplication::quit();
}

void notepadq::copy()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->copy();
#endif
}

void notepadq::cut()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->cut();
#endif
}

void notepadq::paste()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->paste();
#endif
}

void notepadq::undo()
{
     ui->textEdit->undo();
}

void notepadq::redo()
{
    ui->textEdit->redo();
}

void notepadq::selectFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setFont(font);
}

void notepadq::about(){
 QMessageBox::information(this, "Title", "Hello");
}

