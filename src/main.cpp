#include "src/View/mainwindow.h"
#include <QApplication>
#include<QSplashScreen>
#include<QElapsedTimer>
#define SPLAHSCREENTIME 2000
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

    QSplashScreen *screen=new QSplashScreen(QPixmap(":/images/images/before.png"));
    screen->show();
    QElapsedTimer timer;
    timer.start();
    while(timer.elapsed()<SPLAHSCREENTIME)
        a.processEvents();
    delete screen;
    pMainWindows->show();
    return a.exec();


}
