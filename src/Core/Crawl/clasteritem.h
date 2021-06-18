//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "iworlditem.h"

#include <QSet>


#ifndef CLASTERITEM_H
#define CLASTERITEM_H

class Claster;

/**
 * @brief The ClasterItem class This is item of the claster object. Thi class can be used as a one element of the claster class.
 * @note This object invoke the Claster::remove method in destructor.
 */
class ClasterItem: public IWorldItem
{
    Q_OBJECT
public:
    ClasterItem();
    ~ClasterItem();

protected:
    /**
     * @brief setClaster invoked when object added to new claster.
     * @param claster pointer to invoker claster object.
     */
    virtual void setClaster(Claster *claster);

    /**
     * @brief removeClaster
     * @param claster
     */
    virtual void removeClaster(Claster *claster);

    /**
     * @brief parentClasters return current parent clasters list;
     * @return
     */
    const QSet<Claster *> &parentClasters() const;
private:

    QSet<Claster*> _parentClasters;

    friend class Claster;
};

#endif // CLASTERITEM_H
