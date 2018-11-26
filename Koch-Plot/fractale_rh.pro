#-------------------------------------------------
#
# Project created by QtCreator 2016-06-17T01:16:15
#
#-------------------------------------------------

QT       += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


RC_FILE = fractale_rh.rc

TARGET = fractale_rh
TEMPLATE = app

SOURCES += main.cpp \
    circle.cpp \
    frame.cpp \
    generator.cpp \
    main_fenetre.cpp \
    patterne.cpp \
    qwidget_circle.cpp \
    qwidget_edit_pas.cpp \
    qwidget_patterne.cpp \
    qwidget_plot.cpp \
    qwidget_type_ligne.cpp \
    svg.cpp \
    qwidget_generator.cpp

HEADERS  += \
    circle.h \
    frame.h \
    generator.h \
    main_fenetre.h \
    patterne.h \
    qwidget_circle.h \
    qwidget_edit_pas.h \
    qwidget_patterne.h \
    qwidget_plot.h \
    qwidget_type_ligne.h \
    svg.h \
    qwidget_generator.h

FORMS    +=

DISTFILES += \
    incone - copie.png \
    incone.png \
    incone_ok.png \
    incone_raw.PNG \
    incone_raw2.PNG \
    incone_ok.ico \
    fractale_rh.rc \
    Icone.ico
