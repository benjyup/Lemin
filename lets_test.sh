bin=`which ./lem_in`
if [ "$bin" = "" ]
then
    echo "Need './lem_in' FDPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
    exit
fi

echo "Coucou les billy, c'est parti pour check le Lemin, chacun de ces tests rentrent une erreur, donc si ya pas de msg d'erreur, c'est KO"
echo ''
sleep 1
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
echo ''
sleep 0.5
echo "Test 08: There is no road"
./lem_in < ./test/no_road_to_end | cat -e
echo ''
sleep 0.5
echo "Test 09: src compatible?"
./lem_in < ./src | cat -e
echo ''
sleep 0.5
echo "Test 10: Makefile compatible?"
./lem_in < ./Makefile | cat -e
echo ''
sleep 0.5
echo "Test 11: exec compatible?"
./lem_in < ./lem_in | cat -e
echo ''
sleep 0.5
echo "Test 12: inc compatible?"
./lem_in < ./inc/lemin.h | cat -e
