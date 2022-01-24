/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

// application
#include "config.hpp"
#include "window.hpp"
// KF
#include <KAboutData>
#include <KLocalizedString>
// Qt
#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QUrl>
#include <QIcon>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("kodaskanna");

    KAboutData aboutData(QStringLiteral("kodaskanna"),
                         i18n("Kodaskanna"),
                         QStringLiteral(KODASKANNA_VERSION),
                         i18n("Utility to scan data from codes in graphical sources."),
                         KAboutLicense::LGPL_V2_1,
                         i18n("Copyright 2022, Friedrich W. H. Kossebau <kossebau@kde.org>"),
                         QString(),
                         QStringLiteral("https://commits.kde.org/kodaskanna"));

    aboutData.addAuthor(i18n("Friedrich W. H. Kossebau"), i18n("Author"), QStringLiteral("kossebau@kde.org"));

    KAboutData::setApplicationData(aboutData);
    application.setWindowIcon(QIcon::fromTheme(QStringLiteral("kodaskanna")));

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.addPositionalArgument(QStringLiteral("URL"), i18n("Image file to open."), QStringLiteral("[URL}"));

    parser.process(application);
    aboutData.processCommandLine(&parser);

    // empty name: show image select input
    QUrl sourceFileUrl;
    const QStringList positionalArguments = parser.positionalArguments();
    if (positionalArguments.size() > 0) {
        const QString currentPath = QDir::currentPath();
        sourceFileUrl = QUrl::fromUserInput(positionalArguments.first(), currentPath, QUrl::AssumeLocalFile);
    }

    auto *window = new Kodaskanna::Window;
    window->show();

    window->scanFromFile(sourceFileUrl);

    return application.exec();
}
