#include <iostream>
#include <vector>
#include <exception>
#include <locale> //isdigit
/* #include <boost/regex.hpp> */

class Paciente {
    private:
        std::string nome;
        std::string nome_mae;
        //guardar o RG em uma string pode ser um tiro no pé...
        std::string rg;
        std::string cpf;
        int ano_nasc;

        bool check_ano( int ano ) {
            if ( ano < 1900 ) {
                throw std::invalid_argument("Ano de nascimento é menor do que o mínimo(1900)");
			}
            return true;
        }

		bool check_nome ( std::string n ) {
			/* boost::regex fullname_regex ("[A-Za-z]*, [A-Za-z]*"); */
			/* boost::regex fullname_regex ("[A-Za-z]+(,*) [A-Za-z]*"); */
			/* if (! boost::regex_match (n, fullname_regex)) { */
			/* 	throw std::invalid_argument("Nome inválido: " + n); */
			/* } */
			/* Para que um nome seja válido a string não pode ser nula, 
			   não pode começar com um espaço em branco nem com um número. 
			   É possível criar regras mais sofisticadas para a validação
			   dos nomes mas mesmo assim existiriam casos limites onde
			   não seria possível definir uma única resposta certa.
  			   Alguns exemplos são:
				   -Brian W. Kernighan
				   -Artur Costa e Silva
				   -Garcia de Sousa D'Ávila
				   -William Henry Gates III
				   -Jr., Martin Luther King
				   -Pedro de Alcântara Francisco Antonio João Carlos Xavier de Paula Miguel Rafael Joaquim José Gonzaga Pascoal Cipriano Serafim de Bragança e Bourbon
			*/
			if ( (n != "") & (n[0] != ' ') & (!std::isdigit(n[0])) ) {
				return true;
			}
			else {
				throw std::invalid_argument("Nome inválido"); 
			}
			return false;
		}

    public:
        /* O compilador precisa do construtor padrão */
        Paciente();
        Paciente(std::string n, std::string n_mae, std::string r,
                 std::string c, int a_nasc)
        {
			check_nome( n );
            nome = n;
			check_nome( n_mae );
            nome_mae = n_mae;
            rg = r;
            cpf = c;
			check_ano( a_nasc );
            ano_nasc = a_nasc;
        }

        std::string get_nome() {
            return nome;
        }
        std::string get_nome_mae() {
            return nome_mae;
        }
        std::string get_rg() {
            return rg;
        }
        std::string get_cpf() {
            return cpf;
        }
        int get_ano() {
            return ano_nasc;
        }
        bool get_prioridade() {
            /* Isso vai dar problema no ano que vem! */
            if ((2016 - ano_nasc) >= 75) {
                return true;
            }
            else {
                return false;
            }
        }

};

/* Sobrecarga no operador << da calsse Paciente para facilitar a impressão dos dados */
std::ostream & operator<<(std::ostream & os, Paciente & p)
{
   os << "Dados do paciente:" << '\n';
   os << "\t Nome: " << p.get_nome()<< '\n';
   os << "\t Nome da mãe: " << p.get_nome_mae()<< '\n';
   os << "\t RG: " << p.get_rg()<< '\n';
   os << "\t CPF: " << p.get_cpf()<< '\n';
   os << "\t Ano de nascimento: " << p.get_ano() << '\n';
   os << "\t Atendimento prioritário: " << p.get_prioridade();
   os << std::endl;
   return os;
}


class Requisicao {
    private:
        Paciente paciente;
        bool prioritaria;
        int especialidade;
    public:
        Requisicao( Paciente paciente, bool p, int esp) {
            paciente = paciente;
            prioritaria = p;
            especialidade = esp;
    }
};

class UBS {
	private:
		std::vector<Requisicao> fila;
	public:
		UBS();
		bool entrar_na_fila( Requisicao r ) {
			fila.push_back( r );
			return true;
		}

		bool desistir_da_fila( std::string cpf ) {
			/* Pesquisar requisicao pelo cpf do paciente */
			std::cout << cpf;
			return true;
                }
};

Paciente pesquisar_paciente( std::vector<Paciente> pacientes_cadastrados , std::string cpf) {
	/* std::cin >> cpf; */
    std::cout << "procurando por " << cpf << std::endl;
	for (auto p : pacientes_cadastrados) {
		if (p.get_cpf() == cpf) {
			std::cout << p;
			std::cout << "Os dados do paciente estão corretos?(s/n)" << std::endl;
			std::string resp;
			std::cin >> resp;
			if (resp == "n") {
                throw std::invalid_argument("Paciente errado");
                /* return false; */
            }
            else if ( resp == "s") {
                return p;
            }
		}
	}
    /* Paciente não encontrado */
	/* return false; */
    throw std::invalid_argument("Paciente não encontrado");
}

Paciente criar_paciente( std::string cpf ) {
    std::string n, nm, rg, ano;
    /* int a_nasc; */
    std::cout << "Nome:" << std::endl;
    getline(std::cin, n);
    
    /* std::cin >> n; */
    std::cout << "Nome da mãe:" << std::endl;
    getline(std::cin, nm);
    /* std::cin >> nm; */
    std::cout << "RG:" << std::endl;
    getline(std::cin, rg);
    /* std::cin >> rg; */
    std::cout << "CPF:" << cpf << std::endl;
    /* getline(std::cin, cpf); */
    /* std::cin >> cpf; */
    std::cout << "Ano de nascimento:" << std::endl;
    getline(std::cin, ano);
    /* std::cin >> a_nasc; */
    try {
        /* std::cout << "dados entrados" << std::endl; */
        /* std::cout << n << std::endl;// << nm<< std::endl  << rg<< std::endl  << cpf<< std::endl  << ano << std::endl ; */
        Paciente pp(n, nm, rg, cpf, stoi(ano));
        return pp;
    }
    catch(std::invalid_argument& e) {
        throw std::invalid_argument("Paciente não pode ser criado");
    }
}

int main(){
	bool stop;
	stop = false;
	std::vector<Paciente> pacientes_cadastrados;
	std::cout << "Sistema de gerenciamento de filas de UBS" << std::endl;
	std::cout << "1 - Registrar chegada" << std::endl;
	while (!stop){
		std::cout << "Digite a opção desejada:" << std::endl;
		/* int a; */
        std::string a;
        getline(std::cin, a);
		/* std::cin >> a; */
        std::cout << "voce escolheu " << a << std::endl;
        std::string cpf;
		if (a == "1") {
            try {
                /* Paciente paciente; */
	std::cout << "Digite o CPF do paciente:" << std::endl;
    getline(std::cin, cpf);
                auto paciente = pesquisar_paciente( pacientes_cadastrados, cpf);
            }
            catch(std::invalid_argument& e) {
                /* Paciente novo; */
                auto novo = criar_paciente(cpf);
                pacientes_cadastrados.push_back(novo);
            }
		}	
        if (a == "0") {
            stop = true;
        }
		/* try { */

		/* 	Paciente pp("1", "asdd, dsa", "00", "11", 1990); */
		/* 	std::cout << pp; */
		/* } */
		/* catch(std::invalid_argument& e) { */
		/* 	std::cerr << e.what() << std::endl; */
		/* } */
	}
	for (auto p : pacientes_cadastrados) {
        std::cout << p;
    }
    return 0;
}
