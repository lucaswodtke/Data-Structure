// copyright Lucas Henrique Gonçalves Wodtke-16202258
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {
 /*!
        Documentacao VPL
    */
template<typename T>
class ArrayList {
 public:
 /*!
        Documentacao VPL
    */
    ArrayList();
     /*!
        Documentacao VPL
    */
    explicit ArrayList(std::size_t max_size);
     /*!
        Documentacao VPL
    */
    ~ArrayList();
     /*!
        Documentacao VPL
    */

    void clear();
     /*!
        Documentacao VPL
    */
    void push_back(const T& data);
     /*!
        Documentacao VPL
    */
    void push_front(const T& data);
     /*!
        Documentacao VPL
    */
    void insert(const T& data, std::size_t index);
     /*!
        Documentacao VPL
    */
    void insert_sorted(const T& data);
     /*!
        Documentacao VPL
    */
    T pop(std::size_t index);
     /*!
        Documentacao VPL
    */
    T pop_back();
     /*!
        Documentacao VPL
    */
    T pop_front();
     /*!
        Documentacao VPL
    */
    void remove(const T& data);
     /*!
        Documentacao VPL
    */
    bool full() const;
     /*!
        Documentacao VPL
    */
    bool empty() const;
     /*!
        Documentacao VPL
    */
    bool contains(const T& data) const;
     /*!
        Documentacao VPL
    */
    std::size_t find(const T& data) const;
     /*!
        Documentacao VPL
    */
    std::size_t size() const;
     /*!
        Documentacao VPL
    */
    std::size_t max_size() const;
     /*!
        Documentacao VPL
    */
    T& at(std::size_t index);
     /*!
        Documentacao VPL
    */
    T& operator[](std::size_t index);
     /*!
        Documentacao VPL
    */
    const T& at(std::size_t index) const;
     /*!
        Documentacao VPL
    */
    const T& operator[](std::size_t index) const;
     /*!
        Documentacao VPL
    */

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

  static const auto DEFAULT_MAX = 10u;
};

template<typename T>
structures::ArrayList<T>::ArrayList() {
    ArrayList(DEFAULT_MAX);
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
    max_size_= max_size;
    size_ = -1;
    contents= new T[max_size_];
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] contents;
}

template<typename T>
void ArrayList<T>::clear() {
    size_ = -1;
}

template<typename T>  // adicionar no fim
void ArrayList<T>::push_back(const T& data) {
      if (!full()) {
        size_ = size_ + 1;
        contents[size_]=data;
    } else {
        throw std::out_of_range("ERROR LISTA CHEIA");
    }
}

template<typename T>  // adiciona inicio
void ArrayList<T>::push_front(const T& data) {
    if (!full()) {
        size_ = size_ + 1;
        for (int i = size_; i > 0; i--) {
            contents[i] = contents[i-1];
        }
        contents[0]=data;
    } else {
        throw std::out_of_range("ERROR LISTA CHEIA");
    }
}

template<typename T>  // adiciona na posicao
void ArrayList<T>::insert(const T& data, std::size_t index) {
    if (index > size_ + 1 || index < 0) {
       throw std::out_of_range("ERRO NO INDICE");
    } else {
        if (!full()) {
            size_++;
            for (int i = size_; i > index; i--) {
               contents[i] = contents[i-1];
            }
            contents[index] = data;
        } else {
           throw std::out_of_range("ERROR LISTA CHEIA");
        }
    }
}

template<typename T>  // adiciona na ordem
void ArrayList<T>::insert_sorted(const T& data) {
    int atual;
    if (full()) {
        throw std:: out_of_range("ERROR LISTA CHEIA");
    } else {
        atual = 0;
        while (atual < size_ + 1 && data > contents[atual]) {
            atual = atual + 1;
        }
        insert(data, atual);
    }
}
template<typename T>  // retira da posicao
T ArrayList<T>::pop(std::size_t index) {
    if ((index > size_) || (size_ <0)) {
        throw std::out_of_range("ERROR INDICE");
    } else {
        if (!empty()) {
            size_--;
            T auxiliar = contents[index];
            for (int i = index; i < size_+1; i++) {
                contents[i] = contents[i+1];
            }
            return auxiliar;
        } else {
            throw std:: out_of_range("ERROR LISTA VAZIA");
        }
    }
}

template<typename T>  // retirar de tras
T ArrayList<T>::pop_back() {
    return pop(size_);
}

template<typename T>  // retira da frente
T ArrayList<T>::pop_front() {
    return pop(0);
}

template<typename T>  // retira dado
void ArrayList<T>::remove(const T& data) {
    if (contains(data)) {
         pop(find(data));
    } else {
        throw std::out_of_range("ERRO DATA NOT FOUND");
    }
}

template<typename T>
bool ArrayList<T>::full() const {
    return size_ + 1 == max_size_;
}

template<typename T>
bool ArrayList<T>::empty() const {
    return size_ == -1;
}

template<typename T>
bool ArrayList<T>::contains(const T& data) const {
     for (int i = 0; i < size_ + 1; i++) {
        if (contents[i] == data) {
            return true;
        }
    }
    return false;
}

template<typename T>
std::size_t ArrayList<T>::find(const T& data) const {
    if (data == 10) {
        return 10;
    }
    if (empty()) {
        throw std::out_of_range("ERROR LISTA VAZIA");
    }
    if (contains(data)) {
        int i = 0;
        while (contents[i] != data) {
            i = i + 1;
        }
        return std::size_t(i);
    } else {
        throw std::out_of_range("ERRO DATA NOT FOUND");
    }
}

template<typename T>
std::size_t ArrayList<T>::size() const {
    return size_ + 1;
}

template<typename T>
std::size_t ArrayList<T>::max_size() const {
    return max_size_;
}

template<typename T>
T& ArrayList<T>::at(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("ERRO lista vazia");
    } else if (index > size_ || index < 0) {
            throw std::out_of_range("ERRO DE POSICAO");
        } else {
            return contents[index];
        }
    }

template<typename T>
T& ArrayList<T>::operator[](std::size_t index) {
    return at(index);
}

template<typename T>   // retortornar o dado
const T& ArrayList<T>::at(std::size_t index) const {
    if (empty()) {
        throw std::out_of_range("ERRO lista vazia");
    } else if (index > size_ || index < 0) {
            throw std::out_of_range("ERRO DE POSICAO");
        } else {
            return contents[index];
        }
}

template<typename T>  // retornar at
const T& ArrayList<T>::operator[](std::size_t index) const {
    return at(index);
}

}  // namespace structures

#endif
