#-*-coding: utf-8-*-

def representa(valor, base):
    ############################
    #
    #   A função recebe um valor representado na
    # base decimal e uma base.
    #   O resultado é uma lista com os símbolos
    # na base desejada.
    #
    ############################
    # Precisão do valor original
    tamanho = len(str(valor).split('.')[-1])
    # Parte fracionária do valor original
    frac = valor - int(valor)
    if isinstance(valor, float):
        float_flag = True
    else:
        float_flag = False
    resultado = ''
    # Representa a parte inteira do valor
    while valor>0:
        quociente, resto = divmod(valor, base)
        resto = valor_to_simb(resto)
        if isinstance(resto, float):
            resto = int(resto)
        resultado += str(resto)
        valor = quociente
    if resultado == '':
        resultado = '0'
    # Pela forma que o cálculo é realizado o resultado fica invertido
    resultado = resultado[::-1]
    # Caso seja necessário computaremos a representação da parte fracionária
    if float_flag:
        resultado += '.'
        dec = ''
        valor = frac
        for i in range(tamanho):
            valor = valor * base
            quociente, resto = divmod(valor, base)
            dec += str(int(resto))
            valor = resto
        resultado += dec
    return resultado


def quantifica(representacao, base):
    ############################
    #
    #  Recebe uma representação e a base associada e com essas informações
    # retorna o valor associado a essa representação na base decimal.
    #
    ############################
    # Assumiremos que será usado apenas '.' para separar a parte inteira da fracionária
    representacao_list = representacao.split('.')
    #  representacao_list é uma lista que contém na primeira posição o valor inteiro
    # e na segunda posição a parte fracionária do valor.
    #  Caso representacao não possua parte fracionária representacao_list terá apenas
    # um elemento.
    representacao_int = representacao_list[0]
    representacao_frac = None
    if len(representacao_list) > 1:
        representacao_frac = representacao_list[-1]
    resultado = 0
    # Invertemos o valor para realizar o cálculo
    representacao_int = representacao_int[::-1]
    # Parte inteira
    for potencia, simbolo in enumerate(representacao_int):
        if isinstance(simbolo, str):
            if not simbolo.isdigit():
                simbolo = simb_to_valor(simbolo)
        resultado += int(simbolo) * pow(base, potencia)
    # Parte fracionaria
    if representacao_frac:
        f = 0.0
        # A parte fracionária não precisa ser invertida
        for potencia, simbolo in enumerate(representacao_frac):
            if isinstance(simbolo, str):
                if not simbolo.isdigit():
                    # Caso simbolo seja não seja um número, precisamos converter
                    simbolo = simb_to_valor(simbolo)
            f += int(simbolo) * pow(base, (-1)*(potencia+1))
        return resultado + f
    return resultado


def valor_to_simb(valor):
    ############################
    #
    #  Com esta implementação estamos impossibilitados de utilizar
    # bases maiores do que 200.
    #  Caso fosse necessário utilizar bases gigantes deveríamos utilizar
    # a função unichr(). Desta forma poderíamos utilizar todos os caracteres
    # unicode como símbolos.
    #
    ############################
    if valor > 9:
        return chr(55+int(valor))
    else:
        return valor


def simb_to_valor(simb):
    ############################
    #
    #  Função inversa de valor_to_simb().
    #
    ############################
    return ord(simb)-55


#  Código adicionado para a lista 2
#  A forma mais correta de solucionar o problema, provavelmente, é criar uma classe
# e definir os métodos de soma, subtração, ... Isso permitiria realizar operações
# sem grandes preocupações sobre a representação dos valores. Apesar disto,
# utilizarei aqui a saída mais fácil.

def soma_arbitraria(rep1, rep2, base):
    ############################
    #
    # Soma quaisquer dois valores que estejam na mesma base
    #
    ############################
    res = quantifica(rep1, base) + quantifica(rep2, base)
    return representa(res, base)


def subtracao_arbitraria(rep1, rep2, base):
    ############################
    #
    # Subtrai quaisquer dois valores que estejam na mesma base
    #
    ############################
    res = quantifica(rep1, base) - quantifica(rep2, base)
    return representa(res, base)

def multiplicacao_arbitraria(rep1, rep2, base):
    ############################
    #
    # Multiplica quaisquer dois valores que estejam na mesma base
    #
    ############################
    res = quantifica(rep1, base) * quantifica(rep2, base)
    return representa(res, base)

def divisao_arbitraria(rep1, rep2, base):
    ############################
    #
    # Divide quaisquer dois valores que estejam na mesma base
    #
    ############################
    res = quantifica(rep1, base) / float(quantifica(rep2, base))
    return representa(res, base)

print soma_arbitraria('101', '11', 2)
print subtracao_arbitraria('110', '10', 2)
print multiplicacao_arbitraria('10', '10', 2)
print divisao_arbitraria('100', '10', 2)
print soma_arbitraria('F8', 'A34', 16)
print subtracao_arbitraria('27', '1E', 16)
