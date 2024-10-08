import numpy as np

import matplotlib.pyplot as plt

pasta_juiz = 'TimeTest/'
nome_pasta_resp = 'Aula05/'
n_arquivo = pasta_juiz + nome_pasta_resp + 'bubble'

def plotar_grafico(x, y):
    scatter = plt.scatter(x, y, s=10, c=y, cmap='viridis')
    
    # Fit a polynomial of degree 2 (quadratic) to the data points
    z = np.polyfit(x, y, 2)
    p = np.poly1d(z)
    
    # Generate x values for plotting the fitted function
    x_fit = np.linspace(min(x), max(x), 500)
    y_fit = p(x_fit)
    
    plt.plot(x_fit, y_fit, color='r', linestyle='--', label='Fitted Function')
    
    plt.legend()
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
