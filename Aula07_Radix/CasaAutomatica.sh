# Nome dos graficos:
Ga="radixGraph"
Gb="stoogeGraph"

Ta="radixSortT"
Tb="stoogeSortT"

dir="../TimeTest/Aula07"

# Nome dos executáveis dos sorts: a e b
Na="radix.c"
Nb="stooge.c"

# Nome dos executáveis dos testes de tempo: aT e bT
NaT="radixT.c"
NbT="stoogeT.c"

# Nome do executável para geração de casos de teste: c
Nc="gera_caso_teste.c"


read -p "Quantos casos de teste você deseja usar para comparação e teste de tempo? " num_testes

read -p "Deseja criar casos de teste? (s/n): " resposta
if [[ "$resposta" == "s" || "$resposta" == "S" ]]; then
    gcc $Nc -o c
    echo "Criando $num_testes casos de teste"
    ./c "$num_testes"
else
    echo "Pulando a criação de casos de teste"
fi


read -p "Deseja rodar comparações dos sorts? (s/n): " resposta_comparacao
if [[ "$resposta_comparacao" == "s" || "$resposta_comparacao" == "S" ]]; then
    echo "Comparação dos sorts"

    gcc $Na -o a
    gcc $Nb -o b

    for i in $(seq 1 "$num_testes"); do
        echo "$i° Caso"
        ./a < "casos_teste/$i.in" > resA
        ./b < "casos_teste/$i.in" > resB
        if ! diff resA resB; then
            echo "Diferença encontrada no caso $i. Parando o script."
            exit 1
        fi
    done
else
    echo "Pulando a comparação dos sorts"
fi


read -p "Deseja criar gráficos dos testes de tempo? (s/n): " resposta_graficos
if [[ "$resposta_graficos" == "s" || "$resposta_graficos" == "S" ]]; then
    read -p "Deseja criar gráficos para qual executável? (1/2/12): " exec_choice

    if [[ "$exec_choice" == "1" ]]; then
        echo "Teste de tempo do sort a"
        gcc $NaT -o aT

        ./aT < "casos_teste/1.in" > "$Ta.txt"
        for i in $(seq 2 "$num_testes"); do
            echo "$i° Caso"
            ./aT < "casos_teste/$i.in" >> "$Ta.txt"
        done
        python3 ../TimeTest/grafico.py $Ta $Ga $dir
    elif [[ "$exec_choice" == "2" ]]; then
        echo "Teste de tempo do sort b"
        gcc $NbT -o bT

        ./bT < "casos_teste/1.in" > "$Tb.txt"
        for i in $(seq 2 "$num_testes"); do
            echo "$i° Caso"
            ./bT < "casos_teste/$i.in" >> "$Tb.txt"
        done
        python3 ../TimeTest/grafico.py $Tb $Gb $dir
    elif [[ "$exec_choice" == "12" ]]; then
        echo "Teste de tempo dos sorts a e b"
        gcc $NaT -o aT
        gcc $NbT -o bT

        ./aT < "casos_teste/1.in" > "$Ta.txt"
        ./bT < "casos_teste/1.in" > "$Tb.txt"
        for i in $(seq 2 "$num_testes"); do
            echo "$i° Caso"
            ./aT < "casos_teste/$i.in" >> "$Ta.txt"
            ./bT < "casos_teste/$i.in" >> "$Tb.txt"
        done
        python3 ../TimeTest/grafico.py $Ta $Ga $dir
        python3 ../TimeTest/grafico.py $Tb $Gb $dir
    else
        echo "Opção inválida. Pulando a criação de gráficos."
    fi
else
    echo "Pulando a criação de gráficos"
fi
