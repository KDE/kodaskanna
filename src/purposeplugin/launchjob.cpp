/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "launchjob.hpp"

// KF
#include <KIO/CommandLauncherJob>
#include <KService>
#include <KLocalizedString>
// Qt
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace Kodaskanna
{

namespace PurposePlugin
{

LaunchJob::LaunchJob(QObject *parent)
    : Purpose::Job(parent)
{
}

void LaunchJob::start()
{
    const QJsonArray urls = data().value(QStringLiteral("urls")).toArray();
    if (urls.size() != 1) {
        setErrorText(i18n("Need one URL."));
        emitResult();
        return;
    }
    const QString url = urls.at(0).toString();

    const QString desktopName = QStringLiteral("org.kde.kodaskanna");
    KService::Ptr service = KService::serviceByDesktopName(desktopName);

    if (!service) {
        setErrorText(i18n("Could not find Kodaskanna."));
        emitResult();
        return;
    }

    // TODO: using CommandLauncherJob instead of ApplicationLauncherJob, due to additional arg
    // Perhaps should get instead a dedicate separate service desktop file with NoDisplay?
    auto *applicationLauncherJob = new KIO::CommandLauncherJob(service->exec(), {QStringLiteral("--onescan"), url});
    applicationLauncherJob->setDesktopName(desktopName);
    connect(applicationLauncherJob, &KIO::CommandLauncherJob::result,
            this, &LaunchJob::handleApplicationLaunchJobResult);
    applicationLauncherJob->start();
}

void LaunchJob::handleApplicationLaunchJobResult(KJob *job)
{
    if (job->error()) {
        setError(job->error());
        setErrorText(job->errorString());
    }

    emitResult();
}

}
}

#include "moc_launchjob.cpp"
