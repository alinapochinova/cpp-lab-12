#include <iostream>
#include <vector>
#include <deque>

// —оздаем класс обратного итератора
template <typename T>
class ReverseIterator {
public:
    //  онструктор принимает контейнер и текущий индекс
    ReverseIterator(T& container, int index) : container(container), index(index) {}

    // ѕереопределение оператора инкремента (++iterator)
    ReverseIterator<T>& operator++() {
        index--;
        return *this;
    }

    // ѕереопределение оператора декремента (--iterator)
    ReverseIterator<T>& operator--() {
        index++;
        return *this;
    }


    bool operator!=(const ReverseIterator& other) const {
        return index != other.index;
    }

    // ѕереопределение оператора разыменовани€ (*iterator)
    typename T::reference operator*() {
        return container[index-1];
    }

private:
    T& container; // —сылка на контейнер
    int index; // “екущий индекс
};

// ‘ункци€ дл€ создани€ обратного итератора
template <typename T>
ReverseIterator<T> make_reverse_iterator(T& container, int index) {
    return ReverseIterator<T>(container, index);
}

int main() {
    std::vector<int> myVector = { 1, 2, 3, 4, 5 };

    // —оздаем обратный итератор дл€ вектора
    ReverseIterator<std::vector<int>> reverseIterator = make_reverse_iterator(myVector, myVector.size());

    // ѕеребираем вектор в обратном пор€дке с использованием обратного итератора
    for (auto iter = reverseIterator; iter != make_reverse_iterator(myVector, 0); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    std::vector<double> myVector2 = { 1.5, 56.67, 23.54, 24.0, 5.7 };

    // —оздаем обратный итератор дл€ вектора
    ReverseIterator<std::vector<double>> reverseIterator2 = make_reverse_iterator(myVector2, myVector2.size());

    // ѕеребираем вектор в обратном пор€дке с использованием обратного итератора
    for (auto iter = reverseIterator2; iter != make_reverse_iterator(myVector2, 0); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    std::deque<int> myDeque = { 56, 32, 4, 47, 65, 39 };

    // —оздаем обратный итератор дл€ вектора
    ReverseIterator<std::deque<int>> reverseIterator3 = make_reverse_iterator(myDeque, myDeque.size());

    // ѕеребираем вектор в обратном пор€дке с использованием обратного итератора
    for (auto iter = reverseIterator3; iter != make_reverse_iterator(myDeque, 0); ++iter) {
        std::cout << *iter << " ";
    }

    return 0;
}