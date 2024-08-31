import subprocess

# Nome do executável do programa em C
exec1 = './expi'
exec2 = './expr'

# Nome do arquivo onde a saída será salva
arquivo_saida = 'tempos.txt'

# Executa o programa e captura a saída
for j in range(1, 16):
    arquivo_in = f"casoteste/{j}.in"
    arquivo_out = f"casoteste/{j}.out"

    with open(arquivo_saida, 'a') as f:
            f.write(f'{j}° Caso:\n')
    with open(arquivo_in, 'r') as f:
            argumentos = f.read()
    for i in range(0, 3):
        res1 = subprocess.run([exec1], input=argumentos, capture_output=True, text=True, check=True)
        res2 = subprocess.run([exec2], input=argumentos, capture_output=True, text=True, check=True)
        linhas1 = res1.stdout.strip().split('\n')
        linhas2 = res2.stdout.strip().split('\n')

        with open(arquivo_out) as f:
            out = f.read().rstrip('\n')
            if linhas1[0].strip() != out or linhas2[0].strip() != out:
                print(f"Esperado: {repr(out)}")
                print(f"Recebido 1: {repr(linhas1[0])}")
                print(f"Recebido 2: {repr(linhas2[0])}")


        with open(arquivo_saida, 'a') as f:
            f.write(f"{linhas1[1]}\n")
            f.write(f"{linhas2[1]}\n")
            f.write('\n')