#include "LojaEletr.h"
using namespace std;

Produto::Produto(string n, double p, string cod) {
    nome = n;
    preco = p;
    codbarras = cod;
}

string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

string Produto::getCodigo() const {
    return codbarras;
}

void Produto::setNome(string n) {
    nome = n;
}

void Produto::setPreco(double p) {
    preco = p;
}

bool Produto::igual(const Produto& outro) const {
    return codbarras == outro.codbarras;
}

// ======================= SMARTPHONE =======================
Smartphone::Smartphone(string n, double p, string c, string m, int a)
    : Produto(n, p, c) {
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
    cout << "Smartphone: " << nome << endl;
    cout << "Preço (R$): " << preco << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Armazenamento: " << armazenamento << " GB" << endl;
    cout << "Código: " << codbarras << endl << endl;
}

// ======================= LAPTOP =======================
Laptop::Laptop(string n, double p, string c, string m, double t)
    : Produto(n, p, c) {
    marca = m;
    tamanhoTela = t;
}

void Laptop::setMarca(string m) {
    marca = m;
}

void Laptop::setTamanhoTela(double t) {
    tamanhoTela = t;
}

void Laptop::exibir() const {
    cout << "Laptop: " << nome << endl;
    cout << "Preço (R$): " << preco << endl;
    cout << "Marca: " << marca << endl;
    cout << "Tamanho da tela: " << tamanhoTela << " polegadas" << endl;
    cout << "Código: " << codbarras << endl << endl;
}

Tablet::Tablet(string n, double p, string c, string m, int h)
    : Produto(n, p, c) {
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
    cout << "Tablet: " << nome << endl;
    cout << "Preço (R$): " << preco << endl;
    cout << "Marca: " << marca << endl;
    cout << "Duração da bateria: " << duracaoBateria << "h" << endl;
    cout << "Código: " << codbarras << endl << endl;
}

Loja::Loja(string n) {
    nome = n;
    qtdProdutos = 0;
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        estoque[i] = nullptr;
    }
}

void Loja::apresentacao() {
    cout << "Bem-vindo à loja: " << nome << endl;
    cout << "Vendemos eletrônicos de alta qualidade, incluindo smartphones, laptops e tablets." << endl << endl;
}

void Loja::adicionarProduto(Produto* p) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (estoque[i]->igual(*p)) {
            cout << "Erro: Código de barras duplicado!" << endl;
            return;
        }
    }

    if (qtdProdutos < MAX_PRODUTOS) {
        estoque[qtdProdutos++] = p;
        cout << "Produto adicionado com sucesso!" << endl;
    } else {
        cout << "Erro: Estoque cheio!" << endl;
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
    }
    cout << "Produto não encontrado." << endl;
}

void Loja::buscarProduto(string codigo) const {
    for (int i = 0; i < qtdProdutos; i++) {
        if (estoque[i]->getCodigo() == codigo) {
            estoque[i]->exibir();
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void Loja::editarProduto(string codigo) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (estoque[i]->getCodigo() == codigo) {
            string novoNome;
            double novoPreco;
            cout << "Digite o novo nome do produto: ";
            cin >> novoNome;
            cout << "Digite o novo preço (R$): ";
            cin >> novoPreco;
            estoque[i]->setNome(novoNome);
            estoque[i]->setPreco(novoPreco);
            cout << "Produto atualizado com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void Loja::listarInformacoes() const {
    cout << "Loja: " << nome << endl;
    cout << "Quantidade de produtos: " << qtdProdutos << endl << endl;

    for (int i = 0; i < qtdProdutos; i++) {
        estoque[i]->exibir();
    }
}

void Loja::aplicarDesconto(string codigo, double percentual) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (estoque[i]->getCodigo() == codigo) {
            double novoPreco = estoque[i]->getPreco() * (1 - percentual / 100.0);
            estoque[i]->setPreco(novoPreco);
            cout << "Desconto aplicado! Novo preço (R$): " << novoPreco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void Loja::valorTotalEstoque() const {
    double total = 0.0;
    for (int i = 0; i < qtdProdutos; i++) {
        total += estoque[i]->getPreco();
    }
    cout << "Valor total do estoque (R$): " << total << endl;
}

void Loja::verificarEstoqueProduto(string codigo) const {
    int contagem = 0;
    for (int i = 0; i < qtdProdutos; i++) {
        if (estoque[i]->getCodigo() == codigo) {
            contagem++;
        }
    }
    if (contagem > 0)
        cout << "Quantidade em estoque do produto " << codigo << ": " << contagem << endl;
    else
        cout << "Produto esgotado ou não encontrado." << endl;
}

void Loja::realizarCompra() {
    string codigo;
    cout << "Digite o código do produto a ser vendido: ";
    cin >> codigo;

    for (int i = 0; i < qtdProdutos; i++) {
        if (estoque[i]->getCodigo() == codigo) {
            cout << "Venda realizada!" << endl;
            cout << "Produto: " << estoque[i]->getNome() << endl;
            cout << "Valor total da venda (R$): " << estoque[i]->getPreco() << endl;
            removerProduto(codigo); // remove do estoque
            return;
        }
    }
    cout << "Produto não disponível ou estoque zerado." << endl;
}