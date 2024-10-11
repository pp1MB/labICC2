for i in {1..10}; do
    echo "$i° Caso"
    ./merge < "../casos_run/$i.in" > tempos.txt
    ./heap < "../casos_run/$i.in" > tempos.txt
done