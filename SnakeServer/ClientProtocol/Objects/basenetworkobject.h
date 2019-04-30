#ifndef BASENETWORKOBJECT_H
#define BASENETWORKOBJECT_H

#include "networkclasssize.h"

#include <cstdlib>
#include <QDataStream>
#include <QVector>
#include <typeinfo>
#include "config.h"
#include <type_traits>

namespace ClientProtocol {

typedef QByteArray SHA256;

template <typename T>
NetworkClassSize getTypeSize(const T& type = {}) {
    auto hash = typeid(type).hash_code();

    if (hash == typeid(QString).hash_code()) {

        return { sizeof (int), sizeof (QChar) * MAX_SIZE};

    } else if (hash == typeid(QList<int>).hash_code()) {

        return { sizeof (int), sizeof (int) * MAX_SIZE};

    } else if (hash == typeid(QList<float>).hash_code()) {

        return { sizeof (float), sizeof (float) * MAX_SIZE};

    } else if (hash == typeid(QStringList).hash_code()) {

        auto size = getTypeSize<QString>();
        return {sizeof (int) , size.max + static_cast<int>(sizeof (int) * MAX_SIZE)};

    } else if (hash == typeid(SHA256).hash_code()) {

        return {sizeof (int) + 32};

    }

    return sizeof (type);
}

class BaseNetworkObject
{
private:
    int _id = -1;
protected:
    qint8 _class = -1;

    BaseNetworkObject();

public:
    virtual BaseNetworkObject* create() const;
    virtual ~BaseNetworkObject();

    virtual NetworkClassSize classSize() const;
    virtual QDataStream& writeToStream(QDataStream& stream) const;
    virtual QDataStream& readFromStream(QDataStream& stream);
    virtual bool isValid() const;
    void toBytes(QByteArray& array) const;
    void fromBytes(const QByteArray& array);
    auto cast();
    int id() const;
    void setId(int id);
    qint8 getClass() const;
};

template<class T>
auto cast(const BaseNetworkObject* obj) {
    static_assert (!std::is_pointer<T>(), "Cast working only with pointers!");
    return static_cast<T>(obj);
}

}
#endif // BASENETWORKOBJECT_H