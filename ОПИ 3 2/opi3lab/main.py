import sys
from random import randint, uniform
from PyQt5.QtWidgets import QApplication, QLineEdit, QSplitter, QListWidget, QComboBox, QWidget, QVBoxLayout, \
    QPushButton, QLabel, QHBoxLayout, QMessageBox, QScrollArea, QTextEdit
from vector import Vector
from list import List
import time
import tabulate
from math import sin, cos

import g4f

class MainWindow(QWidget):
    def __init__(self, tests=False):
        super().__init__()

        self.initUI()
        self.mass = None

        #self._run_tests()

    def initUI(self):
        layout = QVBoxLayout()
        right_l = QHBoxLayout()

        self.data_type_label = QLabel("Тип данных")
        self.data_type_combo = QComboBox()
        self.data_type_combo.addItem("Int")
        self.data_type_combo.addItem("Float")
        self.data_type_combo.addItem("Double")
        layout.addWidget(self.data_type_label)
        layout.addWidget(self.data_type_combo)

        self.array_type_label = QLabel("Тип массива")
        self.array_type_combo = QComboBox()
        self.array_type_combo.addItem("Vector")
        self.array_type_combo.addItem("List")
        self.array_type_combo.addItem("For")
        layout.addWidget(self.array_type_label)
        layout.addWidget(self.array_type_combo)


        self.array_size_label = QLabel("Размер массива случайных чисел")
        self.array_size_input = QLineEdit()
        layout.addWidget(self.array_size_label)
        layout.addWidget(self.array_size_input)

        self.range_label = QLabel("Диапазон генерации случайных чисел")
        self.range_min_input = QLineEdit()
        layout.addWidget(self.range_label)
        layout.addWidget(self.range_min_input)
        self.range_max_input = QLineEdit()
        layout.addWidget(self.range_max_input)

        self.generate_button = QPushButton("Сгенерировать")
        layout.addWidget(self.generate_button)

        self.result_display = QTextEdit()
        self.result_display.setFixedHeight(200)
        layout.addWidget(self.result_display)

        self.operation_label = QLabel("Операция")
        layout.addWidget(self.operation_label)

        self.operation_combo = QComboBox()
        self.operation_combo.addItem("Plus")
        self.operation_combo.addItem("Minus")
        self.operation_combo.addItem("Mult")
        self.operation_combo.addItem("Div")
        self.operation_combo.addItem("Sin")
        self.operation_combo.addItem("Cos")
        layout.addWidget(self.operation_combo)

        self.test_button = QPushButton("Тестировать")
        layout.addWidget(self.test_button)

        self.result_display_scroll = QScrollArea()
        self.result_display_scroll.setWidgetResizable(True)
        self.result_display_scroll.setFixedHeight(200)
        self.scroll_contents = QListWidget()
        self.result_display_scroll.setWidget(self.scroll_contents)
        layout.addWidget(self.result_display_scroll)


        self.gpt_text = QLabel("Hello!")
        self.gpt_input = QLineEdit("Hi!")
        self.gptbutton = QPushButton("Отправить")
        self.gptbutton.clicked.connect(self.gpt_on_send)

        layout2 = QVBoxLayout()
        layout2.addWidget(self.gpt_text)
        layout2.addWidget(self.gptbutton)
        layout2.addWidget(self.gpt_input)

        right_l.addLayout(layout)
        right_l.addLayout(layout2)
        self.setLayout(right_l)

        self.generate_button.clicked.connect(self.on_generate_button_click)
        self.test_button.clicked.connect(self.on_test_button_click)

        self.setWindowTitle("Тестер")
        self.setGeometry(0, 0, 1500,800)

    def gpt_on_send(self):
        val = self.gpt_input.text()

        response = g4f.ChatCompletion.create(
            model="gpt-3.5-turbo",
            messages=[{"role": "user", "content": val}],
            stream=True,
        )

        res = ""
        for i, message in enumerate(response):
            res += message

        formatted_text = ""
        for i, ch in enumerate(res):
            formatted_text += ch
            if i % 50 == 0:
                formatted_text += '\n'


        self.gpt_text.setText(formatted_text)

    def on_generate_button_click(self):
        data_type = self.data_type_combo.currentText()
        array_type = self.array_type_combo.currentText()
        array_size = int(self.array_size_input.text())
        range_minf = float(self.range_min_input.text())
        range_maxf = float(self.range_max_input.text())

        start_time = time.time()
        display_text = ""
        self.for_flag = False

        if array_type == "Vector":
            self.mass = Vector()
            self.for_flag = False
        elif array_type == "List":
            self.mass = List()
            self.for_flag = False
        elif array_type == "For":
            self.mass = []
            display_text = "Генерация в цикле включена"
            self.for_flag = True


        if not self.for_flag:
            for i in range(array_size):
                if data_type == "Int":
                    num = randint(range_minf, range_maxf)
                elif data_type == "Float":
                    num = uniform(range_minf, range_maxf)
                elif data_type == "Double":
                    num = uniform(range_minf, range_maxf)
                self.mass.append(num)
                if i < 100 or i > array_size - 100:
                    display_text += f"{i}: {num}\n"

        end_time = time.time()
        execution_time = end_time - start_time
        self.result_display.setText(display_text)
        self.scroll_contents.addItem(f"Время генерации: {execution_time} сек;")

    def on_test_button_click(self):
        data_type = self.data_type_combo.currentText()
        operation = self.operation_combo.currentText()
        array_size = int(self.array_size_input.text())
        range_minf = float(self.range_min_input.text())
        range_maxf = float(self.range_max_input.text())
        result = 1

        start_time = time.time()
        if not self.for_flag:
            for e in self.mass:
                if operation == "Plus":
                    result += e
                elif operation == "Minus":
                    result -= e
                elif operation == "Mult":
                    if e == 0:
                        e = 1
                    result *= e
                elif operation == "Div":
                    if e == 0:
                        e = 1
                    result /= e
                elif operation == "Sin":
                    result += sin(e)
                elif operation == "Cos":
                    result += cos(e)
        else:
            for _ in range(array_size):
                e = 0
                if data_type == "Int":
                    e = randint(range_minf, range_maxf)
                elif data_type == "Float":
                    e = uniform(range_minf, range_maxf)
                elif data_type == "Double":
                    e = uniform(range_minf, range_maxf)

                if operation == "Plus":
                    result += e
                elif operation == "Minus":
                    result -= e
                elif operation == "Mult":
                    if e == 0:
                        e = 1
                    result *= e
                elif operation == "Div":
                    if e == 0:
                        e = 1
                    result /= e
                elif operation == "Sin":
                    result += sin(e)
                elif operation == "Cos":
                    result += cos(e)
        end_time = time.time()
        execution_time = end_time - start_time

        self.scroll_contents.addItem(f"Время выполнения: {execution_time} сек; Результат: {result};")

    def _run_tests(self):
        # тест на коллизию с границами диапазона
        min_val = -0.9
        max_val = 0.9

        self.array_type_combo.setCurrentText("Vector")
        self.data_type_combo.setCurrentText("Float")
        self.array_size_input.setText("30000")
        self.range_min_input.setText(str(min_val))
        self.range_max_input.setText(str(max_val))

        self.on_generate_button_click()

        error = False
        for e in self.mass:
            if e > min_val or e < max_val:
                error = True
        if error:
            self.scroll_contents.addItem("Тест на коллизию пройдет")
        else:
            self.scroll_contents.addItem("Тест на коллизию не пройдет")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow(True)
    window.show()
    sys.exit(app.exec_())