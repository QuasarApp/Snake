#ifndef NETWORKPROFILEMAINMODEL_H
#define NETWORKPROFILEMAINMODEL_H

#include <QObject>
#include "settings.h"
#include "worldviewdata.h"

namespace ViewSolutions {
class ListViewModel;
}

class WorldInfo;

/**
 * @brief The MainMenuModel class This is main class for controll user interface
 */
class MainMenuModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* userSettingsModel READ userSettingsModel NOTIFY userSettingsModelChanged)
    Q_PROPERTY(QObject * availableLvlsModel READ availableLvlsModel NOTIFY availableLvlsModelChanged)

public:
    MainMenuModel(QObject *ptr = nullptr);
    QObject* userSettingsModel() const;
    QObject* availableLvlsModel() const;
    void setAvailableLvls(const QList<QObject *> &newData);
    Q_INVOKABLE void newGame(const QString& lvl);


signals:
    void userSettingsModelChanged(QObject* userSettingsModel);
    void sigNewGame(const QString& lvl);
    void availableLvlsModelChanged();

private:
    Settings *_conf = nullptr;
    QObject* _userSettingsModel = nullptr;
    ViewSolutions::ListViewModel *_availableLvlsModel = nullptr;

};

#endif // NETWORKPROFILEMAINMODEL_H