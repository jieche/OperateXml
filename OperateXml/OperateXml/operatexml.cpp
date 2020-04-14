#include "operatexml.h"
#include <QMessageBox>

OperateXml::OperateXml(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	readXML();
	load();
	connect(ui.pushButton_add, &QPushButton::clicked, this, &OperateXml::add);
	connect(ui.pushButton_del, &QPushButton::clicked, this, &OperateXml::del);
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex &)), this,
		SLOT(selectItem(const QModelIndex &)));
}

OperateXml::~OperateXml()
{


}
void OperateXml::selectItem(const QModelIndex &)
{

}
void OperateXml::add()
{
	cityInfo city;
	city.name = ui.lineEdit_name->text();
	bool* lonOK = new  bool;
	bool* latOK=new bool;
	QString lon = ui.lineEdit_lon->text();
	city.lon = lon.toDouble(lonOK);
	QString lat = ui.lineEdit_lon->text();
	city.lat = lat.toDouble(latOK);
	if (city.name.length() > 15)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���Ƴ��ȳ���15���ַ�")); return;
	}
	if (city.name.trimmed().length() ==0)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���Ʋ���Ϊ��")); return;
	}
	if (*lonOK == false)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����Ϊ������")); return;
	}
	if (*latOK == false)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("γ��Ϊ������")); return;
	}
	m_cityList.push_back(city);
	saveXML();
	ui.lineEdit_name->clear();
	ui.lineEdit_lon->clear();
	ui.lineEdit_lat->clear();
	load();
}
void OperateXml::del()
{
	int num=ui.tableView->currentIndex().row();
	//m_model->removeRow(num);
	//��ȡѡ��������
	QModelIndex index = m_model->index(num, 0);
	QString name = m_model->data(index).toString();
	std::vector<cityInfo> tempList;
	for (int i = 0; i < m_cityList.size(); i++)
	{
		if (m_cityList[i].name==name)continue;//����ѡ����
		tempList.push_back(m_cityList[i]);
	}
	m_cityList.clear();
	m_cityList = tempList;//�����б�
	load();//���½���
	saveXML();
}

void OperateXml::load()
{

	m_model = new QStandardItemModel();
	m_model->setColumnCount(3);
	m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("γ��"));
	if (!m_cityList.empty())
	{
		for (int i = 0; i < m_cityList.size(); i++)
		{
			m_model->setItem(i, 0, new QStandardItem(m_cityList[i].name));
			m_model->setItem(i, 1, new QStandardItem(QString::number(m_cityList[i].lon)));
			m_model->setItem(i, 2, new QStandardItem(QString::number(m_cityList[i].lat)));
		}
	}
	ui.tableView->setModel(m_model);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
void OperateXml::readXML()
{
	//�򿪻򴴽��ļ�
	QFile file("test.xml"); //���·��������·������Դ·������
	if (!file.open(QFile::ReadOnly))
		return;

	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomElement root = doc.documentElement(); //���ظ��ڵ�
	QDomNode node = root.firstChild(); //��õ�һ���ӽڵ�
	while (!node.isNull())  //����ڵ㲻��
	{
		if (node.isElement()) //����ڵ���Ԫ��
		{
			cityInfo  city;
			QDomElement e = node.toElement(); //ת��ΪԪ�أ�ע��Ԫ�غͽڵ����������ݽṹ����ʵ���
			if (e.tagName() == "city")
			{
				city.name = e.attribute("name");
				city.lon = e.attribute("lon").toDouble();
				city.lat = e.attribute("lat").toDouble();
				m_cityList.push_back(city);
			}
		}
		node = node.nextSibling(); //��һ���ֵܽڵ�,nextSiblingElement()����һ���ֵ�Ԫ�أ������
	}
}
void OperateXml::saveXML()
{
	//�򿪻򴴽��ļ�
	QFile file("test.xml"); //���·��������·������Դ·��������
	if (!file.open(QFile::WriteOnly | QFile::Truncate)) //������QIODevice��Truncate��ʾ���ԭ��������
		return;

	QDomDocument doc;
	//д��xmlͷ��
	QDomProcessingInstruction instruction; //��Ӵ�������
	instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	//��Ӹ��ڵ�
	QDomElement root = doc.createElement("lib");
	doc.appendChild(root);
	int n = m_model->rowCount();
	for (int i = 0; i < m_cityList.size(); i++)
	{
		//���һ���ӽڵ㼰����Ԫ��
		QDomElement city = doc.createElement("city");
		/*QModelIndex indexName = m_model->index(i, 0);
		QModelIndex indexLon = m_model->index(i, 1);
		QModelIndex indexLat = m_model->index(i, 2);
		QString name = m_model->data(indexName).toString();
		QString lon = m_model->data(indexLon).toString();
		QString lat = m_model->data(indexLat).toString();*/

		city.setAttribute("name",m_cityList[i].name); //��ʽһ����������  ���м�ֵ�Ե�ֵ�����Ǹ�������
		city.setAttribute("lon", m_cityList[i].lon); //��ʽһ����������  ���м�ֵ�Ե�ֵ�����Ǹ�������
		city.setAttribute("lat", m_cityList[i].lat); //��ʽһ����������  ���м�ֵ�Ե�ֵ�����Ǹ�������
		root.appendChild(city);
	}
	//������ļ�
	QTextStream out_stream(&file);
	doc.save(out_stream, 4); //����4��
	file.close();
}