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
class ArrayStack {
 public:
    /*!
        Documentacao VPL
    */
    ArrayStack();
    /*!
       Construtor da Pilha com tamanho especificado
       param_max tamanho maximo permitido da pilha
    */
    explicit ArrayStack(std::size_t max);
    /*!
        Deletar
    */
    ~ArrayStack();
 /*!
        Documentacao VPL
    */
    void push(const T& data);  // empilha
 /*!
        Documentacao VPL
    */
    T pop();  // desempilha
 /*!
        Documentacao VPL
    */
    T& top();
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
};  // Fim ArrayStack.

template<typename T>
ArrayStack<T>::ArrayStack() {
    max_size_ = DEFAULT_SIZE;
    top_ = -1;
    contents = new T[max_size_];
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] contents;
}

template<typename T>
ArrayStack<T>::ArrayStack(std::size_t max) {
    max_size_= max;
    top_= -1;
    contents= new T[max_size_];
}

template<typename T>
void ArrayStack<T>::push(const T& data) {
    if (!full()) {
        contents[++top_]=data;
    } else {
        throw std::out_of_range("ERROR PILHA CHEIA");
    }
}

template<typename T>
T ArrayStack<T>::pop() {
    if (!empty()) {
        top_--;
        return contents[top_+1];
    } else {
        throw std::out_of_range("ERROR PILHA VAZIA");
    }
}

template<typename T>
T& ArrayStack<T>::top() {
    if (!empty()) {
        return contents[top_];
    } else {
        throw std::out_of_range("ERROR PILHA VAZIA");
    }
}

template<typename T>
void ArrayStack<T>::clear() {
    top_ = -1;
}

template<typename T>
std::size_t ArrayStack<T>::size() {
    return top_ + 1;
}

template<typename T>
std::size_t ArrayStack<T>::max_size() {
    return max_size_;
}

template<typename T>
bool ArrayStack<T>::empty() {
    return top_ == -1;
}

template<typename T>
bool ArrayStack<T>::full() {
    return top_ == max_size_-1;
}


}  // namespace structures

#endif
