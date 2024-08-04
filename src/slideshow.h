/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <Plasma/Applet>

class SlideShow : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(QString nativeText READ nativeText CONSTANT)

public:
    explicit SlideShow(QObject *parent, const KPluginMetaData &data, const QVariantList &args);
    ~SlideShow();

    QString nativeText() const;

private:
    QString m_nativeText;
};

#endif
