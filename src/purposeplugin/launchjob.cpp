/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "launchjob.hpp"

// KF
#include <KIO/ApplicationLauncherJob>
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
    const QUrl url(urls.at(0).toString());

    KService::Ptr service = KService::serviceByDesktopName(QStringLiteral("org.kde.kodaskanna"));

    if (!service) {
        setErrorText(i18n("Could not find Kodaskanna."));
        emitResult();
        return;
    }

    auto *applicationLauncherJob = new KIO::ApplicationLauncherJob(service);
    applicationLauncherJob->setUrls({url});
    connect(applicationLauncherJob, &KIO::ApplicationLauncherJob::result,
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
