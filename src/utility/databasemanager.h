#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVariant>
#include <memory>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    static DatabaseManager& instance();

    bool connect(const QString& host, int port,
                 const QString& dbName, const QString& user,
                 const QString& password);
    void disconnect();
    bool isConnected() const;

    // Базовые операции
    QSqlQuery executeQuery(const QString& query,
                          const QVariantList& params = QVariantList());
    bool executeNonQuery(const QString& query,
                        const QVariantList& params = QVariantList());

    // Транзакции
    bool beginTransaction();
    bool commitTransaction();
    bool rollbackTransaction();

private:
    DatabaseManager(QObject* parent = nullptr);
    ~DatabaseManager();

    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase m_db;
};


#endif // DATABASEMANAGER_H
