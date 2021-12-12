// ©copyright Lucas Henrique Gonçalves Wodtke-16202258

#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

/**
 *Lista encadeada
 */
template<typename T>
class DoublyCircularList {
 public:
     /**
	 *Construtor Default Head aponta para null/Size_(tamanho) é zero
	 */
    DoublyCircularList() {
        size_ = size_;
        head = nullptr;
    }
     /**
	 *Destrutor Aciona o metodo clear para limpar a lista
	 */
    ~DoublyCircularList() {
        clear();
    }
    /**
	 *Metodo clear que limpa a lista encadeada
	 */
    void clear() {
        Node *primeiro_node = head;
		while (primeiro_node != nullptr) {
			primeiro_node = primeiro_node->next();
			pop_front();
		}
		size_ = 0;
    }
    /**
	 *Inserir(push)  um elemento(Data) no fim(back) da lista.Reuso de metodos
	 */
    void push_back(const T& data) {
        insert(data, size_);
    }
    /**
     *Inserir(push)  um elemento(Data) no inicio(front) da lista.Reuso de metodos
	 */
    void push_front(const T& data) {
        Node *new_ = new Node(data, head);
        head = new_;
		size_ = size_ + 1;
    }
    /**
	 *Insere(insert) um elemento(data) na posicao(index) 
	 */
    void insert(const T& data, std::size_t index) {
        if (index < 0 || index > size_) {
			throw std::out_of_range("ERROR POSICAO INVALIDA");
		}
		if(index == 0) {
			push_front(data);
		} else {
		   Node *Novo;
		   Node *Anterior;
           Anterior = head;
           int i = 0;
           while (i < index-1) {
               Anterior = Anterior->next();
               i++;
           }
            Novo = new Node (data, Anterior->next());
            Anterior->next(Novo);
            size_ = size_ +1;
		}
	}
	/**
	 *Insere(insert) um elemento(data) na ordem(sorted)
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
    }
    /** 
     *Acessa um elemento na posição(index) e retorna o elemento 
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
    }
    /** 
     *Acessa um elemento na posição(index) e retorna o elemento (constante)
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
    }
    /**
	 *Retira(Pop) da lista o elemento na posição(index) passada como parâmetro.
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
    }
    /**
	 *Retira(Pop) o ultimo(back) elemento da lista, usando o método pop(), e o retorna
	 */
    T pop_back() {
       return pop(size_-1);
    }
    /**Retirar(pop) do Início(front) o primeiro elemento da lista e o retorna
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
    /**
	 *Remove um elemento (data), reuso do metodo pop() e find().
	 */
    void remove(const T& data) {
        pop(find(data));
    }
    /**
     *Verifica se a lista está vazia 		
	 */
    bool empty() const {
        return size_ == 0;
    }
    /**
     *Verifica se na listam contem um elemento(data)
	 */
    bool contains(const T& data) const {
        		if(empty()) {
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
    }
    /**
     *Retorna a posicao do elemento(dado) na lista
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
    }
    /**
     *Verifica o tamanho da lista
	 */
    std::size_t size() const {
        return size_;
    }

 private:
    /**
	 *Representa um Elemento da Lista
	 */
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

#endif
