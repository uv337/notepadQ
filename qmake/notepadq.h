#ifndef NOTEPADQ_H
#define NOTEPADQ_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class notepadq; }
QT_END_NAMESPACE

class notepadq : public QMainWindow
{
    Q_OBJECT

public:
    notepadq(QWidget *parent = nullptr);
    ~notepadq();

private slots:
    void newDocument();

    void open();

    void save();

    void saveAs();

    void print();

    void exit();

    void copy();

    void cut();

    void paste();

    void undo();

    void redo();

    void selectFont();

    void about();

private:
    Ui::notepadq *ui;
     QString currentFile;
};
#endif // NOTEPADQ_H
