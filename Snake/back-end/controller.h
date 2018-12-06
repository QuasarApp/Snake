#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include "diff.h"
#include "snake.h"
#include "world.h"

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int long_ READ long_ NOTIFY long_changed)
    Q_PROPERTY(int generalLong READ generalLong NOTIFY generalLongchanged)

private:
    World world;
    QTimer *timer;
    bool pause = false;
    int lvl = 0;
    QMap<int, GuiObject *> objectsContainer;

    void generateDiff(const QMap<int, GuiObject *> &);

    int m_generalLong = 0;

public:
    Controller();
    void startTimer();
    void stopTimer();

    int long_() const;

    int generalLong() const;

public slots:
    void buttonPress();

    void setPause(bool);

    void update();

    /**
     * @brief nextLvl - switch to next lvl from array lvels
     * @return true if all levels are passed
     */
    bool nextLvl();

    /**
     * @brief newGame - start game from first lvl
     */
    void newGame();

    /**
     * @brief getGameObject
     * @param id - id of guiObject;
     * @return guiObject if (id is not valid return nullptr)
     */
    QObject* getGameObject(int id);

signals:
    /**
     * @brief finished - imited when game over or victory
     * @param victory - flag of vicrory, if it equals false then game over
     * @param lvl - game over lvl
     * @param distance - game over distance
     */
    void finished(bool victory, int lvl, double distance);

    /**
     * @brief gameObjectsChanged
     * @param dif
     */
    void gameObjectsChanged(const Diff &dif);
    void long_changed(int m_long);
    void generalLongchanged(int generalLong);
};

#endif // CONTROLLER_H