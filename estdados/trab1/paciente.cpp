#include <iostream>
#include <vector>
#include <exception>
#include <locale> //isdigit
#include <iomanip>

class Paciente {
    private:
        std::string nome;
        std::string nome_mae;
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
Paciente::Paciente() { };

/* Sobrecarga no operador << da classe Paciente para facilitar a impressão dos dados */
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
        Requisicao();
        Requisicao( const Requisicao &obj);
        Requisicao( Paciente pac, bool p, int esp) {
            paciente = pac;
            prioritaria = p;
            especialidade = esp;
    }
        std::string get_nome_paciente() {
            return paciente.get_nome();
        }

        int get_id_especialidade() {
            return especialidade;
        }

        Paciente get_paciente() {
            return paciente;
        }

        std::string get_nome_especialidade() {
            if ( especialidade == 0 ) {
                return "Triagem";
            }
            if ( especialidade == 1 ) {
                return "Oftalmologia";
            }
            if ( especialidade == 2 ) {
                return "Clinica Geral";
            }
            if ( especialidade == 3 ) {
                return "Pediatria";
            }
            throw std::invalid_argument("Especialidade inválida"); 
        }

        std::string get_prioridade() {
            if (paciente.get_prioridade() ) {
                return "Sim";
            }
            else {
                return "Não";
            }
        }

        std::string get_cpf_paciente() {
            return paciente.get_cpf();
        }
};
Requisicao::Requisicao() {};
Requisicao::Requisicao(const Requisicao &obj)
{
    paciente = obj.paciente;
    especialidade = obj.especialidade;
    prioritaria = obj.prioritaria;
}

std::ostream & operator<<(std::ostream & os, Requisicao & p)
{
   os << "Dados da requisição" << '\n';
   os << "\t Nome: " << p.get_nome_paciente()<< '\n';
   os << "\t Especialidade: " << p.get_nome_especialidade()<< '\n';
   os << "\t Atendimento prioritário: " << p.get_prioridade();
   os << std::endl;
   return os;
}

class UBS {
	private:
        /* Na documentação não foi dito de maneira explícita de que forma
         * deveria aconter a implementação, apenas que as ordens de atendimento
         * referentes às especialidades deveriam ser respeitadas.
         * Com base nisso decidimos por uma solução mais genérica que utiliza
         * apenas uma lista. Desta forma seria muito mais simples adicionar
         * ou remover especialidades no futuro.*/
		std::vector<Requisicao> fila;
        std::vector<Requisicao> registro;
	public:
		UBS();
		bool entrar_na_fila( Requisicao r ) {
			fila.push_back( r );
			return true;
		}

		bool desistir_da_fila( int posicao ) {
			/* Pesquisar requisicao pelo cpf do paciente */
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);

            std::ostringstream oss;
            oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
            auto str = oss.str();

            std::cout << str << std::endl;
			std::cout << fila[posicao].get_nome_paciente();
            fila.erase(fila.begin()+posicao); 
			return true;
        }

        int find_position(std::string cpf) {
            int cont =0;
            for (auto e: fila) {
                if (e.get_cpf_paciente() == cpf ) {
                    return cont;
                }
                cont ++;
            }
        }

        void imprimir_fila() {
            std::cout << "Digite a fila que deseja verificar: \n";
            std::cout << "1 - Oftamologia" << '\n';
            std::cout << "2 - Clinica geral" << '\n';
            std::cout << "3 - Pediatria" << '\n';
            std::cout << "0 - Triagem" << '\n';
            std::string resp;
            getline(std::cin, resp);
            int cont =0;
            int pri =0;
            for (auto e: fila) {
                if ( e.get_id_especialidade() == stoi(resp)){
                    cont ++;
                    if ( e.get_prioridade() == "Sim") {
                        pri ++;
                    }
                }
            }
            std::cout << "A fila selecionada tem " << cont << " pacientes na fila, \n";
            std::cout << "dos quais " << pri << " são de atendimento prioritário. \n";
        };
        Requisicao get_requisicao( std::string cpf ) {

            auto x = find_position(cpf);
            return fila[x];
        }

        void print_requesicao( int posicao) {
            std::cout << fila[posicao] << '\n';
        }

        int contar_prioridades ( int esp ) {
            int cont=0;
            for (auto e: fila) {
                if (e.get_id_especialidade() == esp) {
                    if (e.get_prioridade() == "Sim") {
                        cont ++;
                    }
                }
            }
            return cont;
        }

        bool autenticar() {
            std::cout << "Digite a senha:";
            std::string senha;
            getline(std::cin, senha);
            if ( senha == "123" ) {
                return true;
            }
            else {
                return false;
            }
        }

        Requisicao chamar_paciente( int esp ) {
            int cont =0;
            int pri =0;
            pri = contar_prioridades(esp);
            for (auto e: fila) {
                cont ++;
                if ( pri > 0) {
                    if (e.get_prioridade() == "Não") {
                        continue;
                    }
                    else {
                        std::cout << "Chamando paciente prioritário";
                        std::cout << e;
                        Requisicao qwe = criar_requisicao(e.get_paciente(), e.get_id_especialidade());
                        fila.erase(fila.begin()+(cont-1));
                        return qwe;
                    }
                }
                else if (e.get_id_especialidade() == esp) {
                    std::cout << "chamando paciente \n";
                    std::cout << e;
                    Requisicao qwe = criar_requisicao(e.get_paciente(), e.get_id_especialidade());
                    fila.erase(fila.begin()+cont); 
                    return qwe;
                }
            }
        }

        void registrar_atendimento( Requisicao req ) {
            registro.push_back( req );
        }

        Requisicao criar_requisicao( Paciente pac, int esp ) {
            return Requisicao (pac, pac.get_prioridade(), esp);
        }

        void listar_atendimentos ( int qte ) {
            std::cout << "Listando os últimos " << qte << " atendimentos realizados.\n";
            if (qte < registro.size() ) {
                std::cout << "menor \n";
                    int xx;
                for ( int i=0; i<(qte); i++ ) {
                    xx = registro.size()-(i+1);
                    std::cout << "aljfd " << xx << '\n';
                    std::cout << registro[xx];
                }
            }
            else {
                std::cout << "maior \n";
                for (auto e = registro.rbegin(); e != registro.rend(); ++e) {
                    std::cout << *e;
                }
            }
        }
};

UBS::UBS() {} ;

Paciente pesquisar_paciente( std::vector<Paciente> pacientes_cadastrados , std::string cpf) {
	for (auto p : pacientes_cadastrados) {
		if (p.get_cpf() == cpf) {
			std::cout << p;
			std::cout << "Os dados do paciente estão corretos?(sim/nao)" << std::endl;
			std::string resp;
            getline(std::cin, resp);
			if (resp == "nao") {
                throw std::invalid_argument(std::string("Paciente errado"));
            }
            else if ( resp == "sim") {
                return p;
            }
		}
	}
    throw std::invalid_argument(std::string("Paciente não encontrado"));
}

Paciente criar_paciente( std::string cpf ) {
    std::string n, nm, rg, ano;
    std::cout << "Nome:" << std::endl;
    getline(std::cin, n);
    std::cout << "Nome da mãe:" << std::endl;
    getline(std::cin, nm);
    std::cout << "RG:" << std::endl;
    getline(std::cin, rg);
    std::cout << "CPF:" << cpf << std::endl;
    std::cout << "Ano de nascimento:" << std::endl;
    getline(std::cin, ano);
    try {
        Paciente pp(n, nm, rg, cpf, stoi(ano));
        return pp;
    }
    catch(std::invalid_argument& e) {
        throw std::invalid_argument("Paciente não pode ser criado");
    }
}

Requisicao criar_requisicao( Paciente pac ) {
    std::cout << "As especialidades disponíveis são: " << '\n';
    std::cout << "1 - Oftamologia" << '\n';
    std::cout << "2 - Clinica geral" << '\n';
    std::cout << "3 - Pediatria" << '\n';
    std::cout << "Se você não sabe a especialidade digite 0" << '\n';
    std::string esp;
    getline(std::cin, esp);
    if (esp == "1") {
        return Requisicao(pac, pac.get_prioridade(), 1 );
    }
    if (esp == "2") {
        return Requisicao(pac, pac.get_prioridade(), 2 );
    }
    if (esp == "3") {
        return Requisicao(pac, pac.get_prioridade(), 3 );
    }
    return Requisicao(pac, pac.get_prioridade(), 0 );
}

int main(){
	bool stop;
	stop = false;

	std::vector<Paciente> pacientes_cadastrados;
    UBS unidade;
	std::cout << "Sistema de gerenciamento de filas de UBS" << std::endl;
	while (!stop){
		std::cout << "== Você está no menu principal ==" << std::endl;
        std::cout << "1 - Registrar chegada" << std::endl;
        std::cout << "2 - Consultar fila da UBS" << std::endl;
        std::cout << "3 - Desistir da fila" << std::endl;
        std::cout << "4 - Chamar paciente" << std::endl;
        std::cout << "5 - Listar atendimentos" << std::endl;
        std::cout << "6 - Listar pacientes cadastrados" << std::endl;
        std::cout << "0 - Finalizar operação" << std::endl;
        std::cout << " --- " << std::endl;
		std::cout << "Digite a opção desejada:" << std::endl;
        std::string a;
        getline(std::cin, a);
        std::string cpf;
		if (a == "1") {
            Paciente paciente;
            Requisicao req;
            try {
                std::cout << "Digite o CPF do paciente:" << std::endl;
                getline(std::cin, cpf);
                paciente = pesquisar_paciente( pacientes_cadastrados, cpf);
            }
            catch(std::invalid_argument& e) {
                if ( e.what() == std::string("Paciente não encontrado" )) {
                    std::cout << "Paciente não cadastrado" << std::endl;
                    paciente = criar_paciente(cpf);
                    pacientes_cadastrados.push_back(paciente);
                }
                else if ( e.what() == std::string("Paciente errado" )) {
                    continue;
                }
            }

            req = criar_requisicao(paciente);
            unidade.entrar_na_fila(req);
		}
		if (a == "2") {
            unidade.imprimir_fila();
        }
		if (a == "3") {
            std::cout << "Digite o cpf do paciente que deseja desistir da fila\n";
            std::string cpf;
            getline(std::cin, cpf);
            auto s = unidade.find_position(cpf);
            unidade.print_requesicao(s);
            std::cout << "Confirmar desistência?(sim/nao)\n";
            std::string resp;
            getline(std::cin, resp);
            if (resp == "sim" ) {
                unidade.desistir_da_fila(s);
            }
            else {
                continue;
            }
        }
		if (a == "4") {
            bool auth = false;
            auth = unidade.autenticar();
            if (auth) {
                std::cout << "Digite a especialidade que você está chamando: " << '\n';
                std::cout << "1 - Oftamologia" << '\n';
                std::cout << "2 - Clinica geral" << '\n';
                std::cout << "3 - Pediatria" << '\n';
                std::cout << "0 - Triagem" << '\n';
                std::string esp;
                getline(std::cin, esp);
                Requisicao rr;
                rr = unidade.chamar_paciente(stoi(esp));
                unidade.registrar_atendimento(rr);
            }
            else {
                std::cout << "Senha errada";
            }
        }
        if (a == "5") {
            bool auth = false;
            auth = unidade.autenticar();
            if (auth) {
                std::cout << "Digite quantos registros você deseja ver \n";
                std::string qqq;
                getline(std::cin, qqq);
                unidade.listar_atendimentos(stoi(qqq));
            }
            else {
                std::cout << "Senha errada";
            }
        }
        if (a == "6") {
            bool auth = false;
            auth = unidade.autenticar();
            if (auth) {
                std::cout << "Pacientes cadastrados nesta unidade: \n";
                for (auto p: pacientes_cadastrados) {
                    std::cout << p;
                }
            }
            else {
                std::cout << "Senha errada";
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
			/* Paciente pp("nome valido", "asdd, dsa", "00", "11", 1990); */
            /* Requisicao rr(pp, pp.get_prioridade(), 0); */
            /* std::cout << rr; */
	/* for (auto p : pacientes_cadastrados) { */
        /* std::cout << p; */
    /* } */
    return 0;
}
