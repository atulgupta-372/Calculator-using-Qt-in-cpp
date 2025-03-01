#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_num0_clicked();
    void on_btn_num1_clicked();
    void on_btn_num2_clicked();
    void on_btn_num3_clicked();
    void on_btn_num4_clicked();
    void on_btn_num5_clicked();
    void on_btn_num6_clicked();
    void on_btn_num7_clicked();
    void on_btn_num8_clicked();
    void on_btn_num9_clicked();
    void on_btn_add_clicked();
    void on_btn_equal_clicked();
    void on_btn_clear_clicked();
    void on_btn_subtract_clicked();
    void on_btn_multiply_clicked();
    void on_btn_divide_clicked();

private:
    Ui::MainWindow *ui;
    QString currentInput;  // This stores the current input string
    bool isOperatorPressed;  // This flag prevents multiple consecutive operators

    double evaluateExpression(const QString &expression);
    int precedence(QChar op);
    void processOperator(QStack<double> &values, QStack<QChar> &operators);
};

#endif // MAINWINDOW_H
