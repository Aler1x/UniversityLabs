#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>

#include <QRadioButton>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QRegularExpression>

#include <stack>
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
		~Widget() {	}

		// create button and connect to chosed slot
		QPushButton * createAndConnectNumberAlphaButton(const QString &strButtonName, const QString &strButtonStyle);
		QPushButton * createAndConnectOperatorButton(const QString &strButtonName, const QString &strButtonStyle);
		QPushButton * createChooseTypeButton(const QString &strButtonName, const QString &strButtonStyle);

	private slots:
		void ButtonNumberAlphaClicked();	//slot for numbers and letters buttons
		void ButtonOperatorClicked(); //slot for operator buttons

	private:
		std::stack<std::string> stack;
		QLabel *m_UpperLabel, *m_BottomLabel; //BottomLabel current entered, Upper previously entered
		QString m_strDisplay;	//String saved information from display
		QPushButton *m_HexButton, *m_DecButton, *m_BinButton;

		QRegularExpression m_CheckInputData;
		QRegularExpression m_CheckBinaryData;
		QRegularExpression m_CheckDecimalData;
		QRegularExpression m_CheckHeximalData;

};
#endif // WIDGET_H
