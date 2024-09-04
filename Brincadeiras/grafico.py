import matplotlib.pyplot as plt


def plotar_grafico(x, y):
    # Create the plot
    plt.figure(figsize=(10, 6))

    # Plot Program A times
    plt.plot(range(1, len(x) + 1), x, 'o-', label='Program A Time')

    # Plot Program B times
    #plt.plot(x_values, y, 's-', label='Program B Time')

    # Add labels and title
    plt.xlabel('Sample Index')
    plt.ylabel('Time (s)')
    plt.title('Comparison of Execution Times: Program A vs Program B')

    # Show legend
    plt.legend()
    plt.show()


def plotar_grafico_barras():
    x = []
    y = []

    arquivo = open('Brincadeiras/grafico.txt', 'r')
    for linha in arquivo:
        x.append(linha.split(' ')[0])
        y.append(linha.split(' ')[1].replace('\n', ''))

    arquivo.close()

    return x, y


if __name__ == '__main__':
    plotar_grafico(*plotar_grafico_barras())
