#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>

#include <QMessageBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QString>

#include <iostream>
#include "number.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
		Q_OBJECT

	public:
		Widget(QWidget *parent = nullptr);
		~Widget();

		QPushButton * createAndConnectNumberAlphaButton(const QString &strButtonName, const QString &strButtonStyle);
		QPushButton * createAndConnectOperatorButton(const QString &strButtonName, const QString &strButtonStyle);

		void Convert(Number * num);

	private slots:
		void ButtonNumberAlphaClicked();	//slot for numbers and letters buttons
		void ButtonOperatorClicked(); //slot for operator buttons
		void ButtonSetChecked(); // slot for type set button

	private:
		Number *m_a = new Number();
		Number *m_b = new Number();
		Number *m_c = new Number();

		std::string m_OperatorArray[6] = {"÷","×","−","+","=","⌫"};
		int m_CurrentTask;

		QString m_CurrentCheckedButon;
		QLabel *m_UpperLabel, *m_BottomLabel;
		QPushButton *m_HexButton, *m_DecButton, *m_BinButton;
};
#endif // WIDGET_H
