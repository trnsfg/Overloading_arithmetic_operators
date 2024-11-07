#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int length;

    int StringLength(const char* str) const {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    void CopyString(char* dest, const char* src) const {
        strcpy_s(dest, length + 1, src);
    }

public:
    String() : data(nullptr), length(0) {}

    String(const char* str) {
        length = StringLength(str);
        data = new char[length + 1];
        CopyString(data, str);
    }

    String(const String& other) : length(other.length) {
        data = new char[length + 1];
        CopyString(data, other.data);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            CopyString(data, other.data);
        }
        return *this;
    }

    String operator+(const String& other) const {
        int newLength = length + other.length;
        char* newData = new char[newLength + 1];

        CopyString(newData, data);

        strcpy_s(newData + length, newLength + 1, other.data);

        String result;
        result.data = newData;
        result.length = newLength;
        return result;
    }

    int getLength() const {
        return length;
    }

    bool equals(const String& other) const {
        if (length != other.length) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    ~String() {
        delete[] data;
    }

    void print() const {
        if (data) {
            std::cout << data;
        }
    }
};

class Array {
private:
    int* data;
    int size;

public:
    Array() : data(nullptr), size(0) {}

    Array(int size) : size(size) {
        data = new int[size];
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Array operator+(const Array& other) const {
        int newSize = size + other.size;
        Array result(newSize);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i];
        }
        for (int i = 0; i < other.size; i++) {
            result.data[size + i] = other.data[i];
        }
        return result;
    }

    int& operator[](int index) {
        return data[index];
    }

    const int& operator[](int index) const {
        return data[index];
    }

    void InitRandomValues(int newSize) {
        delete[] data;
        size = newSize;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 21;
        }
    }

    void FillRandomValues() {
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 21;
        }
    }

    void FillWithCustomRandom() {
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 21;
        }
    }

    ~Array() {
        delete[] data;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
};

int customRandom() {
    return rand();
}

int main() {
    String str1("Hello ");
    String str2("World!");
    String str3 = str1 + str2;
    str3.print();

    Array arr1(5);
    arr1.FillRandomValues();
    arr1.print();

    Array arr2(3);
    arr2.FillRandomValues();
    arr2.print();

    Array arr3 = arr1 + arr2;
    arr3.print();

    arr3[2] = 100;
    arr3.print();

    return 0;
}
