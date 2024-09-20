import matplotlib.pyplot as plt


n_arquivo = 'Juiz/grafico_aula3_2.1'

def plotar_grafico(x, y):
    x_values = range(len(x))
    plt.plot(x_values, y)
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
