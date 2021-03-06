//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QString>

class IWorld;

/**
 * @brief The PluginLoader class This class load shared objects like a plugins.
 */
class PluginLoader {
public:
    PluginLoader();

    /**
     * @brief load This method load a plugin game module.
     * @param pluginPath Path to so or dll plugin file.
     * @return Snake WorldInstance;
     * @note The plugin shiold be implement instance function and if you youse Windows systems marked as a DLL_EXPORT symbol.
     */
    static IWorld* load(const QString& pluginPath);
};

#endif // PLUGINLOADER_H
