import subprocess
from os import mkdir

# Nome do diretório onde o programa em C está
nome_relativo = 'Aula03_Selecao/'
pasta_juiz = 'TimeTest/'
nome_pasta_resp = 'Aula03/'

# Nome do executável do programa em C
exec1 = './' + nome_relativo + '/a'
# exec2 = './' + nome_relativo + 'expr'

# Nome do arquivo onde a saída será salva
arquivo_saida = pasta_juiz + nome_pasta_resp + 'tempos.txt'
arquivo_saida_grafico = pasta_juiz + nome_pasta_resp + 'grafico.txt'

caso_teste_txt = nome_relativo + 'casoTesteMultiplicacao.txt'

arquivo_casos_teste = nome_relativo + 'casos_teste_nr2.1'

def start():
    try:
        mkdir(pasta_juiz + nome_pasta_resp)
    except FileExistsError:
        pass


# Executa o programa e captura a saída
def arquivo_bonito(n_casos_teste):
    with open(arquivo_saida, 'w') as f:
        for j in range(1, n_casos_teste):
            arquivo_in = f"casoteste/{j}.in"
            arquivo_out = f"casoteste/{j}.out"

            f.write(f'{j}° Caso:\n')
            
            with open(arquivo_in, 'r') as a:
                argumentos = a.read()

            for i in range(0, 3):
                print(f'{j}° Caso:')
                res1 = subprocess.run([exec1], input=argumentos, capture_output=True, text=True, check=True)
                res2 = subprocess.run([exec2], input=argumentos, capture_output=True, text=True, check=True)
                linhas1 = res1.stdout.strip().split('\n')
                linhas2 = res2.stdout.strip().split('\n')

                with open(arquivo_out) as a:
                    out = a.read().rstrip('\n')
                    if linhas1[0].strip() != out or linhas2[0].strip() != out:
                        print(f"Esperado: {repr(out)}")
                        print(f"Recebido 1: {repr(linhas1[0])}")
                        print(f"Recebido 2: {repr(linhas2[0])}")

                f.write(f"Tempo de Execução Iterativo: {linhas1[1]}\n")
                f.write(f"Tempo de Execução Recursivo: {linhas2[1]}\n")
                f.write('\n')


def arquivo_grafico(n_casos_teste):
    tempos = []
    complexidades = []

    for j in range(1, n_casos_teste + 1):
        arquivo_in = f"{arquivo_casos_teste}/{j}.in"

        a = open(arquivo_in, 'r')
        argumentos = a.read()
        a.close()

        a = open(arquivo_in, 'r')
        complexidades.append(a.readline().strip())
        a.close()

        res1 = subprocess.run([exec1], input=argumentos, capture_output=True, text=True, check=True)
        # res2 = subprocess.run([exec2], input=argumentos, capture_output=True, text=True, check=True)
        linhas1 = res1.stdout.strip().split('\n')
        # linhas2 = res2.stdout.strip().split('\n')

        # tempos.append((linhas1[1], linhas2[1]))
        tempos.append(linhas1[0])

        print(f'{j}° Caso testado')

    with open(arquivo_saida_grafico, 'w') as f:
        for i in range(0, len(tempos)):
            f.write(f"{complexidades[i]} {tempos[i]} \n")
            # f.write(f"{tempos[i][1]}\n")



if __name__ == '__main__':
    start()

    # arquivo_bonito(16)
    arquivo_grafico(1)
    # arquivo_grafico_de_txt()
