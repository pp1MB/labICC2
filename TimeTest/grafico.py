import numpy as np
import matplotlib.pyplot as plt
import argparse


def getArguments():
    parser = argparse.ArgumentParser()

    #adicionamos o type = int abaixo
    parser.add_argument("caminhoTxt")
    parser.add_argument("nomeGrafico")
    parser.add_argument("diretorioGrafico")

    args = parser.parse_args()
    return args


args = getArguments()
n_arquivo = args.caminhoTxt

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
    plt.savefig(f'{args.diretorioGrafico}/{args.nomeGrafico}.png')
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
