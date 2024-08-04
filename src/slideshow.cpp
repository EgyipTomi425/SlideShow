/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "slideshow.h"

#include <KLocalizedString>

SlideShow::SlideShow(QObject *parent, const KPluginMetaData &data, const QVariantList &args)
    : Plasma::Applet(parent, data, args),
      m_nativeText(i18n("Text coming from C++ plugin"))
{
}

SlideShow::~SlideShow()
{
}

QString SlideShow::nativeText() const
{
    return m_nativeText;
}

K_PLUGIN_CLASS(SlideShow)

#include "slideshow.moc"
