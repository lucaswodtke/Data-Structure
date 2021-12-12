// copyright Lucas Henrique Gonçalves Wodtke-16202258
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {
template<typename T>
 /*!
        Documentacao VPL
    */
class ArrayQueue {
 public:
    /*!
        Documentacao VPL
    */
    ArrayQueue();
    /*!
       Construtor da fila com tamanho especificado
       param_max tamanho maximo permitido da fila
    */
    explicit ArrayQueue(std::size_t max);
    /*!
        Deletar
    */
    ~ArrayQueue();
 /*!
        Documentacao VPL
    */
    void enqueue(const T& data);  // insere
 /*!
        Documentacao VPL
    */
    T dequeue();  // retira
 /*!
        Documentacao VPL
    */
    T& back();
 /*!
        Documentacao VPL
    */
    void clear();  // limpa
 /*!
       Documentacao VPL
    */
    std::size_t size();  // tamanho
 /*!
        Documentacao VPL
    */
    std::size_t max_size();
 /*!
        Documentacao VPL
    */
    bool empty();  // vazia
 /*!
        Documentacao VPL
    */
    bool full();  // cheia

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};  // Fim ArrayQueue.

template<typename T>
ArrayQueue<T>::ArrayQueue() {
    max_size_ = DEFAULT_SIZE;
    top_ = -1;
    contents = new T[max_size_];
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] contents;
}

template<typename T>
ArrayQueue<T>::ArrayQueue(std::size_t max) {
    max_size_= max;
    top_= -1;
    contents= new T[max_size_];
}

template<typename T>
void ArrayQueue<T>::enqueue(const T& data) {
    if (!full()) {
        contents[++top_]=data;
    } else {
        throw std::out_of_range("ERROR FILA CHEIA");
    }
}

template<typename T>
T ArrayQueue<T>::dequeue() {
    if (!empty()) {
        int auxiliar = contents[0];
			for (int i = 0; i < top_; i++)
				contents[i] = contents[i+1];
			top_--;
        return auxiliar;
    } else {
        throw std::out_of_range("ERROR FILA VAZIA");
    }
}

template<typename T>
T& ArrayQueue<T>::back() {
    if (!empty()) {
        return contents[top_];
    } else {
        throw std::out_of_range("ERROR FILA VAZIA");
    }
}

template<typename T>
void ArrayQueue<T>::clear() {
    top_ = -1;
}

template<typename T>
std::size_t ArrayQueue<T>::size() {
    return top_ + 1;
}

template<typename T>
std::size_t ArrayQueue<T>::max_size() {
    return max_size_;
}

template<typename T>
bool ArrayQueue<T>::empty() {
    return top_ == -1;
}

template<typename T>
bool ArrayQueue<T>::full() {
    return top_ == max_size_-1;
}


}  // namespace structures

#endif
