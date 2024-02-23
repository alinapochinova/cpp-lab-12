#include <iostream>
#include <vector>

// ������� ����� ��������� ���������
template <typename T>
class ReverseIterator {
public:
    // ����������� ��������� ��������� � ������� ������
    ReverseIterator(T& container, int index) : container(container), index(index) {}

    // ��������������� ��������� ���������� (++iterator)
    ReverseIterator<T>& operator++() {
        index--;
        return *this;
    }

    // ��������������� ��������� ���������� (--iterator)
    ReverseIterator<T>& operator--() {
        index++;
        return *this;
    }


    bool operator!=(const ReverseIterator& other) const {
        return index != other.index;
    }

    // ��������������� ��������� ������������� (*iterator)
    typename T::reference operator*() {
        return container[index-1];
    }

private:
    T& container; // ������ �� ���������
    int index; // ������� ������
};

// ������� ��� �������� ��������� ���������
template <typename T>
ReverseIterator<T> make_reverse_iterator(T& container, int index) {
    return ReverseIterator<T>(container, index);
}

int main() {
    std::vector<int> myVector = { 1, 2, 3, 4, 5 };

    // ������� �������� �������� ��� �������
    ReverseIterator<std::vector<int>> reverseIterator = make_reverse_iterator(myVector, myVector.size());

    // ���������� ������ � �������� ������� � �������������� ��������� ���������
    for (auto iter = reverseIterator; iter != make_reverse_iterator(myVector, 0); ++iter) {
        std::cout << *iter << " ";
    }


    return 0;
}