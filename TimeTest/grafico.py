import matplotlib.pyplot as plt

pasta_juiz = 'Juiz/'
nome_pasta_resp = 'Aula03/'
n_arquivo = pasta_juiz + nome_pasta_resp + 'shellsort2.0'

def plotar_grafico(x, y):
    plt.plot(x, y)
    plt.show()


def plotar_grafico_barras():
    x = []
    y = []

    arquivo = open(f'{n_arquivo}.txt', 'r')
    for linha in arquivo:
        x.append(float(linha.split(' ')[0]))
        y.append(float(linha.split(' ')[1].replace('\n', '')) * 1000)

    arquivo.close()

    return x, y


if __name__ == '__main__':
    plotar_grafico(*plotar_grafico_barras())
