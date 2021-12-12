// ©copyright Lucas Henrique Gonçalves Wodtke-16202258

#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
/*!
        Documentacao VPL
    */
class DoublyLinkedList {
 public:
    DoublyLinkedList() {
        size_ = 0;
        head = nullptr;
    }
    ~DoublyLinkedList() {
        clear();
    }
    /*!
        Documentacao VPL
    */
    void clear() {
        Node *primeiro_node = head;
		while (primeiro_node != nullptr) {
			primeiro_node = primeiro_node->next();
			pop_front();
		}
		size_ = 0;
    }
/*!
        Documentacao VPL
    */
    void push_back(const T& data) {
        insert(data, size_);
    }  // insere no fim
    /*!
        Documentacao VPL
    */
    void push_front(const T& data) {
        Node *new_ = new Node(data, nullptr, head);
	    head = new_;
	 if (new_->next() != nullptr) {
		new_->next()->prev(new_);
	 }
		++size_;
    }  // insere no início
    /*!
        Documentacao VPL
    */
    void insert(const T& data, std::size_t index) {
        if (index > size_ || index < 0) {
			throw std::out_of_range("ERROR POSICAO INVALIDA");
		}
		if(index == 0) {
			push_front(data);
		} else {
			Node *it = head;
			Node *new_ = new Node(data, nullptr, nullptr);
			for(int i = 0; i < (index-1); i++) {
				it = it->next();
			}
			new_->next(it->next());
			if(it->next() != nullptr) {
				it->next()->prev(new_);
			}
			new_->prev(it);
			it->next(new_);
			++size_;
		}
    }  // insere na posição
    /*!
        Documentacao VPL
    */
    void insert_sorted(const T& data) {
        if (empty()) {
			push_front(data);
		} else {
			Node *auxiliar = head;
			int posicao = 0;
			while(auxiliar != nullptr && data > (auxiliar->data())) {
				auxiliar = auxiliar->next();
				posicao = posicao + 1;
			}
			insert(data, posicao);
		}
    }  // insere em ordem
/*!
        Documentacao VPL
    */
    T pop(std::size_t index) {
          if (empty()) {
			throw std::out_of_range("ERRO LISTA VAZIA");
		}
		if(index > size_-1 || index < 0) {
			throw std::out_of_range("ERROR POSICAO INVALIDA");
		} else {
			if(index == 0) {
				return pop_front();
			} else {
				Node *anterior = head;
				Node *delete_;
				for(int i = 0; i < (index-1); i++) {
					anterior = anterior->next();
				}
				delete_ = anterior->next();
				T volta = delete_->data();
				anterior->next(delete_->next());
				delete delete_;
				size_ = size_ -1;
				return volta;
			}
		}
    }  // retira da posição
    /*!
        Documentacao VPL
    */
    T pop_back() {
        return pop(size_-1);
    }   // retira do fim
    /*!
        Documentacao VPL
    */
    T pop_front() {
        if (empty()) {
			throw std::out_of_range("ERROR LISTA VAZIA");
		} else {
			Node *auxiliar = head;
			T back = auxiliar->data();
			head = auxiliar->next();
			delete auxiliar;
			size_ = size_ -1;
			return back;
		}
    }  // retira do início
    /*!
        Documentacao VPL
    */
    void remove(const T& data) {
        pop(find(data));
    }  // retira específico
/*!
        Documentacao VPL
    */
    bool empty() const {
        return size_ == 0;
    }  // lista vazia
    /*!
        Documentacao VPL
    */
    bool contains(const T& data) const {
        if (empty()) {
			return false;
		} else {
			Node *auxiliar = head;
			for(int i = 0; i < size_; i++) {
				if(data == (auxiliar->data())) {
					return true;
				} else {
					auxiliar = auxiliar->next();
				}
			}
			return false;
		}
    }  // contém
/*!
        Documentacao VPL
    */
    T& at(std::size_t index) {
        if (index < size_) {
            Node *auxiliar = head;
			for(int i = 0; i < index; i++) {
					auxiliar = auxiliar->next();
				}
			return auxiliar->data();
        } else {
        throw std::out_of_range("ERROR POSICAO INVALIDA");
        }
    }  // acesso a um elemento (checando limites)
    /*!
        Documentacao VPL
    */
    const T& at(std::size_t index) const {
        if (index < size_) {
            Node *auxiliar = head;
			for(int i = 0; i < index; i++) {
					auxiliar = auxiliar->next();
				}
			return auxiliar->data();
        } else {
        throw std::out_of_range("ERROR POSICAO INVALIDA");
        }
    }  // getter constante a um elemento
/*!
        Documentacao VPL
    */
    std::size_t find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("LISTA VAZIA");
    }
        Node *atual = head;
        for (int i = 0; i < size_; i++) {
            if (atual->data() == data) {
                return i;
        }
            atual = atual->next();
    }
     return size_;
    }  // posição de um dado
    /*!
        Documentacao VPL
    */
    std::size_t size() const {
        return size_;
    }  // tamanho

 private:
    class Node {
     public:
        explicit Node(const T& data) :
            data_{data}
        {}
        Node(const T& data, Node* next) :
            data_{data},
            next_{next}
        {}
        Node(const T& data, Node* prev, Node* next) :
            data_{data}, prev_{prev}, next_{next}
        {}

        T& data() {
             return data_;
        }
        const T& data() const {
             return data_;
        }

        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* head;
    std::size_t size_;
};

}  // namespace structures

#endif
