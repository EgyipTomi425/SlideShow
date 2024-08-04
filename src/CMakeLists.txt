# TODO: adapt "org.kde.plasma" here & elsewhere if needed (see README)
add_definitions(-DTRANSLATION_DOMAIN=\"plasma_applet_com.github.egyiptomi425.slideshow\")

add_library(com.github.egyiptomi425.slideshow MODULE slideshow.cpp)

target_link_libraries(com.github.egyiptomi425.slideshow
                      Qt5::Gui
                      KF5::Plasma
                      KF5::I18n)


install(TARGETS com.github.egyiptomi425.slideshow DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/applets)

plasma_install_package(package com.github.egyiptomi425.slideshow)
