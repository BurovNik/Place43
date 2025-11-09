#ifndef EXTRASERVICEMODEL_H
#define EXTRASERVICEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "extraService.h"

class ExtraServiceModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ExtraServiceModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void populate(const QList<ExtraService> &services);

private:
    QList<ExtraService> m_services;
};

#endif // EXTRASERVICEMODEL_H
