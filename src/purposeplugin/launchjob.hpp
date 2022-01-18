/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KODASKANNA_PURPOSEPLUGIN_LAUNCHJOB_HPP
#define KODASKANNA_PURPOSEPLUGIN_LAUNCHJOB_HPP

// KF
#include <Purpose/Job>

namespace Kodaskanna
{

namespace PurposePlugin
{

class LaunchJob : public Purpose::Job
{
    Q_OBJECT

public:
    explicit LaunchJob(QObject *parent);

public: // Purpose::Job API
    void start() override;

private:
    void handleApplicationLaunchJobResult(KJob *job);
};

}
}

#endif
