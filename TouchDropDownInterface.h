#ifndef _TOUCH_DROP_DOWN_INTERFACE_H
#define _TOUCH_DROP_DOWN_INTERFACE_H

#include <QDesignerCustomWidgetInterface>
#include <QFrame>
#include <QComboBox>
#include <QVBoxLayout>

/* Dummy implement of TouchDropDown */
class TouchDropDown : public QFrame
{
	Q_OBJECT
  public:
	TouchDropDown(QWidget *parent=0) : QFrame(parent) {
		QVBoxLayout *box = new QVBoxLayout(this);
		box->setSpacing(0);
		QComboBox *combo = new QComboBox(this);
		combo->setStyleSheet("border: 0px; background-color: white;");
		box->addWidget(combo);
		box->setContentsMargins(0, 0, 0, 0);
	}

  signals:
    void currentIndexChanged(int);

  public slots:
	void setCurrentIndex(int);
	void setCurrentIndex(QString const &);
	void setCurrentIndexFromData(QVariant const &);
	void showMenu();
};

/* TouchDropDownInterface */
class TouchDropDownInterface : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    TouchDropDownInterface(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized;
};

#endif // _TOUCH_DROP_DOWN_INTERFACE_H
