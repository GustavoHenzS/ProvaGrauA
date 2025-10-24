#include "LojaEletr.h"
#include <limits> // para limpar o buffer do cin

int main() {
    Loja loja("TechWorld");
	
    Smartphone* s1 = new Smartphone("iPhone", 5000.0, "123", "14 Pro", 256);
    Laptop* l1 = new Laptop("Dell XPS", 7000.0, "456", "Dell", 15.6);
    Tablet* t1 = new Tablet("iPad", 4000.0, "789", "Apple", 12);

    int seletor = -1;

    while (seletor != 0) {
        cout << "\n========== LOJA DE ELETRÔNICOS ==========\n";
        cout << "1 - Sobre a loja\n";
        cout << "2 - Informações dos produtos\n";
        cout << "3 - Adicionar produtos ao estoque\n";
        cout << "4 - Remover produto do estoque\n";
        cout << "5 - Editar produto\n";
        cout << "6 - Valor total do estoque\n";
        cout << "7 - Aplicar desconto\n";
        cout << "8 - Listar informações da loja\n";
        cout << "9 - Realizar compra\n";
        cout << "10 - Verificar estoque de produto\n";
        cout << "0 - Sair\n";
        cout << "=========================================\n";
        cout << "Escolha uma opção: ";
        cin >> seletor;

        // validação da entrada
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida! Digite um número.\n";
            continue;
        }

        cout << endl;

        if (seletor == 1) {
            loja.apresentacao();
        }
        else if (seletor == 2) {
            loja.buscarProduto("456");
            loja.buscarProduto("789");
        }
        else if (seletor == 3) {
            loja.adicionarProduto(s1);
            loja.adicionarProduto(l1);
            loja.adicionarProduto(t1);
            cout << "Produtos adicionados ao estoque.\n";
        }
        else if (seletor == 4) {
            string codigo;
            cout << "Digite o código do produto a remover: ";
            cin >> codigo;
            loja.removerProduto(codigo);
        }
        else if (seletor == 5) {
            string codigo;
            cout << "Digite o código do produto que deseja editar: ";
            cin >> codigo;
            loja.editarProduto(codigo);
        }
        else if (seletor == 6) {
            loja.valorTotalEstoque();
        }
        else if (seletor == 7) {
            string codigo;
            double desconto;
            cout << "Código do produto: ";
            cin >> codigo;
            cout << "Percentual de desconto (%): ";
            cin >> desconto;
            loja.aplicarDesconto(codigo, desconto);
        }
        else if (seletor == 8) {
            loja.listarInformacoes();
        }
        else if (seletor == 9) {
            loja.realizarCompra(); 
        }
        else if (seletor == 10) {
            string codigo;
            cout << "Digite o código do produto: ";
            cin >> codigo;
            loja.verificarEstoqueProduto(codigo); 
        }
        else if (seletor == 0) {
            cout << "Saindo do programa... Até logo!\n";
        }
        else {
            cout << "Opção inválida! Tente novamente.\n";
        }
    }

    return 0;
}
