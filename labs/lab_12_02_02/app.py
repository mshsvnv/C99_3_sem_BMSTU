from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QMessageBox, QDialog
import funcs
class Ui_main_window(QDialog):
    def setupUi(self, main_window):
        main_window.setObjectName("main_window")
        main_window.resize(800, 700)
        main_window.setCursor(QtGui.QCursor(QtCore.Qt.WaitCursor))
        self.centralwidget = QtWidgets.QWidget(main_window)
        self.centralwidget.setObjectName("centralwidget")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setGeometry(QtCore.QRect(0, 0, 800, 700))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tabWidget.sizePolicy().hasHeightForWidth())
        self.tabWidget.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(17)
        self.tabWidget.setFont(font)
        self.tabWidget.setStyleSheet("background-color: (1, 2, 3)")
        self.tabWidget.setObjectName("tabWidget")
        self.tab_fib = QtWidgets.QWidget()
        self.tab_fib.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.tab_fib.setObjectName("tab_fib")
        self.label_task = QtWidgets.QLabel(self.tab_fib)
        self.label_task.setGeometry(QtCore.QRect(120, 60, 580, 50))
        self.label_task.setObjectName("label_task")
        self.btn_res_1 = QtWidgets.QPushButton(self.tab_fib)
        self.btn_res_1.setGeometry(QtCore.QRect(360, 290, 101, 31))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.btn_res_1.setFont(font)
        self.btn_res_1.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.btn_res_1.setObjectName("btn_res_1")
        self.label_enter = QtWidgets.QLabel(self.tab_fib)
        self.label_enter.setGeometry(QtCore.QRect(120, 200, 310, 50))
        font = QtGui.QFont()
        font.setPointSize(17)
        self.label_enter.setFont(font)
        self.label_enter.setObjectName("label_enter")
        self.enter_amount = QtWidgets.QPlainTextEdit(self.tab_fib)
        self.enter_amount.setGeometry(QtCore.QRect(430, 200, 241, 50))
        self.enter_amount.setStyleSheet("border: 1px solid silver;")
        self.enter_amount.setObjectName("enter_amount")
        self.enter_amount_2 = QtWidgets.QPlainTextEdit(self.tab_fib)
        self.enter_amount_2.setGeometry(QtCore.QRect(120, 350, 560, 220))
        self.enter_amount_2.setStyleSheet("border: 1px solid silver;")
        self.enter_amount_2.setObjectName("enter_amount_2")
        self.tabWidget.addTab(self.tab_fib, "")
        self.tab_filter = QtWidgets.QWidget()
        self.tab_filter.setObjectName("tab_filter")
        self.label_task_2 = QtWidgets.QLabel(self.tab_filter)
        self.label_task_2.setGeometry(QtCore.QRect(30, 60, 741, 51))
        font = QtGui.QFont()
        font.setPointSize(17)
        self.label_task_2.setFont(font)
        self.label_task_2.setObjectName("label_task_2")
        self.btn_res_2 = QtWidgets.QPushButton(self.tab_filter)
        self.btn_res_2.setGeometry(QtCore.QRect(360, 400, 101, 31))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.btn_res_2.setFont(font)
        self.btn_res_2.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.btn_res_2.setObjectName("btn_res_2")
        self.label_enter_2 = QtWidgets.QLabel(self.tab_filter)
        self.label_enter_2.setGeometry(QtCore.QRect(30, 130, 391, 51))
        font = QtGui.QFont()
        font.setPointSize(17)
        self.label_enter_2.setFont(font)
        self.label_enter_2.setObjectName("label_enter_2")
        self.btn_without_stock = QtWidgets.QRadioButton(self.tab_filter)
        self.btn_without_stock.setGeometry(QtCore.QRect(310, 340, 191, 26))
        font = QtGui.QFont()
        font.setPointSize(17)

        self.btn_without_stock.setFont(font)
        self.btn_without_stock.setObjectName("btn_without_stock")

        # self.btn_without_stock.toggled.connect(self.radio_btn)

        self.labe_mem = QtWidgets.QLabel(self.tab_filter)
        self.labe_mem.setGeometry(QtCore.QRect(30, 337, 281, 31))
        font = QtGui.QFont()
        font.setPointSize(17)
        self.labe_mem.setFont(font)
        self.labe_mem.setObjectName("labe_mem")
        self.btn_with_stock = QtWidgets.QRadioButton(self.tab_filter)
        self.btn_with_stock.setGeometry(QtCore.QRect(520, 340, 123, 26))
        font = QtGui.QFont()
        font.setPointSize(17)
        self.btn_with_stock.setFont(font)
        self.btn_with_stock.setObjectName("btn_with_stock")

        # self.btn_with_stock.toggled.connect(self.radio_btn)

        self.enter_array = QtWidgets.QPlainTextEdit(self.tab_filter)
        self.enter_array.setGeometry(QtCore.QRect(30, 200, 730, 100))
        self.enter_array.setStyleSheet("border: 1px solid silver;")
        self.enter_array.setPlainText("")
        self.enter_array.setObjectName("enter_array")
        self.result_2 = QtWidgets.QPlainTextEdit(self.tab_filter)
        self.result_2.setGeometry(QtCore.QRect(30, 460, 730, 100))
        self.result_2.setStyleSheet("border: 1px solid silver;")
        self.result_2.setPlainText("")
        self.result_2.setObjectName("result_2")
        self.tabWidget.addTab(self.tab_filter, "")
        main_window.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(main_window)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 25))
        self.menubar.setObjectName("menubar")
        main_window.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(main_window)
        self.statusbar.setObjectName("statusbar")
        main_window.setStatusBar(self.statusbar)

        self.retranslateUi(main_window)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(main_window)

        self.add_action()

    def retranslateUi(self, main_window):
        _translate = QtCore.QCoreApplication.translate
        main_window.setWindowTitle(_translate("main_window", "2 Задание"))
        self.label_task.setText(_translate("main_window", "Условие: заполнение массива числами Фибоначчи"))
        self.btn_res_1.setText(_translate("main_window", "Результат"))
        self.label_enter.setText(_translate("main_window", "Введите количество чисел:"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_fib), _translate("main_window", "Задача №1"))
        self.label_task_2.setText(_translate("main_window", "Условие: убрать дубликаты из старого массива и записать в новый"))
        self.btn_res_2.setText(_translate("main_window", "Результат"))
        self.label_enter_2.setText(_translate("main_window", "Введите числа исходного массива:"))
        self.btn_without_stock.setText(_translate("main_window", "точный размер"))
        self.labe_mem.setText(_translate("main_window", "Тип выделения памяти:"))
        self.btn_with_stock.setText(_translate("main_window", "с запасом"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_filter), _translate("main_window", "Задача №2"))

    def add_action(self):
        self.btn_res_1.clicked.connect(lambda: self.write_res_1(self.enter_amount.toPlainText()))
        self.btn_res_2.clicked.connect(lambda: self.write_res_2(self.enter_array.toPlainText()))

    def write_res_1(self, text):

        try:
            n = int(text)

            if (n > 0  and n <= 45):
            
                arr = funcs.fill_fib(n)

                string = " ".join(map(str, arr))
                self.enter_amount_2.setPlainText(string)
            else:
                self.enter_amount_2.clear()

                self.error()
        except:
            self.enter_amount_2.clear()
            
            self.error()

    def write_res_2(self, text):

        try:
            nums = list(map(int, text.split(" ")))

            if (self.btn_with_stock.isChecked()):
                arr = funcs.filter_with_stock(nums)

                string = " ".join(map(str, arr))
                self.result_2.setPlainText(string)

            elif (self.btn_without_stock.isChecked()):
                arr = funcs.filter_without_stock(nums)

                string = " ".join(map(str, arr))
                self.result_2.setPlainText(string)

            else:
                self.result_2.clear()
            
                self.error()
            
        except:
            self.result_2.clear()
            
            self.error()

    def error(self):

        error = QMessageBox()
        error.setWindowTitle("Ошибка")
        error.setText("Некорректное значение!")
        error.setIcon(QMessageBox.Icon.Warning)
        error.setStandardButtons(QMessageBox.Ok)

        error.exec_()


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    main_window = QtWidgets.QMainWindow()
    ui = Ui_main_window()
    ui.setupUi(main_window)
    main_window.show()
    sys.exit(app.exec_())
