EXEC=$1

for i in {2..5..1}; do
    echo "10^$i"
    for j in {1..6..1}; do
        $EXEC tarefa1 testes/performance/$i/$j.txt
    done
done
