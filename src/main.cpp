#include "src/View/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shared_ptr<Model> pModel(new Model());
    shared_ptr<ViewModel> pViewModel(new ViewModel());
    shared_ptr<MainWindow> pMainWindows(new MainWindow);
    pViewModel->setmodel(pModel);

    //bind
    pMainWindows->setplaylist(pViewModel->getplayList());
    pMainWindows->playerinit();
    pMainWindows->mainwindowinit();
    pMainWindows->setaddMusicToListCommand(pViewModel->getAddMusicToListCommand());
    pMainWindows->settoneChangeCommand(pViewModel->getToneChangeCommand());
    pMainWindows->setfrequencyChangeCommand(pViewModel->getFrequencyChangeCommand());
    //add observer
    pModel->addObserver(pViewModel);
    pViewModel->addObserver(pMainWindows);

    pMainWindows->show();

    return a.exec();


}

