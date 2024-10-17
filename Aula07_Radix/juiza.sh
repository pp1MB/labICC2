for i in {1..7}; do
    echo "$i° Caso" >> tempos.txt
    for j in {1..3}; do
        ./radix < "casos_run/$i.in" >> tempos.txt
        ./stooge < "casos_run/$i.in" >> tempos.txt
        echo "" >> tempos.txt
    done
done
