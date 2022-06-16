#include "widget.h"
#include "ui_widget.h"

void Widget::ButtonNumberAlphaClicked() {
	QString str = ((QPushButton*)sender())->text();

	if(this->m_BinButton->isChecked()) {
		this->m_BottomLabel->setText(this->m_BottomLabel->text() + str);
		return;
	} else if(this->m_BottomLabel->text() == "0"){
		this->m_BottomLabel->clear();
		this->m_BottomLabel->setText(this->m_BottomLabel->text() + str);
		return;
	} else {
		this->m_BottomLabel->setText(this->m_BottomLabel->text() + str);
		return;
	}
}

void Widget::Convert(Number * num) {
	if(this->m_CurrentCheckedButon == "Bin") {
		try {
			num->fromBinary(this->m_BottomLabel->text().toStdString());
		} catch(int err){
			qDebug() << "Convertation error";
			throw;
		}
	}
	if(m_CurrentCheckedButon == "Dec") {
		try {
			num->fromDec(this->m_BottomLabel->text().toStdString());
		} catch(int err){
			qDebug() << "Convertation error";
			throw;
		}
	}
	if(m_CurrentCheckedButon == "Hex") {
		try {
			num->fromHex(this->m_BottomLabel->text().toStdString());
		} catch(int err){
			qDebug() << "Convertation error";
			throw;
		}
	}
}

void Widget::ButtonOperatorClicked() {
	std::string strButton = ((QPushButton*)sender())->text().toStdString();

	int i = 0;
	while(m_OperatorArray[i] != strButton){
		++i;
	}

	//0 "÷" //1 "×"	//2 "−"	//3 "+"	//4 "="	//5 "⌫"

	QString OperatorString[5] = {"÷", "×", "-", "+", "="};

	try{
	switch(i){
		case 0 :{
			try {
				this->Convert(this->m_a);
			}
			catch(int){
				throw;
			}
			this->m_CurrentTask = 1;
			this->m_UpperLabel->setText(this->m_BottomLabel->text() + " " + ((QPushButton*)sender())->text());
			this->m_BottomLabel->setText("0");
			break;
		}
		case 1 :{
			try {
				this->Convert(this->m_a);
			}
			catch(int){
				throw;
			}
			this->m_CurrentTask = 2;
			this->m_UpperLabel->setText(this->m_BottomLabel->text() + " " + ((QPushButton*)sender())->text());
			this->m_BottomLabel->setText("0");
			break;
		}
		case 2 :{
			try {
				this->Convert(this->m_a);
			}
			catch(int){
				throw;
			}
			this->m_CurrentTask = 3;
			this->m_UpperLabel->setText(this->m_BottomLabel->text() + " " + ((QPushButton*)sender())->text());
			this->m_BottomLabel->setText("0");
			break;
		}
		case 3 :{
			try {
				this->Convert(this->m_a);
			}
			catch(int){
				throw;
			}
			this->m_CurrentTask = 4;
			this->m_UpperLabel->setText(this->m_BottomLabel->text() + " " + ((QPushButton*)sender())->text());
			this->m_BottomLabel->setText("0");
			break;
		}
		case 4 :{
			if(!m_CurrentTask) {
				throw "Number not entered";
			}

			try {
				this->Convert(this->m_b);
			}
			catch(int){
				throw;
			}

			switch(this->m_CurrentTask) {
				case 1: {
					*m_c = *m_a / *m_b;
					break;
				}
				case 2: {
					*m_c = *m_a * *m_b;
					break;
				}
				case 3: {
					*m_c = *m_a - *m_b;
					break;
				}
				case 4: {
					*m_c = *m_a + *m_b;
					break;
				}
			}

			this->m_UpperLabel->setText(this->m_UpperLabel->text() + " " + this->m_BottomLabel->text());

			if(this->m_CurrentCheckedButon == "Bin") {
				this->m_BottomLabel->setText(QString::fromStdString(m_c->toBin()));
			}
			if(m_CurrentCheckedButon == "Dec") {
				this->m_BottomLabel->setText(QString::fromStdString(m_c->toDec()));
			}
			if(m_CurrentCheckedButon == "Hex") {
				this->m_BottomLabel->setText(QString::fromStdString(m_c->toHex()));
			}

			break;
		}
		case 5 :{
			if(this->m_BottomLabel->text() != "0") {
				this->m_BottomLabel->setText(this->m_BottomLabel->text().chopped(1));
				if(this->m_BottomLabel->text() == "") {
					this->m_BottomLabel->setText("0");
				}
			}
			break;
		}
	}
	}
	catch(double dnum) {
		QMessageBox * msg = new QMessageBox(this);
		msg->setText("You cannot divide by 0");
		msg->show();
	}
	catch(const char *str) {
		QMessageBox * msg = new QMessageBox(this);
		msg->setText("Numbers not entered!");
		msg->show();
	}
	catch(int num) {
		QMessageBox * msg = new QMessageBox(this);
		msg->setText("Convertation error\nChoose another type");
		msg->show();
	}
}

void Widget::ButtonSetChecked(){
	QString strButton = ((QPushButton*)sender())->text();
	if(strButton == "Hex") {
		this->m_BinButton->setChecked(false);
		this->m_DecButton->setChecked(false);
		this->m_CurrentCheckedButon = "Hex";
	} else if(strButton == "Dec") {
		this->m_BinButton->setChecked(false);
		this->m_HexButton->setChecked(false);
		this->m_CurrentCheckedButon = "Dec";
	} else if(strButton == "Bin") {
		this->m_HexButton->setChecked(false);
		this->m_DecButton->setChecked(false);
		this->m_CurrentCheckedButon = "Bin";
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
	: QWidget(parent) {
	this->setFixedSize(250,400);
	this->setWindowIcon(QIcon("://icon//keys.png"));
	this->setWindowTitle("Calculator");
	this->setStyleSheet(
				"QWideget { background-color: #ebedff;}"
				"QPushButton {max-height: 50px; max-width: 50px;}"
						);


	QString PushButtonsName[5][5] = {{"A","Hex","Dec","Bin","÷"},
									 {"B","7","8","9","×"},
									 {"C","4","5","6","−"},
									 {"D","1","2","3","+"},
									 {"E","F","0","⌫","="}
									};
	this->m_UpperLabel = new QLabel;
	this->m_BottomLabel = new QLabel("0");
	m_UpperLabel->setStyleSheet("QLabel {background-color: #fff; font-family: Source Code Pro; font: bold 25px; }");
	m_BottomLabel->setStyleSheet("QLabel {background-color: #fff; font-family: Source Code Pro; font: bold 30px; }");
	m_UpperLabel->setAlignment(Qt::AlignRight);
	m_BottomLabel->setAlignment(Qt::AlignRight);
	m_BottomLabel->setCursor(QCursor(Qt::IBeamCursor));

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
								  "QPushButton::pressed {"
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
								  "QPushButton::pressed {"
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
	this->m_HexButton->setStyleSheet(OperatorButtonStyle);
	this->m_HexButton->setCheckable(true);
	connect(this->m_HexButton, SIGNAL(clicked()), SLOT(ButtonSetChecked()));
	mainLayout->addWidget(m_HexButton, 2, 1);

	this->m_DecButton = new QPushButton("Dec");
	this->m_DecButton->setStyleSheet(OperatorButtonStyle);
	this->m_DecButton->setCheckable(true);
	this->m_DecButton->setChecked(true);
	connect(this->m_DecButton, SIGNAL(clicked()), SLOT(ButtonSetChecked()));
	mainLayout->addWidget(m_DecButton, 2, 2);

	this->m_BinButton = new QPushButton("Bin");
	this->m_BinButton->setStyleSheet(OperatorButtonStyle);
	this->m_BinButton->setCheckable(true);
	connect(this->m_BinButton, SIGNAL(clicked()), SLOT(ButtonSetChecked()));
	mainLayout->addWidget(m_BinButton, 2, 3);

	this->m_CurrentCheckedButon = "Dec";
	this->m_CurrentTask = 0;

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
}

Widget::~Widget() {
	delete m_a;
	delete m_b;
	delete m_c;

	delete m_UpperLabel;
	delete m_BottomLabel;

	delete m_HexButton;
	delete m_DecButton;
	delete m_BinButton;
}
