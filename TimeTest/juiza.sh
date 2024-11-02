for i in {1..11}; do
    echo "$i° Caso" >> tempos.txt
    for j in {1..3}; do
        echo "Tempo de execução Busca Binária: " >> tempos.txt
        ./a < "casos_run/$i.in" >> tempos.txt
        echo "Tempo de execução Busca Linear" >> tempos.txt
        ./b < "casos_run/$i.in" >> tempos.txt
        echo "" >> tempos.txt
    done
done
