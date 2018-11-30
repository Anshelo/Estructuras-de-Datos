class Nodo{
	private:
		int dato;
		Nodo *siguiente;
	public: 
		Nodo(){}
		~Nodo(){}
		Nodo(int valor,Nodo *_siguiente){
			dato = valor;
			siguiente=siguiente;
		}
		Nodo *getSiguiente(){
			return siguiente;
		}
		int getDato(){
			return dato;
		}
		void setDato(int valor){
			dato=valor;
		}
		void setSiguiente(Nodo *_siguiente){
			siguiente=_siguiente;
		}
		
};
