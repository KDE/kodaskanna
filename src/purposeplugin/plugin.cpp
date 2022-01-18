/*
    SPDX-FileCopyrightText: 2022 Friedrich W. H. Kossebau <kossebau@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

// own
#include "launchjob.hpp"
// KF
#include <Purpose/PluginBase>
#include <KPluginFactory>

class KodaskannaPurposePlugin : public Purpose::PluginBase
{
    Q_OBJECT

public:
    KodaskannaPurposePlugin(QObject *p, const QVariantList &)
        : Purpose::PluginBase(p)
    {
    }

    Purpose::Job *createJob() const override
    {
        return new Kodaskanna::PurposePlugin::LaunchJob(nullptr);
    }
};

EXPORT_SHARE_VERSION // Purpose define needed to specify the plugin version
K_PLUGIN_CLASS_WITH_JSON(KodaskannaPurposePlugin, "plugin.json")

#include "plugin.moc"
