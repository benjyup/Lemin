bin=`which ./lem_in`
if [ "$bin" = "" ]
then
    echo "Need './lem_in' Banjam1 est un edp ! timot la marmotte"
    exit
fi

echo "Coucou les billy, c'est parti pour check le Lemin, chacun de ces tests rentrent une erreur, donc si ya pas de msg d'erreur, c'est KO"
echo ''
sleep 1
echo "Test 01: Too many args"
./lem_in < ./test/trop_darg
echo ''
sleep 0.1
echo "Test 02: Name already used"
./lem_in < ./test/already_used
echo ''
sleep 0.1
echo "Test 03: Too many starts"
./lem_in < ./test/mul_start
echo ''
sleep 0.1
echo "Test 04: Too many ends"
./lem_in < ./test/mul_end
echo ''
sleep 0.1
echo "Test 05: There is no start"
./lem_in < ./test/no_start
echo ''
sleep 0.1
echo "Test 06: There is no end"
./lem_in < ./test/no_end
echo ''
sleep 0.1
echo "Test 07: There is no link"
./lem_in < ./test/no_link
echo ''
sleep 0.1
echo "Test 08: There is no road"
./lem_in < ./test/no_road_to_end
echo ''
sleep 0.1
echo "Test 09: src compatible?"
./lem_in < ./src
echo ''
sleep 0.1
echo "Test 10: Makefile compatible?"
./lem_in < ./Makefile
echo ''
sleep 0.1
echo "Test 11: exec compatible?"
./lem_in < ./lem_in
echo ''
sleep 0.1
echo "Test 12: inc compatible?"
./lem_in < ./inc/lemin.h

