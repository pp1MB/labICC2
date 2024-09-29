for i in {1..10}; do
    echo "$i° Caso" >> tempos.txt
    for j in {1..3}; do
        ./bubble < "casoteste/$i.in" >> tempos.txt
        ./quick < "casoteste/$i.in" >> tempos.txt
        echo "" >> tempos.txt
    done
done
