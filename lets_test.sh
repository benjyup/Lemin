bin=`which ./lem_in`
if [ "$bin" = "" ]
then
    echo "Need './lem_in' Banjam1 est un edp ! timot la marmotte"
    exit
fi

test_01()
{
    touch "tmp"
    echo "Test 01: Too many args"
    ./lem_in < ./test/trop_darg
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_02()
{
    touch "tmp"
    echo "Test 02: Name already used"
    ./lem_in < ./test/already_used
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_03()
{
    touch "tmp"
    echo "Test 03: Too many starts"
    ./lem_in < ./test/mul_start
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_04()
{
    touch "tmp"
    echo "Test 04: Too many ends"
    ./lem_in < ./test/mul_end
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_05()
{
    touch "tmp"
    echo "Test 05: There is no start"
    ./lem_in < ./test/no_start
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_06()
{
    touch "tmp"
    echo "Test 06: There is no end"
    ./lem_in < ./test/no_end
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_07()
{
    touch "tmp"
    echo "Test 07: There is no link"
    result=`./lem_in < ./test/no_link`
    result > tmp
    echo ''
    sleep 0.1
    #rm -rf tmp
}

test_08()
{
    touch "tmp"
    echo "Test 08: There is no road"
    ./lem_in < ./test/no_road_to_end
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_09()
{
    touch "tmp"
    echo "Test 09: src compatible?"
    ./lem_in < ./src
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_10()
{
    touch "tmp"
    echo "Test 10: Makefile compatible?"
    ./lem_in < ./Makefile
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_11()
{
    touch "tmp"
    echo "Test 11: exec compatible?"
    ./lem_in < ./lem_in
    echo ''
    sleep 0.1
    rm -rf tmp
}

test_12()
{
    touch "tmp"
    echo "Test 12: inc compatible?"
    ./lem_in < ./inc/lemin.h
    rm -rf tmp
}

#test_01
#test_02
#test_03
#test_04
#test_05
#test_06
test_07
#test_08
#test_09
#test_10
#test_11
#test_12
