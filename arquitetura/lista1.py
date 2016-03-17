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


# Resolução de alguns exercícios
texto = 'Converta {} que está na base {}, para a base {}: {}'

ex1 = '1011010010011111'
boex1 = 2
bdex1 = 16
res_ex1 = representa(quantifica(ex1, 2), 16)
texto_ex1 = 'Ex1) ' + texto
print texto_ex1.format(ex1, boex1, bdex1, res_ex1)

ex2 = 'A7DF'
boex2 = 16
bdex2 = 2
res_ex2 = representa(quantifica(ex2, 16), 2)
texto_ex2 = 'Ex2) ' + texto
print texto_ex2.format(ex2, boex2, bdex2, res_ex2)

ex3a = '1100'
boex3a = 2
bdex3a = 10
res_ex3a = representa(quantifica(ex3a, boex3a), bdex3a)
texto_ex3a = 'Ex3a) ' + texto
print texto_ex3a.format(ex3a, boex3a, bdex3a, res_ex3a)

ex3b = '10.011'
boex3b = 2
bdex3b = 10
res_ex3b = representa(quantifica(ex3b, boex3b), bdex3b)
texto_ex3b = 'Ex3b) ' + texto
print texto_ex3b.format(ex3b, boex3b, bdex3b, res_ex3b)

ex3c = '0.001'
boex3c = 2
bdex3c = 10
res_ex3c = representa(quantifica(ex3c, boex3c), bdex3c)
texto_ex3c = 'Ex3c) ' + texto
print texto_ex3c.format(ex3c, boex3c, bdex3c, res_ex3c)

ex3d = '10001'
boex3d = 2
bdex3d = 10
res_ex3d = representa(quantifica(ex3d, boex3d), bdex3d)
texto_ex3d = 'Ex3d) ' + texto
print texto_ex3d.format(ex3d, boex3d, bdex3d, res_ex3d)

ex4a = '7'
boex4a = 10
bdex4a = 2
res_ex4a = representa(quantifica(ex4a, boex4a), bdex4a)
texto_ex4a = 'Ex4a) ' + texto
print texto_ex4a.format(ex4a, boex4a, bdex4a, res_ex4a)

ex4b = '23'
boex4b = 10
bdex4b = 2
res_ex4b = representa(quantifica(ex4b, boex4b), bdex4b)
texto_ex4b = 'Ex4b) ' + texto
print texto_ex4b.format(ex4b, boex4b, bdex4b, res_ex4b)

ex4c = '2.25'
boex4c = 10
bdex4c = 2
res_ex4c = representa(quantifica(ex4c, boex4c), bdex4c)
texto_ex4c = 'Ex4c) ' + texto
print texto_ex4c.format(ex4c, boex4c, bdex4c, res_ex4c)

ex5a = '70'
boex5a = 10
bdex5a = 2
res_ex5a = representa(quantifica(ex5a, boex5a), bdex5a)
texto_ex5a = 'Ex5a) ' + texto
print texto_ex5a.format(ex5a, boex5a, bdex5a, res_ex5a)

ex5b = '111111'
boex5b = 2
bdex5b = 10
res_ex5b = representa(quantifica(ex5b, boex5b), bdex5b)
texto_ex5b = 'Ex5b) ' + texto
print texto_ex5b.format(ex5b, boex5b, bdex5b, res_ex5b)

ex5c = '796'
boex5c = 10
bdex5c = 8
res_ex5c = representa(quantifica(ex5c, boex5c), bdex5c)
texto_ex5c = 'Ex5c) ' + texto
print texto_ex5c.format(ex5c, boex5c, bdex5c, res_ex5c)

#  A saída esperada para o código acima é:
# Ex1) Converta 1011010010011111 que está na base 2, para a base 16: B49F
# Ex2) Converta A7DF que está na base 16, para a base 2: 1010011111011111
# Ex3a) Converta 1100 que está na base 2, para a base 10: 12
# Ex3b) Converta 10.011 que está na base 2, para a base 10: 2.375
# Ex3c) Converta 0.001 que está na base 2, para a base 10: 0.125
# Ex3d) Converta 10001 que está na base 2, para a base 10: 17
# Ex4a) Converta 7 que está na base 10, para a base 2: 111
# Ex4b) Converta 23 que está na base 10, para a base 2: 10111
# Ex4c) Converta 2.25 que está na base 10, para a base 2: 10.01
# Ex5a) Converta 70 que está na base 10, para a base 2: 1000110
# Ex5b) Converta 111111 que está na base 2, para a base 10: 63
# Ex5c) Converta 796 que está na base 10, para a base 8: 1434
