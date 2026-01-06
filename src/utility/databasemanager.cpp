#include "databasemanager.h"
#include <QDebug>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connect(const QString& host, int port,
                            const QString& dbName, const QString& user,
                            const QString& password)
{
    m_db = QSqlDatabase::addDatabase("QPSQL", "place43db_connection");
    m_db.setHostName(host);
    m_db.setPort(port);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(user);
    m_db.setPassword(password);

    if (!m_db.open()) {
        qDebug() << "Database error:" << m_db.lastError().text();
        return false;
    }

    return true;
}

QSqlQuery DatabaseManager::executeQuery(const QString& query,
                                       const QVariantList& params)
{
    QSqlQuery qry(m_db);
    qry.prepare(query);

    for (int i = 0; i < params.size(); ++i) {
        qry.bindValue(i, params[i]);
    }

    if (!qry.exec()) {
        qDebug() << "Query error:" << qry.lastError().text();
        qDebug() << "Query:" << query;
    }

    return qry;
}
