for i in {1..10}; do
    echo "$i° Caso" >> tempos.txt
    for j in {1..3}; do
        #./a < "casoteste2/$i.in" >> bubble.txt
        ./c < "casoteste/$i.in" >> quick.txt
        echo "" >> tempos.txt
    done
done
