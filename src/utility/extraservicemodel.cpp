#include "extraservicemodel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

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
    // Теперь 5 столбцов: ID, Имя, Стоимость, Кнопка Обновить, Кнопка Удалить
    return parent.isValid() ? 0 : 5;
}

QVariant ExtraServiceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        const ExtraService &service = m_services[index.row()];
        switch (index.column()) {
        case 0: return service.id;
        case 1: return service.name;
        case 2: return QString::number(service.cost, 'f', 1);
        case 3: return "Обновить"; // Текст для кнопки обновления
        case 4: return "Удалить";  // Текст для кнопки удаления
        default: return QVariant();
        }
    }

    return QVariant();
}

QVariant ExtraServiceModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case 0: return "ID";
    case 1: return "Имя";
    case 2: return "Стоимость";
    case 3: return "Действия"; // Заголовок для столбца с кнопками
    case 4: return QVariant(); // Пустой заголовок для второй кнопки
    default: return QVariant();
    }
}

void ExtraServiceModel::populate(const QList<ExtraService> &services)
{
    beginResetModel();
    m_services = services;
    endResetModel();
}

ExtraService ExtraServiceModel::getService(const QModelIndex &index) const
{
    if (!index.isValid() || index.row() >= m_services.size())
        return ExtraService();

    return m_services.at(index.row());
}

ExtraService ExtraServiceModel::getService(int row) const
{
    if (row < 0 || row >= m_services.size())
        return ExtraService();

    return m_services.at(row);
}

void ExtraServiceModel::updateService(int row, const ExtraService &service)
{
    if (row < 0 || row >= m_services.size())
        return;

    beginResetModel();
    m_services[row] = service;
    endResetModel();
}

void ExtraServiceModel::addService(const ExtraService &service)
{
    beginInsertRows(QModelIndex(), m_services.size(), m_services.size());
    m_services.append(service);
    endInsertRows();
}

void ExtraServiceModel::removeService(int row)
{
    if (row < 0 || row >= m_services.size())
        return;

    beginRemoveRows(QModelIndex(), row, row);
    m_services.removeAt(row);
    endRemoveRows();
}
