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
   os << "\t Ano de nascimento: " << p.get_prioridade();
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

int main(){
	try {
		Paciente pp("1", "asdd, dsa", "00", "11", 1990);
	std::cout << pp;
	}
	catch(std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
    return 0;
}
