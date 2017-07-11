#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T14:29:13
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniAudio
TEMPLATE = app


SOURCES += src/main.cpp \
    src/View/mainwindow.cpp \
    src/Viewmodel/ViewModel.cpp \
    src/Model/Model.cpp

HEADERS  += src/View/mainwindow.h \
    src/Model/Model.h \
    src/Viewmodel/ViewModel.h \
    src/Common/BaseCommand.h \
    src/Common/Observable.h \
    src/Common/Observer.h \
    src/Common/Params.h \
    src/Common/Types.h \
    src/Common/Notify.h \
    src/Viewmodel/Commands/AddMuiscToListCommand.h

FORMS    += src/View/mainwindow.ui
