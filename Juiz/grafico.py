import matplotlib.pyplot as plt


def plotar_grafico(x, y):
# Create the x-axis values (index for each time entry)
    x_values = range(1, len(x) + 1)

    # First plot for Program A
    plt.figure(1)
    plt.bar(x_values, x, label='Program A Time')
    plt.xlabel('Problem Instance Index')
    plt.ylabel('Time (s)')
    plt.title('Execution Time: Program A')
    plt.legend()

    # Second plot for Program B
    plt.figure(2)
    plt.bar(x_values, y, label='Program B Time')
    plt.xlabel('Problem Instance Index')
    plt.ylabel('Time (s)')
    plt.title('Execution Time: Program B')
    plt.legend()

    # Display both plots
    plt.show()


def plotar_grafico_barras():
    x = []
    y = []

    arquivo = open('grafico.txt', 'r')
    for linha in arquivo:
        x.append(float(linha.split(' ')[0]))
        y.append(float(linha.split(' ')[1].replace('\n', '')))

    arquivo.close()

    return x, y


if __name__ == '__main__':
    plotar_grafico(*plotar_grafico_barras())
