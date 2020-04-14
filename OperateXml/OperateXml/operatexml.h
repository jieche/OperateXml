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

	void load();//��ʼ���б�
	void add();//������б�
	void del();//ɾ��ѡ��
	void saveXML();//���浽xml
	void readXML();//��xml�ж�ȡ
	void update();//ˢ�½�������
public slots:
	void selectItem(const QModelIndex &);

private:
	Ui::OperateXmlClass ui;
	std::vector<cityInfo> m_cityList;
	QStandardItemModel  *m_model;

};

#endif // OPERATEXML_H
