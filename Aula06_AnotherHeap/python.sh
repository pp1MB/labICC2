gcc merge.c -o a

./a < "casos_teste/1.in" > mergeGraph.txt
for i in {2..499}; do
    echo "$i° Caso"
    ./a < "casos_teste/$i.in" >> mergeGraph.txt
done

python3 ../TimeTest/grafico.py mergeGraph mergeSort ../TimeTest/Aula6