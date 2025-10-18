#include "LojaEletr.h"

Produto::Produto(string n = "", double p = 0.0, string cod = "") {
	nome = n;
	preco = p;
	codbarras = cod;
};

string Produto::getNome() const {
	return nome;
};

double Produto::getPreco() const {
	return preco;
};

string Produto::getCodigo() const {
	return codbarras;
};

void Produto::setNome(string n) {
	nome = n;
}

void Produto::setPreco(double p) {
	preco = p;
}

bool Produto::igual(const Produto& outro) const {
	return codbarras == outro.codbarras;
}

Smartphone::Smartphone(string n, float p, string c, string m, int a) {
	n = getNome();
	p = getPreco();
	c = getCodigo();
	modelo = m;
	armazenamento = a;
}

void Smartphone::setModelo(string m) { 
	modelo = m; 
}

void Smartphone::setArmazenamento(int a) { 
	armazenamento = a; 
}

void Smartphone::exibir() const {
	cout << "Laptop: " << nome << endl;
	cout << "Reais: " << preco << endl;
	cout << "Modelo: " << modelo << endl;
	cout << "Armazenamento: " << armazenamento << endl;
}

Laptop::Laptop(string n, float p, string c, string m, float t) {
	n = getNome();
	p = getPreco();
	c = getCodigo();
	marca = m;
	tamanhoTela = t;
}

void Laptop::setMarca(string m) { 
	marca = m; 
}

void Laptop::setTamanhoTela(float t) { 
	tamanhoTela = t; 
}

void Laptop::exibir() const {
	cout << "Laptop: " << nome << endl;
	cout << "Reais: " << preco << endl;
	cout << "Marca: " << marca << endl;
	cout << "Tela: " << tamanhoTela << endl;
	cout << "Codigo: " << codbarras << endl;
}

Tablet::Tablet(string n, float p, string c, string m, int h) {
	n = getNome();
	p = getPreco();
	c = getCodigo();
	marca = m;
	duracaoBateria = h;
}

void Tablet::setMarca(string m) { 
	marca = m; 
}
void Tablet::setDuracaoBateria(int h) { 
	duracaoBateria = h; 
}

void Tablet::exibir() const {
	cout << "Laptop: " << nome << endl;
	cout << "Reais: " << preco << endl;
	cout << "Marca: " << marca << endl;
	cout << "Tela: " << duracaoBateria << endl;
	cout << "Codigo: " << codbarras << endl;
}

Loja::Loja(string n = "Loja de Produtos") {
	nome = n;
	qtdProdutos = 0;

	for (int i = 0; i < MAX_PRODUTOS; i++) {
		estoque[i] = nullptr;
	}
};

Loja::~Loja() {
	for (int i = 0; i < qtdProdutos; i++) {
		delete estoque[i];
	}
}

void Loja::apresentacao() 
{
	cout << nome << endl;
	cout << "Somos uma loja que vendemos diversos tipos de eletronicos," << endl;
	cout << "os produtos incluem smartphones, laptops e tablets." << endl;

}

void Loja::adicionarProduto(Produto* p) {
	for (int i = 0; i < qtdProdutos; i++) {
		if (estoque[i]->igual(*p)) {
			cout << "Erro: Código de barras duplicado!" << endl;
			return;
		}
	}
	if (qtdProdutos < 50) {
		estoque[qtdProdutos++] = p;
		cout << "Produto adicionado com sucesso!" << endl;
	}
	else {
		cout << "Estoque cheio!" << endl;
	}
}

void Loja::removerProduto(string codigo) {
	for (int i = 0; i < qtdProdutos; i++) {
		if (estoque[i]->getCodigo() == codigo) {
			delete estoque[i];
			estoque[i] = estoque[qtdProdutos - 1];
			estoque[qtdProdutos - 1] = nullptr;
			qtdProdutos--;
			cout << "Produto removido com sucesso!" << endl;
			return;
		}
		else {
			cout << "Produto não encontrado." << endl;
		}
	}
}

void Loja::buscarProduto(string codigo) const {
	for (int i = 0; i < qtdProdutos; i++) {
		if (estoque[i]->getCodigo() == codigo) {
			estoque[i]->exibir();
			return;
		}
		else {
			cout << "Produto não encontrado." << endl;
		}
	}
}


void Loja::listarInformacoes() const {
	cout << "Loja: " << nome << endl;
	cout << "Quantidade de produtos: " << qtdProdutos << endl;
	for (int i = 0; i < qtdProdutos; i++) {
		estoque[i]->exibir();
	}
}

void Loja::aplicarDesconto(string codigo, float percentual) {
	for (int i = 0; i < qtdProdutos; i++) {
		if (estoque[i]->getCodigo() == codigo) {
			float novoPreco = estoque[i]->getPreco() * (1 - percentual / 100);
			estoque[i]->setPreco(novoPreco);
			cout << "Desconto aplicado! Novo preço - Reais: " << novoPreco << endl;
			return;
		}
		else {
			cout << "Produto não encontrado." << endl;
		}
	}
}

void Loja::valorTotalEstoque() const {
	float total = 0;
	for (int i = 0; i < qtdProdutos; i++) {
		total += estoque[i]->getPreco();
		cout << "Valor total do estoque - Reais: " << total << endl;
	}
}

