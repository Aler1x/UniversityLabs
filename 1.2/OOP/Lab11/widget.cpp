#include "widget.h"
#include "ui_widget.h"

#define N 6

template <typename Type1, typename Type2>
QString showStack(std::stack<Type1, Type2> &stk) {
	QString stack;
	std::stack<Type1, Type2> outstk = stk;
	for(size_t i = 0; i < stk.size(); i++){
		stack += QString::number(outstk.top()) += "  ";
		outstk.pop();
	}
	return stack;
}

template <typename Type1>
QString showQueue(std::queue<Type1> &queue) {
	QString q;
	std::queue<Type1> outqueue = queue;
	for(size_t i = 0; i < queue.size(); i++){
		q += QString::number(outqueue.front()) += "  ";
		outqueue.pop();
	}
	return q;
}

template <class T, class U, class Compare>
void sort_stack(std::stack<T,U> &stack, Compare comp)
{
	std::vector<T> tmp_container;
	tmp_container.reserve(stack.size());
	while(!stack.empty())
	{
		tmp_container.push_back(std::move(stack.top()));
		stack.pop();
	}
	std::sort(tmp_container.begin(), tmp_container.end(), comp);
	for(auto it:tmp_container)
	{
		stack.push(std::move(it));
	}
}
template <class T, class U>
void sort_stack(std::stack<T,U> &stack)
{
	sort_stack(stack, std::less<T>());
}

template <class T, class U>
void sort_stack2(std::stack<T,U> &stack)
{
	sort_stack(stack, std::greater<T>());
}

void Widget::OnStart() {
	bool ch = true;
	ch = stack_1.empty();
	qDebug() << ch;
	ch = stack_2.empty();
	qDebug() << ch;
	ch = queue.empty();
	qDebug() << ch;
	vector.clear();

	for(int i = 0; i < N; i++) {
		stack_1.push(i + 0.2*i);
		if(!i%2){
		stack_2.push(stack_1.top()+0.3);
		} else {
		stack_2.push(stack_1.top()-0.4);
		}
	}

	this->outputLabel_1->setText((showStack(stack_1))+"\n"+(showStack(stack_2)));
//--------------------------------------------------------------------------------------------//
	std::stack<float, std::vector<float>> stack_1_copy;
	for(int i = 0; i < N; i++) {

		if((abs(i)-2)){
			stack_1_copy.push(stack_1.top()*0.2);
		}
		stack_1.pop();
	}

	stack_1 = stack_1_copy;

	this->outputLabel_2->setText(showStack(stack_1));
//--------------------------------------------------------------------------------------------//

	while(!stack_1_copy.empty()){
		stack_1_copy.pop();
	}

	qDebug() << stack_1_copy.empty();

	std::stack<float, std::vector<float>> stack_2_copy = stack_2;
	for(size_t i = 0; i < stack_2.size(); i++) {
		stack_1_copy.push(stack_2_copy.top());
		stack_2_copy.pop();
	}

	for(size_t i = 0; i < stack_2.size(); i++) {
		stack_1.push(stack_1_copy.top());
		stack_1_copy.pop();
	}
	stack_1_copy = stack_1;
	sort_stack(stack_1);
	this->outputLabel_3->setText(showStack(stack_1));
//--------------------------------------------------------------------------------------------//

	std::stack<float, std::vector<float>> stack_1_copy2 = stack_1_copy;
	for(size_t i = 0; i < stack_1_copy.size(); i++) {
		stack_1.push(stack_1_copy.top());
		stack_1_copy.pop();
	}

	for(size_t i = 0; i < stack_1.size(); i++) {
		queue.push(stack_1.top());
		stack_1.pop();
	}

	this->outputLabel_4->setText(showQueue(queue));
//--------------------------------------------------------------------------------------------//

	stack_1 = stack_1_copy2;
	sort_stack2(stack_1);
	this->outputLabel_5->setText(showStack(stack_1));

//--------------------------------------------------------------------------------------------//

	while(!queue.empty()){
		vector.push_back(queue.front());
		queue.pop();
	}

	while(!stack_1.empty()){
		vector.push_back(stack_1.top());
		stack_1.pop();
	}

	int i = 0;
	for(std::vector<float>::iterator it = vector.begin(); it != vector.end(); ++it, ++i){
		if(i == 9) {this->outputLabel_6->setText(this->outputLabel_6->text() + ("\n"));}
		this->outputLabel_6->setText(this->outputLabel_6->text() + QString::number(*it) + "  ");
	}


	qDebug() << "Stack 1" << showStack(stack_1) << "\nStack 1 copy" << showStack(stack_1_copy) << "\nStack 1 copy2" << showStack(stack_1_copy2);

}

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	QGridLayout * layout = new QGridLayout;

	this->setFixedSize(600,600);
	this->setWindowIcon(QIcon("://img//Stack.png"));
	this->setWindowTitle("STL containers");
	this->setStyleSheet
			(
				"QPushButton{ background-color: #fff; border: 1px solid #dbdbdb; border-radius: .375em; color: #363636;"
					"font-family: Segoe UI; font-size: 1rem; height: 2.5em; line-height: 1.5; padding: calc(0.5em - 1px) 1em;"
					"position: relative; text-align: center; vertical-align: top; white-space: nowrap; }"

				"QPushButton::hover{ border-color: #5500ff; outline: 0;}"

				"QPushButton::pressed { border-color: #4a4a4a; outline: 0;}"
				);

	this->startButton = new QPushButton(QIcon("://img//Caret down.png"), "Start");

	this->taskResult_1 = new QLabel("Stack 1\nStack 2");
	this->outputLabel_1 = new QLabel;

	this->taskResult_2 = new QLabel("Stack 1\nchanged");
	this->outputLabel_2 = new QLabel;

	this->taskResult_3 = new QLabel("Stack 1+2\nsorted to lower");
	this->outputLabel_3 = new QLabel;

	this->taskResult_4 = new QLabel("Queue");
	this->outputLabel_4 = new QLabel;

	this->taskResult_5 = new QLabel("Stack\nsorted to large");
	this->outputLabel_5 = new QLabel;

	this->taskResult_6 = new QLabel("Stack + Queue\nIn vector");
	this->outputLabel_6 = new QLabel;

	layout->addWidget(this->taskResult_1, 0, 0);
	layout->addWidget(this->taskResult_2, 1, 0);
	layout->addWidget(this->taskResult_3, 2, 0);
	layout->addWidget(this->taskResult_4, 3, 0);
	layout->addWidget(this->taskResult_5, 4, 0);
	layout->addWidget(this->taskResult_6, 5, 0);

	layout->addWidget(this->outputLabel_1, 0, 1);
	layout->addWidget(this->outputLabel_2, 1, 1);
	layout->addWidget(this->outputLabel_3, 2, 1);
	layout->addWidget(this->outputLabel_4, 3, 1);
	layout->addWidget(this->outputLabel_5, 4, 1);
	layout->addWidget(this->outputLabel_6, 5, 1);

	layout->addWidget(this->startButton, 0, 2);

	connect(this->startButton, &QPushButton::clicked, this, &Widget::OnStart);

	setLayout(layout);
}
