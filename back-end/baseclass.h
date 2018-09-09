#ifndef BASECLASS_H
#define BASECLASS_H
#include <QString>

class BaseClass
{
private:
    QString name;
public:
    BaseClass();
    virtual void render() = 0;
    virtual ~BaseClass();
    QString getName() const;
};

#endif // BASECLASS_H
