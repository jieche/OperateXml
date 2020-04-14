#ifndef OPERATEXML_H
#define OPERATEXML_H

#include <QtWidgets/QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QString>
#include <QtXml>
#include <QDomDocument>
#include <QStringList>
#include "ui_operatexml.h"
struct cityInfo
{
	QString name;
	double  lon;
	double  lat;
};
class OperateXml : public QMainWindow
{
	Q_OBJECT

public:
	OperateXml(QWidget *parent = 0);
	~OperateXml();

	void load();//初始化列表
	void add();//添加入列表
	void del();//删除选中
	void saveXML();//保存到xml
	void readXML();//从xml中读取
	void update();//刷新界面数据
public slots:
	void selectItem(const QModelIndex &);

private:
	Ui::OperateXmlClass ui;
	std::vector<cityInfo> m_cityList;
	QStandardItemModel  *m_model;

};

#endif // OPERATEXML_H
