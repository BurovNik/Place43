#include "extraservicemodel.h"

ExtraServiceModel::ExtraServiceModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ExtraServiceModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_services.size();
}

int ExtraServiceModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;
}

QVariant ExtraServiceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const ExtraService &service = m_services[index.row()];
    switch (index.column()) {
    case 0: return service.id;
    case 1: return service.name;
    case 2: return QString::number(service.cost, 'f', 1);
    default: return QVariant();
    }
}

QVariant ExtraServiceModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case 0: return "ID";
    case 1: return "Имя";
    case 2: return "Стоимость";
    default: return QVariant();
    }
}

void ExtraServiceModel::populate(const QList<ExtraService> &services)
{
    beginResetModel();
    m_services = services;
    endResetModel();
}
