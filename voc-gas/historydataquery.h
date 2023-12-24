﻿#ifndef HISTORYDATAQUERY_H
#define HISTORYDATAQUERY_H

#include <QWidget>
#include <QPushButton>
#include <QDateTime>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QStringList>
#include <QComboBox>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QFile>
#include <QPen>
#include <QColor>
#include <QFont>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QScrollBar>

#include "xlsxworksheet.h"
#include "xlsxformat.h"
#include "common.h"
#include "factorinfo.h"
#include "historychartview.h"
#include "xlsxdocument.h"

namespace Ui {
class HistoryDataQuery;
}

class HistoryDataQuery : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryDataQuery(QWidget *parent = nullptr);
    ~HistoryDataQuery();
    void widgetinit();
    void connectevent();
    void databaseinit();
    //构造表格
    void buildDefaultTable(int rows,int cols);
    void mergeCell(int rows,int cols);
    void fillindfttxt(int rows,int cols);
    void modifyTable();
    void editDataRow(QDateTime dt_start,QDateTime dt_end);
    void filldateTime(QDateTime dt_start,QDateTime dt_end);
    void fillinDatas();
    void calStastics();

signals:


public slots:
    void onQuery();
    void onExport();
    void on_comboBox_currentChanged(const QString &);

private:
    Ui::HistoryDataQuery *ui;
    QSqlDatabase curdb;
    QString tableName,queryFormat;
    QMap<QString,QStringList> resMap;

};

#endif // HISTORYDATAQUERY_H
