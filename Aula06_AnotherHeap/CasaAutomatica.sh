gcc merge.c -o a
gcc heap.c -o b

gcc mergeT.c -o aT
gcc heapT.c -o bT

gcc cria_caso_teste.c -o c


read -p "Quantos casos de teste você deseja usar para comparação e teste de tempo? " num_testes

read -p "Deseja criar casos de teste? (s/n): " resposta
if [[ "$resposta" == "s" || "$resposta" == "S" ]]; then
    echo "Criando $num_testes casos de teste"
    ./c "$num_testes"
else
    echo "Pulando a criação de casos de teste"
fi


read -p "Deseja rodar comparações dos sorts? (s/n): " resposta_comparacao
if [[ "$resposta_comparacao" == "s" || "$resposta_comparacao" == "S" ]]; then
    echo "Comparação dos sorts"
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
    echo "Teste de tempo dos sorts"
    ./aT < "casos_teste/1.in" > mergeGraph.txt
    ./bT < "casos_teste/1.in" > heapGraph.txt
    for i in $(seq 2 "$num_testes"); do
        echo "$i° Caso"
        ./aT < "casos_teste/$i.in" >> mergeGraph.txt
        ./bT < "casos_teste/$i.in" >> heapGraph.txt
    done

    python3 ../TimeTest/grafico.py mergeGraph mergeSortT ../TimeTest/Aula6
    python3 ../TimeTest/grafico.py heapGraph heapSortT ../TimeTest/Aula6
else
    echo "Pulando a criação de gráficos"
fi
