/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

// application
#include "config.hpp"
#include "window.hpp"
// KF
#include <KAboutData>
#include <KCrash>
#include <KLocalizedString>
// Qt
#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QUrl>
#include <QIcon>
// Std
#include <unistd.h>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain(QByteArrayLiteral("kodaskanna"));

    KAboutData aboutData(QStringLiteral("kodaskanna"),
                         i18n("Kodaskanna"),
                         QStringLiteral(KODASKANNA_VERSION),
                         i18n("Utility to scan data from codes in graphical sources."),
                         KAboutLicense::LGPL_V2_1,
                         i18n("Copyright 2022, 2024, Friedrich W. H. Kossebau"),
                         QString(),
                         QStringLiteral("https://apps.kde.org/kodaskanna"));

    aboutData.addAuthor(i18n("Friedrich W. H. Kossebau"), i18n("Author"), QStringLiteral("kossebau@kde.org"));

    KAboutData::setApplicationData(aboutData);
    application.setWindowIcon(QIcon::fromTheme(QStringLiteral("kodaskanna")));

    KCrash::initialize();

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.addPositionalArgument(QStringLiteral("URL"), i18n("Image file to open."), QStringLiteral("[URL}"));
    const QCommandLineOption oneScanOption(QStringLiteral("onescan"), i18n("Enable only one scan."));
    parser.addOption(oneScanOption);

    parser.process(application);
    aboutData.processCommandLine(&parser);

    // empty name: show image select input
    QUrl sourceFileUrl;
    const QStringList positionalArguments = parser.positionalArguments();
    if (positionalArguments.size() > 0) {
        const QString currentPath = QDir::currentPath();
        sourceFileUrl = QUrl::fromUserInput(positionalArguments.first(), currentPath, QUrl::AssumeLocalFile);
    } else {
        if (!isatty(STDIN_FILENO)) {
            sourceFileUrl = QUrl(QStringLiteral("stdin:/"));
        }
    }
    const bool isOneScanMode = parser.isSet(oneScanOption);

    const Kodaskanna::Window::Modus windowModus = isOneScanMode ? Kodaskanna::Window::OneScanModus : Kodaskanna::Window::DefaultModus;

    auto *window = new Kodaskanna::Window(windowModus);
    window->show();

    window->scanFromFile(sourceFileUrl);

    return application.exec();
}
