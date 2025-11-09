#ifndef EXTRASERVICE_H
#define EXTRASERVICE_H

#include <QString>

struct ExtraService {
    int id;
    QString name;
    double cost;

    ExtraService(int id = 0, const QString& name = "", double cost = 0.0)
        : id(id), name(name), cost(cost) {}
};
#endif // EXTRASERVICE_H
