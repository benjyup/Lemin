echo "Coucou les billy, c'est parti pour check le Lemin, chacun de ces tests rentrent une erreur, donc si ya pas de msg d'erreur, c'est KO"
echo ''
sleep 3
echo "Test 01: Too many args"
./lem_in < ./test/trop_darg | cat -e
echo ''
sleep 0.5
echo "Test 02: Name already used"
./lem_in < ./test/already_used | cat -e
echo ''
sleep 0.5
echo "Test 03: Too many starts"
./lem_in < ./test/mul_start | cat -e
echo ''
sleep 0.5
echo "Test 04: Too many ends"
./lem_in < ./test/mul_end | cat -e
echo ''
sleep 0.5
echo "Test 05: There is no start"
./lem_in < ./test/no_start | cat -e
echo ''
sleep 0.5
echo "Test 06: There is no end"
./lem_in < ./test/no_end | cat -e
echo ''
sleep 0.5
echo "Test 07: There is no link"
./lem_in < ./test/no_link | cat -e
