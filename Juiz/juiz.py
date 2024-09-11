import subprocess

# Nome do executável do programa em C
exec1 = './expi'
exec2 = './expr'

# Nome do arquivo onde a saída será salva
arquivo_saida = 'tempos.txt'
arquivo_saida_grafico = 'grafico.txt'

caso_teste_txt = 'casoTesteMultiplicacao.txt'


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
    with open(arquivo_saida_grafico, 'w') as f:
        for j in range(1, n_casos_teste):
            arquivo_in = f"casoteste/{j}.in"

            with open(arquivo_in, 'r') as a:
                argumentos = a.read().split()
                f.write(f"{len(argumentos[1])}\n")

        for j in range(1, n_casos_teste):
            arquivo_in = f"casoteste/{j}.in"

            with open(arquivo_in, 'r') as a:
                argumentos = a.read()

            res1 = subprocess.run([exec1], input=argumentos, capture_output=True, text=True, check=True)
            res2 = subprocess.run([exec2], input=argumentos, capture_output=True, text=True, check=True)
            linhas1 = res1.stdout.strip().split('\n')
            linhas2 = res2.stdout.strip().split('\n')

            f.write(f"{linhas1[1]} ")
            f.write(f"{linhas2[1]}\n")


def arquivo_grafico_de_txt():
    with open(arquivo_saida_grafico, 'w') as f:
        arquivo = open(caso_teste_txt, 'r')

        for linha in arquivo:
            res1 = subprocess.run([exec1], input=linha, capture_output=True, text=True, check=True)
            res2 = subprocess.run([exec2], input=linha, capture_output=True, text=True, check=True)
            linhas1 = res1.stdout.strip().split('\n')
            linhas2 = res2.stdout.strip().split('\n')

            f.write(f"{linhas1[1]} ")
            f.write(f"{linhas2[1]}\n")



if __name__ == '__main__':
    # arquivo_bonito(16)
    arquivo_grafico(16)
    # arquivo_grafico_de_txt()
