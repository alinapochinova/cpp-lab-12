#include <iostream>
#include <vector>

// Создаем класс обратного итератора
template <typename T>
class ReverseIterator {
public:
    // Конструктор принимает контейнер и текущий индекс
    ReverseIterator(T& container, int index) : container(container), index(index) {}

    // Переопределение оператора инкремента (++iterator)
    ReverseIterator<T>& operator++() {
        index--;
        return *this;
    }

    // Переопределение оператора декремента (--iterator)
    ReverseIterator<T>& operator--() {
        index++;
        return *this;
    }


    bool operator!=(const ReverseIterator& other) const {
        return index != other.index;
    }

    // Переопределение оператора разыменования (*iterator)
    typename T::reference operator*() {
        return container[index-1];
    }

private:
    T& container; // Ссылка на контейнер
    int index; // Текущий индекс
};

// Функция для создания обратного итератора
template <typename T>
ReverseIterator<T> make_reverse_iterator(T& container, int index) {
    return ReverseIterator<T>(container, index);
}

int main() {
    std::vector<int> myVector = { 1, 2, 3, 4, 5 };

    // Создаем обратный итератор для вектора
    ReverseIterator<std::vector<int>> reverseIterator = make_reverse_iterator(myVector, myVector.size());

    // Перебираем вектор в обратном порядке с использованием обратного итератора
    for (auto iter = reverseIterator; iter != make_reverse_iterator(myVector, 0); ++iter) {
        std::cout << *iter << " ";
    }


    return 0;
}