for i in {1..10}; do
    echo "$i° Caso" >> tempos.txt
    for j in {1..3}; do
        ./merge < "casos_run/$i.in" >> tempos.txt
        ./heap < "casos_run/$i.in" >> tempos.txt
        echo "" >> tempos.txt
    done
done
