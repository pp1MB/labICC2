for i in {0..200}; do
    #echo "$i° Caso" >> tempos.txt
    ./a < "casoteste2/$i.in" >> bubble.txt
    #./c < "casoteste2/$i.in" >> quick.txt
    echo "" >> tempos.txt
done
