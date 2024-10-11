gcc heap.c -o a 

for i in {1..10}; do
    echo "$i° Caso"
    ./a < "../casos_run/$i.in" > res.txt
    diff res.txt "../casos_run/$i.out" || break
done