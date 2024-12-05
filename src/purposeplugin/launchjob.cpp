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
    const QJsonArray jsonUrls = data().value(QStringLiteral("urls")).toArray();
    if (jsonUrls.size() < 1) {
        // TODO: after string unfreeze change to "Need at least one URL."
        setErrorText(i18n("Need one URL."));
        emitResult();
        return;
    }

    const QString desktopName = QStringLiteral("org.kde.kodaskanna");
    KService::Ptr service = KService::serviceByDesktopName(desktopName);

    if (!service) {
        setErrorText(i18n("Could not find Kodaskanna."));
        emitResult();
        return;
    }

    m_applicationLaunchJobsWaitedFor = jsonUrls.size();

    for (const auto &jsonUrl : jsonUrls)  {
        const QString url = jsonUrl.toString();
        // TODO: using CommandLauncherJob instead of ApplicationLauncherJob, due to additional arg
        // Perhaps should get instead a dedicate separate service desktop file with NoDisplay?
        auto *applicationLauncherJob = new KIO::CommandLauncherJob(service->exec(), {QStringLiteral("--onescan"), url});
        applicationLauncherJob->setDesktopName(desktopName);
        connect(applicationLauncherJob, &KIO::CommandLauncherJob::result,
                this, &LaunchJob::handleApplicationLaunchJobResult);
        applicationLauncherJob->start();
    }
}

void LaunchJob::handleApplicationLaunchJobResult(KJob *job)
{
    // TODO: for now just reporting last error on multiple jobs, find a good way to report all
    if (job->error()) {
        setError(job->error());
        setErrorText(job->errorString());
    }

    --m_applicationLaunchJobsWaitedFor;

    if (m_applicationLaunchJobsWaitedFor > 0) {
        return;
    }

    emitResult();
}

}
}

#include "moc_launchjob.cpp"
