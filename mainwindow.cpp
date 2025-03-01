#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentInput = "";
    isOperatorPressed = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_num0_clicked()
{
    currentInput += "0";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num1_clicked()
{
    currentInput += "1";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num2_clicked()
{
    currentInput += "2";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num3_clicked()
{
    currentInput += "3";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num4_clicked()
{
    currentInput += "4";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num5_clicked()
{
    currentInput += "5";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num6_clicked()
{
    currentInput += "6";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num7_clicked()
{
    currentInput += "7";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num8_clicked()
{
    currentInput += "8";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_num9_clicked()
{
    currentInput += "9";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_add_clicked()
{
    if (!currentInput.isEmpty()) {
        currentInput += "+";
        ui->display->setText(currentInput);
    }
}

void MainWindow::on_btn_equal_clicked()
{
    if (currentInput.isEmpty()) {
        return;
    }

    // Evaluate the expression (basic)
    double result = evaluateExpression(currentInput);

    if (result != -1) {
        ui->display->setText(QString::number(result));
        currentInput = QString::number(result);
    } else {
        ui->display->setText("Error");
    }
}

double MainWindow::evaluateExpression(const QString &expression)
{
    QStack<double> values;
    QStack<QChar> operators;

    int i = 0;
    QString numStr;

    while (i < expression.length()) {
        QChar currentChar = expression[i];

        if (currentChar.isDigit() || currentChar == '.') {
            numStr += currentChar;
            i++;
            while (i < expression.length() && (expression[i].isDigit() || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            values.push(numStr.toDouble());
            numStr.clear();
        }
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            while (!operators.isEmpty() && precedence(operators.top()) >= precedence(currentChar)) {
                processOperator(values, operators);
            }
            operators.push(currentChar);
            i++;
        }
        else {
            i++;
        }
    }

    while (!operators.isEmpty()) {
        processOperator(values, operators);
    }

    return values.isEmpty() ? 0 : values.pop();
}

int MainWindow::precedence(QChar op)
{
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

void MainWindow::processOperator(QStack<double> &values, QStack<QChar> &operators)
{
    if (values.size() < 2) {
        QMessageBox::critical(this, "Error", "Invalid expression!");
        return;
    }

    double operand2 = values.pop();
    double operand1 = values.pop();
    QChar op = operators.pop();

    double result = 0;
    if (op == '+') {
        result = operand1 + operand2;
    } else if (op == '-') {
        result = operand1 - operand2;
    } else if (op == '*') {
        result = operand1 * operand2;
    } else if (op == '/') {
        if (operand2 != 0) {
            result = operand1 / operand2;
        } else {
            QMessageBox::critical(this, "Error", "Division by zero!");
            return;
        }
    }
    values.push(result);
}

void MainWindow::on_btn_clear_clicked()
{
    currentInput.clear();
    ui->display->clear();
}

void MainWindow::on_btn_subtract_clicked()
{
    currentInput += "-";
    ui->display->setText(currentInput);
}

void MainWindow::on_btn_multiply_clicked()
{
    if (!currentInput.isEmpty()) {
        currentInput += "*";
        ui->display->setText(currentInput);
    }
}

void MainWindow::on_btn_divide_clicked()
{
    if (!currentInput.isEmpty()) {
        currentInput += "/";
        ui->display->setText(currentInput);
    }
}
