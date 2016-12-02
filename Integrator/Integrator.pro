#-------------------------------------------------
#
# Project created by QtCreator 2016-10-13T19:44:50
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Integrator
TEMPLATE = app


SOURCES += main.cpp\
    gra/integrator.cpp \
    gra/mainintegratorwidget.cpp \
    gra/pasa_merge_widget.cpp \
    gra/pasemergefod01.cpp \
    gra/qjira.cpp \
    gra/test_qmv_01.cpp \
    gra/ticket.cpp \
    gra/jiratickets.cpp \
    gra/errticket.cpp \
    gra/ui_stp/ui_define_stp.cpp \
    gra/ui_stp/build/builddefine.cpp \
    gra/ui_stp/build/definebuildwidget.cpp \
    gra/ui_stp/build/Util/UIComponentSoftware.cpp \
    gra/ui_stp/jira/uijirastpinterface.cpp

HEADERS  +=  gra/integrator.h \
    gra/mainintegratorwidget.h \
    gra/pasa_merge_widget.h \
    gra/pasemergefod01.h \
    gra/qjira.h \
    gra/test_qmv_01.h \
    gra/ticket.h \
    gra/jiratickets.h \
    gra/errticket.h \
    gra/ui_stp/ui_define_stp.h \
    gra/ui_stp/build/builddefine.h \
    gra/ui_stp/build/definebuildwidget.h \
    gra/ui_stp/build/Util/UIComponentSoftware.h \
    gra/ui_stp/jira/uijirastpinterface.h

FORMS    +=  gra/integrator.ui \
    gra/test.ui \
    gra/ui_stp/ui_define_stp.ui \
    gra/ui_stp/build/builddefine.ui \
    gra/ui_stp/build/definebuildwidget.ui \
    gra/ui_stp/jira/uijirastpinterface.ui

RESOURCES += \
    gra/integrator.qrc

DISTFILES += \
    gra/Integrator.ico \
    gra/Integrator.rc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/release/ -lSTPCreatorLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/debug/ -lSTPCreatorLib
else:unix:!macx: LIBS += -L$$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/ -lSTPCreatorLib

INCLUDEPATH += $$PWD/STPCore/lib
DEPENDPATH += $$PWD/STPCore/lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/release/libSTPCreatorLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/debug/libSTPCreatorLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/release/STPCreatorLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/debug/STPCreatorLib.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/STPCore/lib/build-STPCreatorLib-Desktop_Qt_5_6_0_MinGW_32bit-Debug/libSTPCreatorLib.a
