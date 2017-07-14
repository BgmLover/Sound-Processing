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
    src/Model/Model.cpp \
    src/View/tone.cpp \
    src/View/frequency.cpp \
    src/Common/soundTouch/BPMDetect.cpp \
    src/Common/soundTouch/change.cpp \
    src/Common/soundTouch/WavFile.cpp \
    src/Common/soundTouch/FIFOSampleBuffer.cpp \
    src/Common/soundTouch/PeakFinder.cpp \
    src/Common/soundTouch/AAFilter.cpp \
    src/Common/soundTouch/cpu_detect_x86.cpp \
    src/Common/soundTouch/FIRFilter.cpp \
    src/Common/soundTouch/InterpolateCubic.cpp \
    src/Common/soundTouch/InterpolateLinear.cpp \
    src/Common/soundTouch/InterpolateShannon.cpp \
    src/Common/soundTouch/mix.cpp \
    src/Common/soundTouch/mmx_optimized.cpp \
    src/Common/soundTouch/RateTransposer.cpp \
    src/Common/soundTouch/RunParameters.cpp \
    src/Common/soundTouch/SoundTouch.cpp \
    src/Common/soundTouch/sse_optimized.cpp \
    src/Common/soundTouch/TDStretch.cpp \
    src/View/Plot/curveplot.cpp

HEADERS  += src/View/mainwindow.h \
    src/Model/Model.h \
    src/Viewmodel/ViewModel.h \
    src/Common/BaseCommand.h \
    src/Common/Observable.h \
    src/Common/Observer.h \
    src/Common/Params.h \
    src/Common/Types.h \
    src/Common/Notify.h \
    src/Viewmodel/Commands/AddMuiscToListCommand.h \
    src/View/tone.h \
    src/View/frequency.h \
    src/Viewmodel/Commands/tonechangecommand.h \
    src/Viewmodel/Commands/frequencychangecommand.h \
    src/Common/soundTouch/BPMDetect.h \
    src/Common/soundTouch/change.hpp \
    src/Common/soundTouch/SoundTouch.h \
    src/Common/soundTouch/STTypes.h \
    src/Common/soundTouch/WavFile.h \
    src/Common/soundTouch/FIFOSampleBuffer.h \
    src/Common/soundTouch/PeakFinder.h \
    src/Common/soundTouch/FIFOSamplePipe.h \
    src/Common/soundTouch/AAFilter.h \
    src/Common/soundTouch/cpu_detect.h \
    src/Common/soundTouch/FIRFilter.h \
    src/Common/soundTouch/InterpolateCubic.h \
    src/Common/soundTouch/InterpolateLinear.h \
    src/Common/soundTouch/InterpolateShannon.h \
    src/Common/soundTouch/RateTransposer.h \
    src/Common/soundTouch/RunParameters.h \
    src/Common/soundTouch/soundtouch_config.h \
    src/Common/soundTouch/TDStretch.h \
    src/View/Plot/fmod.h \
    src/View/Plot/fmod_errors.h \
    src/View/Plot/curveplot.h

FORMS    += src/View/mainwindow.ui \
    src/View/tone.ui \
    src/View/frequency.ui
