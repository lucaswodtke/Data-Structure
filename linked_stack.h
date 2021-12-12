// ©copyright Lucas Henrique Gonçalves Wodtke-16202258
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {
    /**
 * Pilha encadeada
 */

template<typename T>
class LinkedStack {
 public:
    LinkedStack() {
        size_ = size_;
        head = nullptr;
    }

    ~LinkedStack() {
        clear();
    }
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
    }  // limpa pilha
 /*!
        Documentacao VPL
    */
    void push(const T& data) {
        Node *new_ = new Node(data, head);
        head = new_;
		size_ = size_ + 1;
    }  // empilha
 /*!
        Documentacao VPL
    */
    T pop() {
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
    }  // desempilha
 /*!
        Documentacao VPL
    */
    T& top() const {
        if (0 < size_) {
            Node *auxiliar = head;
			for(int i = 0; i < 0; i++) {
					auxiliar = auxiliar->next();
				}
			return auxiliar->data();
        } else {
        throw std::out_of_range("ERROR POSICAO INVALIDA");
        }
    }  // dado no topo
 /*!
        Documentacao VPL
    */
    bool empty() const {
        return size_ == 0;
    }  // pilha vazia
 /*!
        Documentacao VPL
    */
    std::size_t size() const {
        return size_;
    }  // tamanho da pilha

 private:
  class Node {
   public:
        /**
         *Construtor gera um node com dado e o proximo node
    	 *data Dado guardo pelo node/ next proximo node a ser guardado pelo node
    	 */
        explicit Node(const T& data):
            data_{data}
        {}
        /**
         *Construtor dado passado como parâmetro e o próximo node.
    	 */
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
       /**
	    *Getter do Dado		
	    */
        T& data() {
            return data_;
        }
       /**
	    *Getter Constante do Dado
	    */
        const T& data() const {
            return data_;
        }
       /**
        *Getter do Próximo Node 		
	    */
        Node* next() {
            return next_;
        }
       /**
        *Getter Constante do Próximo Node 
	    */
        const Node* next() const {
            return next_;
        }
       /**
	    *Setter do Próximo Node 		
	    */
        void next(Node* node) {
            next_ = node;
        }

   private:
       /**
	    *data_Dado guardado pelo node.
	    */     
        T data_;
       /**
        * next_Próximo node.
        */
        Node* next_{nullptr};
  };
    /**
	 *Getter do ultimo Nodo da Lista
	 */
    Node* end() {
        auto auxiliar = head;
        for (int i = 1u; i < size(); ++i) {
            auxiliar = auxiliar->next();
        }
        return auxiliar;
    }
    /**
	 *head Ponteiro para primeiro node da lista.
	 */
    Node* head{nullptr};
    /**
	 *size_Tamanho da lista. 
	 */
    std::size_t size_{0u};
};

}  // namespace structures
