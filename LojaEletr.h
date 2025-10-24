#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUTOS = 50;

class Produto {
protected:
    string nome;
    double preco;
    string codbarras;

public:
    Produto(string n = "", double p = 0.0, string cod = "");
    virtual ~Produto() {}

    string getNome() const;
    double getPreco() const;
    string getCodigo() const;

    void setNome(string n);
    void setPreco(double p);

    bool igual(const Produto& outro) const;
    virtual void exibir() const = 0; 
};

class Smartphone : public Produto {
private:
    string modelo;
    int armazenamento;

public:
    Smartphone(string n = "", double p = 0.0, string c = "", string m = "", int a = 0);
    void setModelo(string m);
    void setArmazenamento(int a);
    void exibir() const override;
};

class Laptop : public Produto {
private:
    string marca;
    double tamanhoTela;

public:
    Laptop(string n = "", double p = 0.0, string c = "", string m = "", double t = 0.0);
    void setMarca(string m);
    void setTamanhoTela(double t);
    void exibir() const override;
};

class Tablet : public Produto {
private:
    string marca;
    int duracaoBateria;

public:
    Tablet(string n = "", double p = 0.0, string c = "", string m = "", int h = 0);
    void setMarca(string m);
    void setDuracaoBateria(int h);
    void exibir() const override;
};

class Loja {
private:
    string nome;
    Produto* estoque[MAX_PRODUTOS];
    int qtdProdutos;

public:
    Loja(string nome = "Minha Loja");

    void apresentacao();
    void adicionarProduto(Produto* p);
    void removerProduto(string codigo);
    void editarProduto(string codigo);
    void buscarProduto(string codigo) const;
    void listarInformacoes() const;
    void aplicarDesconto(string codigo, double percentual);
    void valorTotalEstoque() const;

    void verificarEstoqueProduto(string codigo) const;
    void realizarCompra();
};


