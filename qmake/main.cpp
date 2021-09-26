#include "notepadq.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    notepadq Editor;
    Editor.show();
    return EditorApp.exec();
}
