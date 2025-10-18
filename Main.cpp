#include "LojaEletr.h"

int main() {
	Loja loja;
	Smartphone* s1 = new Smartphone("iPhone", 5000.0, "123", "14 Pro", 256);
	Laptop* l1 = new Laptop("Dell XPS", 7000.0, "456", "Dell", 15.6);
	Tablet* t1 = new Tablet("iPad", 4000.0, "789", "Apple", 12);


	int seletor = 11;

	while (seletor != 0) {
		cout << "Loja de Eletronicos" << endl;
		cout << "Digete um dos numeros abaixo: " << endl;
		cin >> seletor;
		cout << "1 - Sobre a loja" << endl;
		cout << "2 - Informacoes dos produtos" << endl;
		cout << "3 - Adicionar produtos ao estoque" << endl;
		cout << "4 - Remover do estoque" << endl;
		cout << "5 - Editar produto" << endl;
		cout << "6 - Valor do estoque" << endl;
		cout << "7 - Aplicar desconto" << endl;
		cout << "8 - Verificar estoque de um produto" << endl;
		cout << "9 - Realizar compra" << endl;
		cout << "10 - Pesquisa de produto" << endl;
		cout << "0 - Sair do programa" << endl;

		if (seletor == 1) {
			loja.apresentacao();
			break;
		} if (seletor == 2) {
			loja.buscarProduto("456");
			loja.buscarProduto("789");
			break;
		} if (seletor == 3) {
			loja.adicionarProduto(s1);
			loja.adicionarProduto(l1);
			loja.adicionarProduto(t1);
			break;
		} if (seletor == 4) {
			loja.removerProduto("456");
			break;
		} if (seletor == 5) {
			loja.editarProduto(s1);
			break;
		} if (seletor == 6) {
			loja.valorTotalEstoque();
			break;
		} if (seletor == 7) {
			loja.aplicarDesconto("123", 10);;
			break;
		} if (seletor == 8) {
			loja.listarInformacoes();
			break;
		} if (seletor == 9) {
			loja.realizarCompra();
			break;
		} if (seletor == 10) {
			loja.valorPesquisa();
			break;
		} if (seletor == 0) {
			cout << "Saindo do programa!" << endl;
			break;
		}
		else {
			cout << "Tente novamente" << endl;
		}
	}
}