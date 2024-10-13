#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ProteinFood.h"
#include "food.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate() {
    try {
        // Проверка на пустые поля
        if (ui->caloriesInput->text().isEmpty() ||
            ui->weightInput->text().isEmpty() ||
            ui->proteinsInput->text().isEmpty()) {
            throw std::runtime_error("Все поля должны быть заполнены.");
        }

        // Преобразование ввода в числа
        double caloriesPer100g = ui->caloriesInput->text().toDouble();
        double weight = ui->weightInput->text().toDouble();
        double proteinsPer100g = ui->proteinsInput->text().toDouble();

        // Проверка на отрицательные значения
        if (caloriesPer100g < 0 || weight < 0 || proteinsPer100g < 0) {
            throw std::runtime_error("Значения не могут быть отрицательными.");
        }

        ProteinFood food(caloriesPer100g, weight, proteinsPer100g);

        double totalCalories = food.calculateCalories();
        double totalProteins = food.calculateProteins();

        ui->resultLabel->setText(QString("Общая калорийность: %1 ккал\nОбщее количество белков: %2 г")
                                         .arg(totalCalories)
                                         .arg(totalProteins));
    }
    catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Ошибка ввода", e.what());
    }
}