/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <Plasma/Applet>
#include <QStringList>

class SlideShow : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(QString currentImage READ currentImage NOTIFY currentImageChanged)
    Q_PROPERTY(QString currentImageName READ currentImageName NOTIFY currentImageChanged)

public:
    explicit SlideShow(QObject *parent, const KPluginMetaData &data, const QVariantList &args);
    ~SlideShow();

    QString currentImage() const;
    QString currentImageName() const;

public Q_SLOTS:
    void nextImage();

Q_SIGNALS:
    void currentImageChanged();

private:
    void loadImages();

    QStringList m_images;
    int m_currentIndex;
};

#endif
