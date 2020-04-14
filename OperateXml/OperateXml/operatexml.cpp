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
		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("名称长度超过15个字符")); return;
	}
	if (city.name.trimmed().length() ==0)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("名称不能为空")); return;
	}
	if (*lonOK == false)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("经度为非数字")); return;
	}
	if (*latOK == false)
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("纬度为非数字")); return;
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
	//获取选中行名称
	QModelIndex index = m_model->index(num, 0);
	QString name = m_model->data(index).toString();
	std::vector<cityInfo> tempList;
	for (int i = 0; i < m_cityList.size(); i++)
	{
		if (m_cityList[i].name==name)continue;//跳过选中行
		tempList.push_back(m_cityList[i]);
	}
	m_cityList.clear();
	m_cityList = tempList;//更新列表
	load();//更新界面
	saveXML();
}

void OperateXml::load()
{

	m_model = new QStandardItemModel();
	m_model->setColumnCount(3);
	m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("名称"));
	m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("经度"));
	m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("纬度"));
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
	//打开或创建文件
	QFile file("test.xml"); //相对路径、绝对路径、资源路径都行
	if (!file.open(QFile::ReadOnly))
		return;

	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomElement root = doc.documentElement(); //返回根节点
	QDomNode node = root.firstChild(); //获得第一个子节点
	while (!node.isNull())  //如果节点不空
	{
		if (node.isElement()) //如果节点是元素
		{
			cityInfo  city;
			QDomElement e = node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多
			if (e.tagName() == "city")
			{
				city.name = e.attribute("name");
				city.lon = e.attribute("lon").toDouble();
				city.lat = e.attribute("lat").toDouble();
				m_cityList.push_back(city);
			}
		}
		node = node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
	}
}
void OperateXml::saveXML()
{
	//打开或创建文件
	QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
	if (!file.open(QFile::WriteOnly | QFile::Truncate)) //可以用QIODevice，Truncate表示清空原来的内容
		return;

	QDomDocument doc;
	//写入xml头部
	QDomProcessingInstruction instruction; //添加处理命令
	instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	//添加根节点
	QDomElement root = doc.createElement("lib");
	doc.appendChild(root);
	int n = m_model->rowCount();
	for (int i = 0; i < m_cityList.size(); i++)
	{
		//添加一个子节点及其子元素
		QDomElement city = doc.createElement("city");
		/*QModelIndex indexName = m_model->index(i, 0);
		QModelIndex indexLon = m_model->index(i, 1);
		QModelIndex indexLat = m_model->index(i, 2);
		QString name = m_model->data(indexName).toString();
		QString lon = m_model->data(indexLon).toString();
		QString lat = m_model->data(indexLat).toString();*/

		city.setAttribute("name",m_cityList[i].name); //方式一：创建属性  其中键值对的值可以是各种类型
		city.setAttribute("lon", m_cityList[i].lon); //方式一：创建属性  其中键值对的值可以是各种类型
		city.setAttribute("lat", m_cityList[i].lat); //方式一：创建属性  其中键值对的值可以是各种类型
		root.appendChild(city);
	}
	//输出到文件
	QTextStream out_stream(&file);
	doc.save(out_stream, 4); //缩进4格
	file.close();
}