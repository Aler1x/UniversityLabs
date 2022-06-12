#include "widget.h"
#include "ui_widget.h"

Number *a = new Number;
Number *b = new Number;

void Widget::ButtonNumberAlphaClicked() {
	QString str = ((QPushButton*)sender())->text();
	if(!this->m_BinButton->isChecked()) {
		if(str.contains(m_CheckInputData)) {
			if(this->m_BottomLabel->text() != "0"){
			this->m_BottomLabel->setText(this->m_BottomLabel->text() + str);
			} else {
			this->m_BottomLabel->setText(this->m_BottomLabel->text().chopped(1));
			this->m_BottomLabel->setText(this->m_BottomLabel->text() + str);
			}
		}
	} else {
		this->m_BottomLabel->setText(this->m_BottomLabel->text() + str);
	}
}


void Widget::ButtonOperatorClicked() {
	QString strButton = ((QPushButton*)sender())->text();

	if(strButton.contains("⌫")) {
		if(this->m_BottomLabel->text() != ""){
		this->m_BottomLabel->setText(this->m_BottomLabel->text().chopped(1));
			if(this->m_BottomLabel->text() == ""){
				this->m_BottomLabel->setText("0");
			}
		} else {
			this->m_BottomLabel->setText("0");
		}
		return;
	}

	try {

		if(this->m_BinButton->isChecked() && this->m_DecButton->isChecked() && this->m_HexButton->isChecked()) {
			throw("Error: choosed so many type buttons");
		} else if (this->m_BinButton->isChecked() && this->m_DecButton->isChecked()) {
			throw("Error: choosed so many type buttons");
		} else if(this->m_DecButton->isChecked() && this->m_HexButton->isChecked()) {
			throw("Error: choosed so many type buttons");
		} else if(this->m_BinButton->isChecked() && this->m_HexButton->isChecked()) {
			throw("Error: choosed so many type buttons");
		} else {

			if(this->m_BinButton->isChecked()){
				this->stack.emplace(this->m_BottomLabel->text().toStdString());
			} else if(this->m_DecButton->isChecked()){
				this->stack.emplace(this->m_BottomLabel->text().toStdString());
			} else if(this->m_HexButton->isChecked()){
				this->stack.emplace(this->m_BottomLabel->text().toStdString());
			} else {
				throw("Error: type not choosed");
			}

			if(strButton.contains("÷")){
				this->stack.emplace("/");
			} else if(strButton.contains("×")) {
				this->stack.emplace("*");
			} else if(strButton.contains("−")) {
				this->stack.emplace("-");
			} else if(strButton.contains("+")) {
				this->stack.emplace("+");
			} else if(strButton.contains("=")) {

		}
	}
	}
	catch(const char* &str){
		qDebug() << "Error: operand error";
	}
}


QPushButton * Widget::createAndConnectNumberAlphaButton(const QString &strButtonName, const QString &strButtonStyle) {
	QPushButton * button = new QPushButton(strButtonName);

	button->setStyleSheet(strButtonStyle);
	button->setShortcut(QKeySequence(strButtonName));

	connect(button, SIGNAL(clicked()), SLOT(ButtonNumberAlphaClicked()));

	return button;
}

QPushButton * Widget::createAndConnectOperatorButton(const QString &strButtonName, const QString &strButtonStyle) {
	QPushButton * button = new QPushButton(strButtonName);

	button->setStyleSheet(strButtonStyle);
	if(strButtonName.contains("⌫")) {
		button->setShortcut(QKeySequence(Qt::Key_Backspace));
	}

	connect(button, SIGNAL(clicked()), SLOT(ButtonOperatorClicked()));

	return button;
}

Widget::Widget(QWidget *parent)
	: QWidget(parent),
	  m_CheckInputData("[A-Za-z0-9]"),
	  m_CheckBinaryData("[01]"),
	  m_CheckDecimalData("[0-9]"),
	  m_CheckHeximalData("[A-Za-z0-9]")
{
	this->setFixedSize(250,400);
	this->setWindowIcon(QIcon("://icon//keys.png"));
	this->setWindowTitle("Calculator");
	this->setStyleSheet("QWideget { background-color: #ebedff;}"
						"QPushButton {max-height: 50px; max-width: 50px;}"
						);


	this->m_UpperLabel = new QLabel;
	this->m_BottomLabel = new QLabel("0");
	m_UpperLabel->setStyleSheet("QLabel {background-color: #fff; font-family: Source Code Pro; font: bold 25px; }");
	m_BottomLabel->setStyleSheet("QLabel {background-color: #fff; font-family: Source Code Pro; font: bold 30px; }");
	m_UpperLabel->setAlignment(Qt::AlignRight);
	m_BottomLabel->setAlignment(Qt::AlignRight);
	m_BottomLabel->setCursor(QCursor(Qt::IBeamCursor));

	QString PushButtonsName[5][5] = {{"A","Hex","Dec","Bin","÷"},
									 {"B","7","8","9","×"},
									 {"C","4","5","6","−"},
									 {"D","1","2","3","+"},
									 {"E","F","0","⌫","="}
									};

	QString NumAlphaButtonStyle = " QPushButton {"
									"background-color: #fff;"
									"border-radius: 15px;"
									"color: #000;"
									"font-family: Source Code Pro;"
									"font: bold 17px;"
									"outline: none;"
									"padding: .75rem;"
									"border-bottom-left-radius: 15px 255px;"
									"border-bottom-right-radius: 255px 15px;"
									"border-top-left-radius: 255px 15px;"
									"border-top-right-radius: 15px 255px;}"
								  "QPushButton::presed {"
								  "border: 2px solid #0087f3;}";
	QString OperatorButtonStyle = " QPushButton {			"
									"background-color: #fff;"
									"border-radius: 15px;"
									"color: #0087f3;"
									"font-family: Source Code Pro;"
									"font: bold 20px;"
									"outline: none;"
									"padding: .75rem;"
									"border-bottom-left-radius: 15px 255px;"
									"border-bottom-right-radius: 255px 15px;"
									"border-top-left-radius: 255px 15px;"
									"border-top-right-radius: 15px 255px;}"
								  "QPushButton::presed {"
								  "border: 2px solid #0087f3;}";
	QString OtherButtonStyle =		"QPushButton {"
									"background-color: #fff;"
									"border-radius: 15px;"
									"color: #0087f3;"
									"font-family: Source Code Pro;"
									"font: bold 17px;"
									"outline: none;"
									"padding: .75rem;"
									"border-bottom-left-radius: 15px 255px;"
									"border-bottom-right-radius: 255px 15px;"
									"border-top-left-radius: 255px 15px;"
									"border-top-right-radius: 15px 255px;}"
									"QPushButton::presed {"
									"border: 2px solid #0087f3;}"
									"QPushButton::checked {"
									"background-color: #ebedff;}";

	QGridLayout * mainLayout = new QGridLayout;

	for(int i = 0; i < 5; i++) {
		QPushButton *pButton = createAndConnectNumberAlphaButton(PushButtonsName[i][0], NumAlphaButtonStyle);
		mainLayout->addWidget(pButton, i+2, 0);
		pButton = createAndConnectOperatorButton(PushButtonsName[i][4], OperatorButtonStyle);
		mainLayout->addWidget(pButton, i+2, 4);
	}

	this->m_HexButton = new QPushButton("Hex");
	this->m_HexButton->setStyleSheet(OtherButtonStyle);
	this->m_HexButton->setCheckable(true);
	mainLayout->addWidget(m_HexButton, 2, 1);
	this->m_DecButton = new QPushButton("Dec");
	this->m_DecButton->setStyleSheet(OtherButtonStyle);
	this->m_DecButton->setCheckable(true);
	mainLayout->addWidget(m_DecButton, 2, 2);
	this->m_BinButton = new QPushButton("Bin");
	this->m_BinButton->setStyleSheet(OtherButtonStyle);
	this->m_BinButton->setCheckable(true);
	mainLayout->addWidget(m_BinButton, 2, 3);

	for(int i = 1; i < 5; i++) {
		for(int j = 1; j < 4; j++) {
			if(PushButtonsName[i][j] != "⌫") {
			QPushButton *pButton = createAndConnectNumberAlphaButton(PushButtonsName[i][j], NumAlphaButtonStyle);
			mainLayout->addWidget(pButton, i+2, j);
			} else {
				QPushButton *pButton = createAndConnectOperatorButton(PushButtonsName[i][j], OperatorButtonStyle);
				mainLayout->addWidget(pButton, i+2, j);
			}
		}
	}


	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0,0,0,0);

	mainLayout->addWidget(this->m_UpperLabel, 0, 0, 1, 5);
	mainLayout->addWidget(this->m_BottomLabel, 1, 0, 1, 5);

	setLayout(mainLayout);
};
