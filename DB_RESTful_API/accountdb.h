#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H

#include "database.h"

class AccountDB : public DataBase
{
public:
    AccountDB();
    ~AccountDB();
    //출력
    QJsonArray  getAll() override;
    QJsonObject getLatest() override;
    QJsonObject getById(int id) override;
    QJsonObject getByCondition(const QString &cond,const QString &id) override;
    //입력
    bool insert(const QJsonObject &data) override;
    bool update(int id, const QJsonObject &data) override;
    bool remove(int id) override;

private:
    QString buildUpdateQuery(const QString &table, int id, const QJsonObject &data) override;
    QString buildInsertQuery(const QString &table, const QJsonObject &data) override;
    void bindJsonToQuery(QSqlQuery &query, const QJsonObject &data) override;
};

#endif // ACCOUNTDB_H
