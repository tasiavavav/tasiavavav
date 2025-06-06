// Задание 1: Инвертировать максимальные элементы в строках
    invertMaxInRows(workingArray, m, n);
    cout << "После инверсии максимальных элементов в строках:" << endl;
    printArray(workingArray, m, n);

    // Задание 2: Вставить нулевые столбцы после столбцов с максимальным элементом
    size_t newColumns = getNumberColumns(workingArray, m, n);
    int** newArray = createArray(m, n + newColumns);
    insertZeroColumns(newArray, m, n + newColumns, n, workingArray);
    cout << "После вставки нулевых столбцов:" << endl;
    printArray(newArray, m, n + newColumns);

    // Освобождаем память
    deleteArray(originalArray, m, n);
    deleteArray(workingArray, m, n);
    deleteArray(newArray, m, n + newColumns);

    return 0;
}

int getValue()
{
    int value = 0;
    if (!(cin >> value)) {
        cerr << "Ошибка ввода! Программа завершена." << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    int n = getValue();
    checkN(n);
    return static_cast<size_t>(n);
}

void checkN(const int n)
{
    if (n <= 0) {
        cerr << "Ошибка: Размер должен быть положительным!" << endl;
        abort();
    }
}

int** createArray(const size_t rows, const size_t cols)
{
    int** array = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    return array;
}

void printArray(int** array, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << "Введите элемент [" << i << "][" << j << "]: ";
            array[i][j] = getValue();
        }
    }
}

size_t getMaxIndexInRow(int* row, const size_t n)
{
    size_t maxIndex = 0;
    for (size_t i = 1; i < n; i++) {
        if (row[i] > row[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void invertMaxInRows(int** array, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++) {
        size_t maxIndex = getMaxIndexInRow(array[i], cols);
        array[i][maxIndex] = -array[i][maxIndex];
    }
}

int findMaxElement(int** array, const size_t rows, const size_t cols)
{
    int maxElement = array[0][0];
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (array[i][j] > maxElement) {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}

bool hasMaxElement(int** array, const size_t rows, size_t col, int maxElement)
{
    for (size_t i = 0; i < rows; i++) {
        if (array[i][col] == maxElement) {
            return true;
        }
    }
    return false;
}

size_t getNumberColumns(int** array, const size_t rows, const size_t cols)
{
    int maxElement = findMaxElement(array, rows, cols);
    size_t count = 0;

    for (size_t j = 0; j < cols; j++) {
        if (hasMaxElement(array, rows, j, maxElement)) {
            count++;
        }
    }
    return count;
}

void insertZeroColumns(int newArray, const size_t rows, const size_t newCols, const size_t cols, int originalArray)
{
    int maxElement = findMaxElement(originalArray, rows, cols);
    size_t newCol = 0;

    for (size_t j = 0; j < cols; j++) {
        // Копируем оригинальный столбец
        for (size_t i = 0; i < rows; i++) {
            newArray[i][newCol] = originalArray[i][j];
        }
        newCol++;

        // Добавляем нулевой столбец если нужно
        if (hasMaxElement(originalArray, rows, j, maxElement)) {
            for(size_t i = 0; i < rows; i++) {
                newArray[i][newCol] = 0;
            }
            newCol++;
        }
    }
}

void deleteArray(int** array, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}
int copyArray(int array, const size_t rows, const size_t cols)
{
    int** newArray = createArray(rows, cols);
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            newArray[i][j] = array[i][j];
        }
    }
    return newArray;
}
