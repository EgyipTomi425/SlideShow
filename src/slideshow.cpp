/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "slideshow.h"

#include <QDir>
#include <QStandardPaths>
#include <KLocalizedString>

SlideShow::SlideShow(QObject *parent, const KPluginMetaData &data, const QVariantList &args)
    : Plasma::Applet(parent, data, args), m_currentIndex(0)
{
    loadImages();
}

SlideShow::~SlideShow()
{
}

QString SlideShow::currentImage() const
{
    if (m_images.isEmpty()) {
        return QString();
    }
    return m_images.at(m_currentIndex);
}

QString SlideShow::currentImageName() const
{
    if (m_images.isEmpty()) {
        return QString();
    }
    return QFileInfo(m_images.at(m_currentIndex)).fileName();
}

void SlideShow::nextImage()
{
    if (!m_images.isEmpty()) {
        m_currentIndex = (m_currentIndex + 1) % m_images.size();
        Q_EMIT currentImageChanged();
    }
}

void SlideShow::loadImages()
{
    QString picturesPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    QDir picturesDir(picturesPath);

    QStringList filters;
    filters << QLatin1String("*.jpg") << QLatin1String("*.jpeg");
    m_images = picturesDir.entryList(filters, QDir::Files);
    for (auto &image : m_images) {
        image = picturesDir.absoluteFilePath(image);
    }
}

K_PLUGIN_CLASS(SlideShow)

#include "slideshow.moc"
