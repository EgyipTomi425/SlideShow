# TODO: adapt "org.kde.plasma" here & elsewhere if needed (see README)
add_definitions(-DTRANSLATION_DOMAIN=\"plasma_applet_org.kde.plasma.slideshow\")

add_library(org.kde.plasma.slideshow MODULE slideshow.cpp)

target_link_libraries(org.kde.plasma.slideshow
                      Qt5::Gui
                      KF5::Plasma
                      KF5::I18n)


install(TARGETS org.kde.plasma.slideshow DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/applets)

plasma_install_package(package org.kde.plasma.slideshow)
