import sys
import subprocess
from PyQt5.QtWidgets import QApplication, QLineEdit, QSplitter, QListWidget, QComboBox, QWidget, QVBoxLayout, \
    QPushButton, QLabel, QHBoxLayout, QMessageBox


class MainWindow(QWidget):
    """Основной класс оконного приложения"""
    def __init__(self):
        super().__init__()
        self.create_ui()

    def create_ui(self):
        """Создание, настройка и фороматирование виджетов окнаы"""

        # Верхний левый блок настроек
        self.label_1 = QLabel("Тип данных")
        self.select_box_1 = QComboBox()
        self.select_box_1.addItems(["Int", "Float", "Double"])

        self.label_2 = QLabel("Тип массива")
        self.select_box_2 = QComboBox()
        self.select_box_2.addItems(["Dyn array", "List", "For cycle"])

        self.label_3 = QLabel("Тип операции")
        self.select_box_3 = QComboBox()
        self.select_box_3.addItems(["Minus", "Plus", "Mult", "Div", "Sin", "Cos"])

        lv_box = QVBoxLayout()
        lv_box.addWidget(self.label_1)
        lv_box.addWidget(self.select_box_1)

        lv_box.addWidget(self.label_2)
        lv_box.addWidget(self.select_box_2)

        lv_box.addWidget(self.label_3)
        lv_box.addWidget(self.select_box_3)

        # Верхний правый блок настроек
        self.label_4 = QLabel("Размер массива случайных чисел")
        self.text_input_1 = QLineEdit()
        self.text_input_1.setText("300000000")
        self.label_5 = QLabel("Диапазон случайных чисел")

        t_range = QHBoxLayout()
        self.text_input_2 = QLineEdit()
        self.text_input_2.setText("0")
        self.text_input_3 = QLineEdit()
        self.text_input_3.setText("10")
        t_range.addWidget(self.text_input_2)
        t_range.addWidget(self.text_input_3)

        rv_box = QVBoxLayout()
        rv_box.addWidget(self.label_4)
        rv_box.addWidget(self.text_input_1)

        rv_box.addWidget(self.label_5)
        rv_box.addLayout(t_range)


        # Верхний блок настроек
        upper_box = QHBoxLayout()
        upper_box.addLayout(lv_box)
        upper_box.addLayout(rv_box)

        # Нижний блок результатов
        self.button = QPushButton("Начать тестирование")
        self.button.clicked.connect(self.start_testing_clicked)
        self.scrollable_list = QListWidget()

        down_box = QVBoxLayout()
        down_box.addWidget(QSplitter())
        down_box.addWidget(self.button)
        down_box.addWidget(self.scrollable_list)

        # Собираем весь Layout
        layout = QVBoxLayout()
        layout.addLayout(upper_box)
        layout.addLayout(down_box)

        self.setLayout(layout)

        self.setGeometry(100, 100, 800, 600)
        self.setWindowTitle("Тестер")

    def start_testing_clicked(self):
        """on_click event, собираем данные с форм, запускаем тестирование, отображаем результат"""

        try:
            # Получаем данные с формы
            data_type = self.select_box_1.currentText()
            array_type = self.select_box_2.currentText()
            op_type = self.select_box_3.currentText()

            array_size = self.text_input_1.text()
            min_rand_range = self.text_input_2.text()
            max_rand_range = self.text_input_3.text()

            # Запускаем impl приложение (запускаем расчеты)
            process = subprocess.run(['opi_biglab_impl.exe', data_type, array_type, op_type, array_size, min_rand_range,
                                      max_rand_range], capture_output=True, text=True)
            return_code = process.returncode
            if return_code != 0:
                raise Exception

            # Читаем результат и отображаем
            with open('results.bin', 'r') as file:
                time = file.readline()
                summ = file.readline()
                numbers = list(map(str, file.readline().split()))

            formatted_text = f"Результаты тестирование\nВремя (мс): {time}\nСумма: {summ}\n"

            self.scrollable_list.clear()
            self.scrollable_list.addItems(numbers)

            msg_box = QMessageBox()
            msg_box.setIcon(QMessageBox.Information)
            msg_box.setText(formatted_text)
            msg_box.setWindowTitle("Результаты")
            msg_box.setStandardButtons(QMessageBox.Ok)

            result = msg_box.exec_()

        except Exception:
            msg = QMessageBox()
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Что-то пошло не так")
            msg.setWindowTitle("Ошибка")
            msg.exec_()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())